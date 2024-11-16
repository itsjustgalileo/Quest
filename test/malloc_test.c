#include <quest/quest.h>

int main(int argc, char **argv) {
    if (argc) {
        ((void)(argv));
    }
    if (quest_init() != QUEST_SUCCESS) {
        return 1;
    }

    int *ptr = quest_malloc(5 * sizeof(int));
    if (ptr == NULL) {
        return 2;
    }

    int i;
    for (i = 0; i < 5; ++i) {
        ptr[i] = i + 1;
        printf("%i\n", ptr[i]);
    }

    quest_free(ptr);
    quest_shutdown();
    return 0;
}
