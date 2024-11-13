#ifndef QUEST_PLATFORMS_H_
#define QUEST_PLATFORMS_H_

#if defined(__linux__) || defined(__linux) || defined(linux)
#define QUEST_PLATFORM_LINUX 1
#endif /* defined(__linux__) || defined(__linux) || defined(linux) */

#if defined(__unix__) || defined(__unix) || defined(unix)
#define QUEST_PLATFORM_UNIX 1
#endif /* defined(__unix__) || defined(__unix) || defined(unix) */

#if defined(ANDROID) || defined(__ANDROID__)
#define QUEST_PLATFORM_ANDROID 1
#undef QUEST_PLATFORM_LINUX
#endif /* defined(ANDROID) || defined(__ANDROID__) */

#ifdef __EMSCRIPTEN__
#define QUEST_PLATFORM_EMSCRIPTEN 1
#endif /* __EMSCRIPTEN__ */

#if defined(__MINGW32__) || defined(__MINGW64__)
#define QUEST_PLATFORM_MINGW32 1
#endif /* defined(__MINGW32__) || defined(__MINGW64__) */

#if defined(_WIN32) || defined(QUEST_PLATFORM_MINGW32)
#define QUEST_PLATFORM_WINDOWS 1
#endif /* defined(_WIN32) || defined(QUEST_PLATFORM_MINGW32) */

#endif /* QUEST_PLATFORMS_H_ */
