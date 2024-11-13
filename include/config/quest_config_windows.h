#ifndef QUEST_CONFIG_WINDOWS_H_
#define QUEST_CONFIG_WINDOWS_H_
#define QUEST_CONFIG_H_

#include <quest/quest_platforms.h>

/* winsdkver.h defines _WIN32_MAXVER for SDK version detection. It is present since at least the Windows 7 SDK,
 * but out of caution we'll only use it if the compiler supports __has_include() to confirm its presence.
 * If your compiler doesn't support __has_include() but you have winsdkver.h, define HAVE_WINSDKVER_H.  */
#if !defined(HAVE_WINSDKVER_H) && defined(__has_include)
#if __has_include(<winsdkver.h>)
#define HAVE_WINSDKVER_H 1
#endif
#endif

#ifdef HAVE_WINSDKVER_H
#include <winsdkver.h>
#endif

/* sdkddkver.h defines more specific SDK version numbers. This is needed because older versions of the
 * Windows 10 SDK have broken declarations for the C API for DirectX 12. */
#if !defined(HAVE_SDKDDKVER_H) && defined(__has_include)
#if __has_include(<sdkddkver.h>)
#define HAVE_SDKDDKVER_H 1
#endif
#endif

#ifdef HAVE_SDKDDKVER_H
#include <sdkddkver.h>
#endif

#if !defined(HAVE_STDINT_H) && !defined(_STDINT_H_)
#if defined(_MSC_VER) && _MSC_VER < 1600
typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#ifndef _UINTPTR_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64 uintptr_t;
#else
typedef unsigned int uintptr_t;
#endif
#define _UINTPTR_T_DEFINED
#endif /* _UINTPTR_T_DEFINED */
#else
#define HAVE_STDINT_H 1
#endif /*  Visual Studio 2008 */
#endif /* HAVE_STDINT_H */

#ifdef __clang__
#define HAVE_GCC_ATOMICS 1
#endif /* __clang__ */

#ifndef HAVE_LIBC
#define HAVE_LIBC 1
#endif /* HAVE_LIBC */

#if HAVE_LIBC
/* Useful headers */
#define HAVE_FLOAT_H 1
#define HAVE_LIMITS_H 1
#define HAVE_MATH_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_STDARG_H 1
#define HAVE_STDBOOL_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_WCHAR_H 1

/* C library functions */
#define HAVE_MALLOC 1
#define HAVE_CALLOC 1
#define HAVE_REALLOC 1
#define HAVE_FREE 1
#define HAVE_ABS 1
#define HAVE_MEMSET 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE 1
#define HAVE_MEMCMP 1
#define HAVE_STRLEN 1
#define HAVE__STRREV 1
/* These functions have security warnings, so we won't use them */
/* #undef HAVE__STRUPR */
/* #undef HAVE__STRLWR */
#define HAVE_STRCHR 1
#define HAVE_STRRCHR 1
#define HAVE_STRSTR 1
/* #undef HAVE_STRTOK_R */
/* These functions have security warnings, so we won't use them */
/* #undef HAVE__LTOA */
/* #undef HAVE__ULTOA */
#define HAVE_STRTOL 1
#define HAVE_STRTOUL 1
#define HAVE_STRTOD 1
#define HAVE_ATOI 1
#define HAVE_ATOF 1
#define HAVE_STRCMP 1
#define HAVE_STRNCMP 1
#define HAVE_STRPBRK 1
#define HAVE__WCSDUP 1
#define HAVE_SSCANF 1
#define HAVE_VSSCANF 1
#define HAVE_VSNPRINTF 1
#define HAVE_ACOS   1
#define HAVE_ASIN   1
#define HAVE_ATAN   1
#define HAVE_ATAN2  1
#define HAVE_CEIL   1
#define HAVE_COS    1
#define HAVE_EXP    1
#define HAVE_FABS   1
#define HAVE_FLOOR  1
#define HAVE_FMOD   1
#define HAVE_ISINF  1
#define HAVE_ISINF_FLOAT_MACRO 1
#define HAVE_ISNAN  1
#define HAVE_ISNAN_FLOAT_MACRO 1
#define HAVE_LOG    1
#define HAVE_LOG10  1
#define HAVE_POW    1
#define HAVE_SIN    1
#define HAVE_SQRT   1
#define HAVE_TAN    1
#define HAVE_ACOSF  1
#define HAVE_ASINF  1
#define HAVE_ATANF  1
#define HAVE_ATAN2F 1
#define HAVE_CEILF  1
#define HAVE__COPYSIGN 1
#define HAVE_COSF   1
#define HAVE_EXPF   1
#define HAVE_FABSF  1
#define HAVE_FLOORF 1
#define HAVE_FMODF  1
#define HAVE_LOGF   1
#define HAVE_LOG10F 1
#define HAVE_POWF   1
#define HAVE_SINF   1
#define HAVE_SQRTF  1
#define HAVE_TANF   1
#ifdef _MSC_VER
/* These functions were added with the VC++ 2013 C runtime library */
#if _MSC_VER >= 1800
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#define HAVE_VSSCANF 1
#define HAVE_LROUND 1
#define HAVE_LROUNDF 1
#define HAVE_ROUND 1
#define HAVE_ROUNDF 1
#define HAVE_SCALBN 1
#define HAVE_SCALBNF 1
#define HAVE_TRUNC  1
#define HAVE_TRUNCF 1
#endif
/* This function is available with at least the VC++ 2008 C runtime library */
#if _MSC_VER >= 1400
#define HAVE__FSEEKI64 1
#endif
#endif    /* _MSC_VER */
#else
#define HAVE_STDARG_H   1
#define HAVE_STDDEF_H   1
#endif

/* Enable various shared object loading systems */
#define QUEST_LOADSO_WINDOWS  1

/* Enable various threading systems */
#define QUEST_THREAD_GENERIC_COND_SUFFIX 1
#define QUEST_THREAD_GENERIC_RWLOCK_SUFFIX 1
#define QUEST_THREAD_WINDOWS  1

/* Enable RTC system */
#define QUEST_TIME_WINDOWS   1

/* Enable various timer systems */
#define QUEST_TIMER_WINDOWS   1

/* Enable various process implementations */
#define QUEST_PROCESS_WINDOWS 1

/* Enable filesystem support */
#define SDL_FILESYSTEM_WINDOWS  1
#define SDL_FSOPS_WINDOWS 1

#endif /* QUEST_CONFIG_WINDOWS_H_ */
