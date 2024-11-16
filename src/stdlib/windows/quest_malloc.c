#include "../../quest_internal.h"

#include "../quest_malloc_c.h"

#include "../../core/windows/quest_windows.h"

static quest_memory_manager _this;

static void *win32_malloc(size_t size) {
    HANDLE hHandle = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
    if (hHandle == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += size;
    ++_this.num_allocs;
    return hHandle;
}

static void *win32_calloc(size_t num, size_t size) {
    HANDLE hHandle = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, num * size);
    if (hHandle == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += (num * size);
    ++_this.num_allocs;
    return hHandle;    
}

static void *win32_realloc(void *mem, size_t size) {
    HANDLE hHandle = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, mem, size);
    if (hHandle == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += size;
    return hHandle;        
}

static void win32_free(void *mem) {
    HeapFree(GetProcessHeap(), 0, mem);
    --_this.num_allocs;
    QUEST_TODO("track alloc size to remove it upon free");
}

quest_memory_manager *quest_get_memory_manager(void) {
    return &_this;
}

bool quest_init_memory_manager(void) {
    _this.alloc_size = 0;
    _this.num_allocs = 0;
    _this.malloc_func = win32_malloc;
    _this.calloc_func = win32_calloc;
    _this.realloc_func = win32_realloc;
    _this.free_func = win32_free;
    if (_this.malloc_func == NULL || _this.calloc_func == NULL || _this.realloc_func == NULL || _this.free_func == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }
    return true;
}

void quest_shutdown_memory_manager(void) {
    _this.alloc_size = 0;
    _this.num_allocs = 0;
    _this.malloc_func = NULL;
    _this.calloc_func = NULL;
    _this.realloc_func = NULL;
    _this.free_func = NULL;
}
