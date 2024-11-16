#include "../quest_internal.h"

#include "./quest_malloc_c.h"

void *quest_malloc(size_t size) {
    quest_memory_manager *mm = quest_get_memory_manager();
    QUEST_ASSERT(mm != NULL);
    return mm->malloc_func(size);
}

void *quest_calloc(size_t num, size_t size) {
    quest_memory_manager *mm = quest_get_memory_manager();
    QUEST_ASSERT(mm != NULL);
    return mm->calloc_func(num, size);    
}

void *quest_realloc(void *mem, size_t size) {
    quest_memory_manager *mm = quest_get_memory_manager();
    QUEST_ASSERT(mm != NULL);
    return mm->realloc_func(mem, size);    
}

void quest_free(void *mem) {
    quest_memory_manager *mm = quest_get_memory_manager();
    QUEST_ASSERT(mm != NULL);
    return mm->free_func(mem);        
}
