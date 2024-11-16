#include "../../quest_internal.h"

#include "../quest_video_c.h"

#include "../../core/windows/quest_windows.h"

struct quest_window_data {
    LPSTR class_name;
    HINSTANCE hInstance;
    HWND hWnd;
    HDC hDC;
};

static bool win32_create_window(quest_window *window) {
    if (window == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }

    window->internal->class_name = "QUEST APP";
    window->internal->hInstance = GetModuleHandle(0);

    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hInstance = window->internal->hInstance;
    wc.lpszClassName = window->internal->class_name;
    wc.lpfnWndProc = DefWindowProc;

    if (!RegisterClassEx(&wc)) {
        QUEST_TODO("error tracking");
        return false;
    }

    window->internal->hWnd = CreateWindowEx(0, window->internal->class_name, window->title, WS_OVERLAPPEDWINDOW, window->x, window->y, window->width, window->height, 0, NULL, window->internal->hInstance, NULL);
    if (window->internal->hWnd == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }

    ShowWindow(window->internal->hWnd, SW_SHOW);
    UpdateWindow(window->internal->hWnd);
    return true;
}

static bool win32_destroy_window(quest_window *window) {
    if (window == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }

    DestroyWindow(window->internal->hWnd);
    UnregisterClass(window->internal->class_name, window->internal->hInstance);

    free(window->internal);
    return true;
}

bool quest_window_init_internal(quest_window *window) {
    if (window == NULL) {
        return false;
    }
    
    window->internal = (quest_window_data *)quest_malloc(sizeof(quest_window_data));
    if (window->internal == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }

    window->create_window = win32_create_window;
    window->destroy_window = win32_destroy_window;
    if (window->create_window == NULL || window->destroy_window == NULL) {
        QUEST_TODO("error tracking");
        return false;
    }
    
    return true;
}
