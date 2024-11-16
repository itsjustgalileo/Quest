#ifdef QUEST_HEADER_H_
#error "This file was included twice"
#endif /* QUEST_HEADER_H_ */
#define QUEST_HEADER_H_

#ifndef QUEST_DECL
#if defined(QUEST_PLATFORM_WINDOWS) && !defined(__GNUC__)
#define QUEST_DECL __cdecl
#else
#define QUEST_DECL
#endif
#endif /* !QUEST_DECL */

#ifndef QUEST_BREAKPOINT
#if defined(DEBUG) || defined(_DEBUG) || defined(QUEST_DEBUG)
#if defined(QUEST_PLATFORM_WINDOWS) && !defined(__GNUC__)
#define QUEST_BREAKPOINT __debugbreak()
#elif defined(__GNUC__) && !defined(__clang__)
/* HIGHLY RISKY */
extern int raise(int);
#define QUEST_BREAKPOINT raise(5)
#elif defined(__clang__)
#define QUEST_BREAKPOINT __builtin_debugtrap()
#else
#error "Define breakpoint for platform"
#define QUEST_BREAKPOINT *(volatile int *)0 = 0
#endif /*  defined(QUEST_PLATFORM_WINDOWS) && !defined(__GNUC__) */
#else
#define QUEST_BREAKPOINT exit(1)
#endif /*  defined(DEBUG) || defined(_DEBUG) || defined(QUEST_DEBUG) */
#endif /* QUEST_BREAKPOINT */

#ifndef QUEST_API
#ifdef QUEST_BUILD_DLL
#ifdef _WIN32
#define QUEST_API __declspec(dllexport)
#elif (defined(__GNUC__) && __GNUC__ >= 4) || defined(__clang__)
#define QUEST_API __attribute__((visibility("default")))
#endif /* _WIN32 */
#elif defined(QUEST_USE_DLL)
#ifdef _WIN32
#define QUEST_API __declspec(dllimport)
#elif defined(__GNUC__) || defined(__clang__)
#define QUEST_API
#endif /* _WIN32 */
#else
#define QUEST_API
#endif /* QUEST_BUILD_DLL */
#endif /* QUEST_API */

#ifndef __MACH__
#ifndef NULL
#ifdef __cplusplus
#define NULL (0)
#else
#define NULL ((void *)0)
#endif /* __cplusplus */
#endif /* NULL */
#endif /* __MACH__ */

#if defined(_MSC_VER)
#ifdef _MSC_VER
#pragma warning(disable: 4103)
#endif
#ifdef __clang__
#pragma clang diagnostic ignored "-Wpragma-pack"
#endif
#ifdef _WIN64
/* Use 8-byte alignment on 64-bit architectures, so pointers are aligned */
#pragma pack(push,8)
#else
#pragma pack(push,4)
#endif
#endif /* Compiler needs structure packing set */

#ifndef QUEST_INLINE
#ifdef __GNUC__
#define QUEST_INLINE __inline__
#elif defined(_MSC_VER)
#define QUEST_INLINE __inline
#ifndef __inline__
#define __inline__ __inline
#endif
#else
#define QUEST_INLINE inline
#ifndef __inline__
#define __inline__ inline
#endif
#endif
#endif /* QUEST_INLINE not defined */

#ifndef QUEST_FORCE_INLINE
#ifdef _MSC_VER
#define QUEST_FORCE_INLINE __forceinline
#elif ( (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__clang__) )
#define QUEST_FORCE_INLINE __attribute__((always_inline)) static __inline__
#else
#define QUEST_FORCE_INLINE static QUEST_INLINE
#endif
#endif /* QUEST_FORCE_INLINE not defined */
