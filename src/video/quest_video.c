#include "../quest_internal.h"

#include "./quest_video_c.h"

quest_window *quest_create_window(const char *title, size_t width, size_t height, int x, int y, int flags) {
    quest_window *window = (quest_window *)quest_malloc(sizeof(quest_window));
    if (window == NULL) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    QUEST_TODO("copy title to window title safely via strdup");
    window->title = "Quest";
    window->width = width;
    window->height = height;
    window->x = x;
    window->y = y;
    window->flags = flags;

    if (!quest_window_init_internal(window)) {
        QUEST_TODO("error tracking");
        return NULL;        
    }
    
    if (!window->create_window(window)) {
        QUEST_TODO("error tracking");
        return NULL;
    }
    
    return window;
}

void quest_destroy_window(quest_window *window) {
    if (window) {
        window->destroy_window(window);
        quest_free(window);
    }
}
