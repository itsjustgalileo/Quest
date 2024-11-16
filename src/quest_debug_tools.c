#include "./quest_internal.h"

#include <quest/quest_debug_tools.h>

void quest_todo_impl(const char *file, int line, const char *fn, const char *fmt) {
    fprintf(stdout, "%s:%i (in function %s): [ TODO ] - ", file, line, fn);
    fprintf(stdout, "%s", fmt);
    fprintf(stdout, "\n");
}

void quest_log_impl(questLogLevel logLevel, const char *file, int line, const char *fn, const char *fmt, ...) {
    if (fmt == NULL) {
        return;
    }
    (void)file;
    (void)line;
    (void)fn;
    
    va_list ap;
    va_start(ap, fmt);
    switch (logLevel) {
    case QUEST_LOGLEVEL_TRACE:
        fprintf(stderr, "[ TRACE ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_DEBUG:
        fprintf(stderr, "[ DEBUG ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_INFO:
        fprintf(stderr, "[ INFO ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_WARN:
        fprintf(stderr, "[ WARNING ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_ERROR:
        fprintf(stderr, "[ ERROR ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_FATAL:
        fprintf(stderr, "[ FATAL ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    }
    va_end(ap);
}

void quest_throw_exception_impl(const char *file, int line, const char *fn, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "%s:%i (in function %s): [ exception thrown ] - ", file, line, fn);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);

    QUEST_BREAKPOINT;
}
