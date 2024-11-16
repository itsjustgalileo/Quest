#ifndef QUEST_VIDEO_H_
#define QUEST_VIDEO_H_

#include <quest/quest_stdinc.h>

#include <quest/quest_header.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef struct quest_window quest_window;

    extern QUEST_API quest_window *QUEST_DECL quest_create_window(const char *title, size_t width, size_t height, int x, int y, int flags);
    extern QUEST_API void QUEST_DECL quest_destroy_window(quest_window *window);

    extern QUEST_API const char *QUEST_DECL quest_get_window_title(quest_window *window);
    
    extern QUEST_API bool QUEST_DECL quest_get_window_size(quest_window *window, size_t *w, size_t *h);
    extern QUEST_API bool QUEST_DECL quest_get_window_pos(quest_window *window, int *x, int *y);

    extern QUEST_API bool QUEST_DECL quest_set_window_title(quest_window *window, const char *title);
    
    extern QUEST_API bool QUEST_DECL quest_set_window_size(quest_window *window, const size_t w, const size_t h);
    extern QUEST_API bool QUEST_DECL quest_set_window_pos(quest_window *window, const int x, const int y);
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <quest/quest_footer.h>

#endif /* QUEST_VIDEO_H_ */
