#include "../quest_internal.h"

#ifndef QUEST_VIDEO_C_H_
#define QUEST_VIDEO_C_H_

typedef struct quest_window_data quest_window_data;

struct quest_window {
    char *title;
    size_t width, height;
    int x, y;
    int flags;
    struct quest_window_data *internal;

    /* platform function pointers */
    bool (*QUEST_DECL create_window)(quest_window *_this);
    bool (*QUEST_DECL destroy_window)(quest_window *_this);
};

bool quest_window_init_internal(quest_window *window);

#endif /* QUEST_VIDEO_C_H_ */
