#include <quest/quest.h>

int main(int argc, char **argv) {
    if (quest_init() != QUEST_SUCCESS) {
        return 1;
    }

    quest_window *window = quest_create_window("quest test", 800, 600, 100, 100, 0);
    if (window == NULL) {
        return 1;
    }

    system("pause");
    
    quest_destroy_window(window);
    quest_shutdown();
    return 0;
}
