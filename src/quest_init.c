#include "./quest_internal.h"

#include "./quest_init_c.h"

#include "./stdlib/quest_malloc_c.h"

int quest_init(void) {
    if (!quest_init_memory_manager()) {
        QUEST_TODO("error tracking");
        return 1;
    }
    
    return QUEST_SUCCESS;
}

void quest_shutdown(void) {
    quest_shutdown_memory_manager();
}
