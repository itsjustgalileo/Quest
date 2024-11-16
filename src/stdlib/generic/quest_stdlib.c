#include "../../quest_internal.h"

#include "../quest_malloc_c.h"

static quest_memory_manager _this;

static void *generic_malloc(size_t size) {
    void *mem = malloc(size);
    if (mem == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += size;
    ++_this.num_allocs;
    return mem;
}

static void *generic_calloc(size_t num, size_t size) {
    void *mem = calloc(num, size);
    if (mem == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += num * size;
    ++_this.num_allocs;
    return mem;
}

static void *generic_realloc(void *mem, size_t size) {
    void *nmem = realloc(mem, size);
    if (nmem == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    _this.alloc_size += size;
    return nmem;
}

static void generic_free(void *mem) {
    free(mem);
    --_this.num_allocs;
    QUEST_TODO("track alloc size to remove it upon free");
}

quest_memory_manager *quest_get_memory_manager(void) {
    return &_this;
}

bool quest_init_memory_manager(void) {
    _this.alloc_size = 0;
    _this.num_allocs = 0;
    _this.malloc_func = generic_malloc;
    _this.calloc_func = generic_calloc;
    _this.realloc_func = generic_realloc;
    _this.free_func = generic_free;
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
