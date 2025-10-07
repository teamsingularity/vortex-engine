cmake_minimum_required(VERSION 4.0)
project(vortex-engine)


add_library(vortex-engine SHARED
# src/main.cpp
src/engine/window.cpp
src/engine/window.hpp
src/engine/input.cpp
src/engine/input.hpp
src/engine/render/shader.cpp
src/engine/render/shader.hpp
src/engine/render/texture.cpp
src/engine/render/texture.hpp
src/engine/render/mesh.cpp
src/engine/render/mesh.hpp
src/engine/render/material.cpp
src/engine/render/material.hpp
src/engine/engine.hpp
src/engine/engine.cpp
src/component/component.hpp
src/component/renderer.hpp
src/component/renderers/meshrenderer.cpp
src/component/renderers/meshrenderer.hpp
src/component/core/camera.cpp
src/component/core/camera.hpp
src/object/gameobject.cpp
src/object/gameobject.hpp
src/object/transform.cpp
src/object/transform.hpp
src/loader/png.cpp
src/loader/png.hpp
src/util/types.hpp
src/shaders.hpp
src/loader/model.hpp
src/loader/model.cpp
)

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

)

target_compile_definitions(vortex-engine PRIVATE VORTEX_BUILD)

add_custom_command(TARGET vortex-engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_SOURCE_DIR}/res"
        "${CMAKE_BINARY_DIR}/res"
)