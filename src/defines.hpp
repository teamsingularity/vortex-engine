#ifndef DEFINES_HPP
#define DEFINES_HPP

// API definition for dynamic library
#if defined(_WIN32)
    #if defined(VORTEX_BUILD)
        #define VORTEXAPI __declspec(dllexport)
    #else
        #define VORTEXAPI __declspec(dllimport)
    #endif
#else
    #define VORTEXAPI __attribute__((visibility("default")))
#endif

typedef unsigned int uint;

#endif //DEFINES_HPP