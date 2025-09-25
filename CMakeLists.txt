cmake_minimum_required(VERSION 4.0)
project(vortex-engine)

add_executable(vortex-engine
    src/main.cpp
    src/Window.hpp
    src/Window.cpp
)

target_compile_definitions(vortex-engine PRIVATE GLEW_STATIC)

target_include_directories(vortex-engine PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(vortex-engine PRIVATE
    glfw
    GLEW
    GL
)