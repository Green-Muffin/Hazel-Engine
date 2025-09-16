#ifndef CORE_H
#define CORE_H

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#elif defined HZ_PLATFORM_MACOS 
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __attribute__((visibility("default")))
    #else
        #define HAZEL_API __attribute__((visibility("default")))
    #endif
#else
    #error Hazel only supports Windows and MacOS!
#endif



#endif // CORE_H