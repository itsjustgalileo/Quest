#ifndef QUEST_DEBUG_TOOLS_H_
#define QUEST_DEBUG_TOOLS_H_

#include <quest/quest_stdinc.h>

#include <quest/quest_header.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef enum questLogLevel {
        QUEST_LOGLEVEL_TRACE,
        QUEST_LOGLEVEL_DEBUG,
        QUEST_LOGLEVEL_INFO,
        QUEST_LOGLEVEL_WARN,
        QUEST_LOGLEVEL_ERROR,
        QUEST_LOGLEVEL_FATAL,
    } questLogLevel;

    extern QUEST_API void QUEST_DECL quest_log_impl(questLogLevel logLevel, const char *file, int line, const char *fn, const char *fmt, ...);
    extern QUEST_API void QUEST_DECL quest_todo_impl(const char *file, int line, const char *fn, const char *fmt);
    extern QUEST_API void QUEST_DECL quest_throw_exception_impl(const char *file, int line, const char *fn, const char *fmt, ...);

#define QUEST_LOG(level, msg, ...) quest_log_impl(level, __FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)
#define QUEST_TODO(msg) quest_todo_impl(__FILE__, __LINE__, __FUNCTION__, msg)
#define QUEST_EXCEPTION(msg, ...) quest_throw_exception_impl(__FILE__, __LINE__, __FUNCTION__, msg, ##__VA_ARGS__)    
#define QUEST_ASSERT(expr) if ((expr)) {} else { QUEST_LOG(QUEST_LOGLEVEL_FATAL, "Assertion failed: %s", QUEST_STRINGIFY(expr)); QUEST_BREAKPOINT; }
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <quest/quest_footer.h>

#endif /* QUEST_DEBUG_TOOLS_H_ */
