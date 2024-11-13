#ifndef QUEST_STDINC_H_
#define QUEST_STDINC_H_

#include <quest/quest_platforms.h>

#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#ifdef __cplusplus
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L || \
    defined(_MSC_VER) && _MSC_VER >= 1910 || \
    defined(QUEST_INCLUDE_STDBOOL_H)
#include <stdbool.h>
#elif !defined(__bool_true_and_false_are_defined) && !defined(bool)
#define bool unsigned char
#define true 1
#define false 0
#endif /*  Bool */
#endif /* __cplusplus */

#ifndef QUEST_DISABLE_ALLOCA
#ifndef alloca
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#elif defined(__GNUC__)
#define alloca __builtin_alloca
#elif defined(_MSC_VER)
#include <malloc.h>
#define alloca _alloca
#else
void *alloca(size_t);
#endif
#endif
#endif

#ifdef SIZE_MAX
# define QUEST_SIZE_MAX SIZE_MAX
#else
# define QUEST_SIZE_MAX ((size_t) -1)
#endif

#ifndef QUEST_COMPILE_TIME_ASSERT
#if defined(__cplusplus)
/* Keep C++ case alone: Some versions of gcc will define __STDC_VERSION__ even when compiling in C++ mode. */
#if (__cplusplus >= 201103L)
#define QUEST_COMPILE_TIME_ASSERT(name, x)  static_assert(x, #x)
#endif
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 202311L)
#define QUEST_COMPILE_TIME_ASSERT(name, x)  static_assert(x, #x)
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define QUEST_COMPILE_TIME_ASSERT(name, x) _Static_assert(x, #x)
#endif
#endif /* !QUEST_COMPILE_TIME_ASSERT */

#ifndef QUEST_COMPILE_TIME_ASSERT
/* universal, but may trigger -Wunused-local-typedefs */
#define QUEST_COMPILE_TIME_ASSERT(name, x)               \
       typedef int quest_compile_time_assert_ ## name[(x) * 2 - 1]
#endif

#define QUEST_ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define QUEST_STRINGIFY(arg) #arg

#ifdef __cplusplus
#define quest_static_cast(type, value) static_cast<type>(value)
#define quest_reinterpret_cast(type, value) reinterpret_cast<type>(value)
#define quest_const_cast(type, value) const_cast<type>(value)
#else
#define quest_static_cast(type, value) ((type)(value))
#define quest_reinterpret_cast(type, value) ((type)(value))
#define quest_const_cast(type, value) ((type)(value))
#endif /* __cplusplus */

typedef uint8_t uint8;
#define QUEST_UINT8_MIN ((uint8)0x00)
#define QUEST_UINT8_MAX ((uint8)0xFF)

typedef int8_t int8;
#define QUEST_INT8_MIN ((int8)~(0x7F))
#define QUEST_INT8_MAX ((int8)0x7F)

typedef uint16_t uint16;
#define QUEST_UINT16_MIN ((uint16)0x0000)
#define QUEST_UINT16_MAX ((uint16)0xFFFF)

typedef int16_t int16;
#define QUEST_INT16_MIN ((int16)~(0x7FFF))
#define QUEST_INT16_MAX ((int16)0x7FFF)

typedef uint32_t uint32;
#define QUEST_UINT32_MIN ((uint32)0x00000000)
#define QUEST_UINT32_MAX ((uint32)0xFFFFFFFF)

typedef int32_t int32;
#define QUEST_INT32_MIN ((int32)~(0x7FFFFFFF))
#define QUEST_INT32_MAX ((int32)0x7FFFFFFF)

typedef uint64_t uint64;
#define QUEST_UINT64_MIN ((uint64)0x0000000000000000)
#define QUEST_UINT64_MAX ((uint64)0xFFFFFFFFFFFFFFFF)

typedef int64_t int64;
#define QUEST_INT64_MIN ((int64)~(0x7FFFFFFFFFFFFFFF))
#define QUEST_INT64_MAX ((int64)0x7FFFFFFFFFFFFFFF)

#include <quest/quest_header.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    /* Memory functions */
#ifndef QUEST_DISABLE_ALLOCA
#define quest_stack_alloc(type, count)    (type*)alloca(sizeof(type)*(count))
#define quest_stack_free(data)
#else
#define quest_stack_alloc(type, count)    (type*)quest_malloc(sizeof(type)*(count))
#define quest_stack_free(data)            quest_free(data)
#endif
    
    extern QUEST_API void *QUEST_DECL quest_malloc(size_t size);
    extern QUEST_API void *QUEST_DECL quest_calloc(size_t num, size_t size);
    extern QUEST_API void *QUEST_DECL quest_realloc(void *mem, size_t size);
    extern QUEST_API void QUEST_DECL quest_free(void *mem);

    extern QUEST_API void *QUEST_DECL quest_aligned_alloc(size_t align, size_t size);
    extern QUEST_API void QUEST_DECL quest_free(void *mem);

    /* String functions */

    /* Print functions */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
    
    /* Math functions */

#ifndef QUEST_PI_D
#define QUEST_PI_D 3.14159265358979311599796346854
#endif /* QUEST_PI_D */    

#ifndef QUEST_PI_F
#define QUEST_PI_F 3.14159265358979311599796346854f
#endif /* QUEST_PI_F */
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <quest/quest_footer.h>

#endif /* QUEST_STDINC_H_ */
