cmake_minimum_required(VERSION 4.0)
project(vortex-engine)

file(GLOB_RECURSE CPP_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HPP_FILES "${CMAKE_SOURCE_DIR}/src/*.hpp")

add_library(vortex-engine SHARED ${CPP_FILES} ${HPP_FILES})

find_library(ASSIMP_LIB assimp PATHS /usr/lib /usr/lib/x86_64-linux-gnu REQUIRED)

add_library(imgui
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

set_target_properties(imgui PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(imgui PUBLIC imgui imgui/backends)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_compile_definitions(vortex-engine PRIVATE GLEW_STATIC)

target_include_directories(vortex-engine PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    imgui
    imgui/backends
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
    imgui
)

target_compile_definitions(vortex-engine PRIVATE VORTEX_BUILD)