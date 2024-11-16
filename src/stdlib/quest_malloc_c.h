#include "../quest_internal.h"

#ifndef QUEST_STDLIB_C_H_
#define QUEST_STDLIB_C_H_

typedef struct quest_memory_manager {
    int num_allocs;
    size_t alloc_size;
    void *(QUEST_DECL *malloc_func)(size_t);
    void *(QUEST_DECL *calloc_func)(size_t, size_t);
    void *(QUEST_DECL *realloc_func)(void *, size_t);
    void (QUEST_DECL *free_func)(void *);
} quest_memory_manager;

quest_memory_manager *quest_get_memory_manager(void);

bool quest_init_memory_manager(void);
void quest_shutdown_memory_manager(void);

#endif /* QUEST_STDLIB_C_H_ */
