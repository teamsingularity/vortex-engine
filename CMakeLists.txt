cmake_minimum_required(VERSION 4.0)
project(vortex-engine)

file(GLOB_RECURSE CPP_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HPP_FILES "${CMAKE_SOURCE_DIR}/src/*.hpp")

add_library(vortex-engine SHARED ${CPP_FILES} ${HPP_FILES})

find_library(ASSIMP_LIB assimp PATHS /usr/lib /usr/lib/x86_64-linux-gnu REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_compile_definitions(vortex-engine PRIVATE GLEW_STATIC)

target_include_directories(vortex-engine PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(vortex-engine PRIVATE
    glfw
    GLEW
    GL
    spng
    ${ASSIMP_LIB}
    openal
    ogg
    vorbis
    vorbisfile
)

target_compile_definitions(vortex-engine PRIVATE VORTEX_BUILD)