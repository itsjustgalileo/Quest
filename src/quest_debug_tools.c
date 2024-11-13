#include "./quest_internal.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <quest/quest_debug_tools.h>

void quest_log_impl(questLogLevel logLevel, const char *file, int line, const char *fn, const char *fmt, ...) {
    if (fmt == NULL) {
        return;
    }
    va_list ap;
    va_start(ap, fmt);
    switch (logLevel) {
    case QUEST_LOGLEVEL_TRACE:
        fprintf(stderr, "%s:%i (in function %s): [ TRACE ] - ", file, line, fn);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_DEBUG:
        fprintf(stderr, "%s:%i (in function %s): [ DEBUG ] - ", file, line, fn);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_INFO:
        fprintf(stderr, "%s:%i (in function %s): [ INFO ] - ", file, line, fn);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_WARN:
        fprintf(stderr, "%s:%i (in function %s): [ WARNING ] - ", file, line, fn);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_ERROR:
        fprintf(stderr, "%s:%i (in function %s): [ ERROR ] - ", file, line, fn);
        fprintf(stderr, "[ ERROR ] - ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_FATAL:
        fprintf(stderr, "%s:%i (in function %s): [ FATAL ] - ", file, line, fn);
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        break;
    case QUEST_LOGLEVEL_TODO:
        fprintf(stderr, "%s:%i (in function %s): [ TODO ] - ", file, line, fn);
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

#if defined(_DEBUG) || defined(DEBUG) || defined(QUEST_DEBUG)
    QUEST_BREAKPOINT;
#else
    exit(1); // Exit program normally in release mode
#endif
}
