#ifndef DEFINES_HPP
#define DEFINES_HPP

/**
 * @file defines.hpp
 * @brief Contains global type definitions and macros for library visibility.
 *
 * This file defines export/import macros used for building dynamic libraries 
 * across different platforms, as well as general type aliases.
 */

/**
 * @def VORTEXAPI
 * @brief Controls symbol visibility for shared library builds.
 *
 * On Windows, this macro expands to `__declspec(dllexport)` when building 
 * the library, or `__declspec(dllimport)` when using it.
 * On Linux and macOS, it expands to `__attribute__((visibility("default")))`.
 *
 * Example:
 * @code
 * class VORTEXAPI Renderer {};
 * @endcode
 */
#if defined(_WIN32)
    #if defined(VORTEX_BUILD)
        #define VORTEXAPI __declspec(dllexport)
    #else
        #define VORTEXAPI __declspec(dllimport)
    #endif
#else
    #define VORTEXAPI __attribute__((visibility("default")))
#endif

/**
 * @typedef uint
 * @brief Unsigned integer alias for convenience.
 */
typedef unsigned int uint;

#endif // DEFINES_HPP
