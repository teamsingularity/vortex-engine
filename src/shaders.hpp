#pragma once
#ifndef SHADERS_HPP
#define SHADERS_HPP

/**
 * @file shaders.hpp
 * @brief Contains GLSL shader code as string literals for the engine.
 *
 * This file stores vertex and fragment shaders as C++ string literals.
 * They can be passed directly to OpenGL shader compilation functions.
 */

/**
 * @brief Vertex shader for lit objects.
 *
 * Attributes:
 * - `position`  : Vertex position.
 * - `normal`    : Vertex normal.
 * - `uv`        : Texture coordinates.
 *
 * Outputs:
 * - `texCoord`  : Passed to fragment shader.
 * - `fragNormal`: Passed to fragment shader.
 *
 * Uniforms:
 * - `transform` : Model transformation matrix.
 * - `projection`: Projection matrix.
 * - `view`      : View matrix.
 */
static const char* litVertex = R"(
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec2 texCoord;
out vec3 fragNormal;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main() {
    gl_Position = projection * view * transform * vec4(position, 1.0);
    texCoord = uv;
    fragNormal = normal;
}
)";

/**
 * @brief Fragment shader for lit objects.
 *
 * Inputs:
 * - `texCoord` : Interpolated texture coordinates from vertex shader.
 * - `fragNormal`: Interpolated normal from vertex shader.
 *
 * Uniforms:
 * - `_texture` : Texture sampler.
 *
 * Outputs:
 * - `color` : Final fragment color.
 */
static const char* litFragment = R"(
#version 330 core

out vec4 color;
in vec2 texCoord;
in vec3 fragNormal;

uniform sampler2D _texture;

void main() {
    color = texture(_texture, texCoord);
}
)";


static const char* unlitVertex = R"(
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec2 texCoord;
out vec3 fragNormal;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main() {
    gl_Position = projection * view * transform * vec4(position, 1.0);
    texCoord = uv;
    fragNormal = normal;
}
)";

/**
 * @brief Fragment shader for lit objects.
 *
 * Inputs:
 * - `texCoord` : Interpolated texture coordinates from vertex shader.
 * - `fragNormal`: Interpolated normal from vertex shader.
 *
 * Uniforms:
 * - `_texture` : Texture sampler.
 *
 * Outputs:
 * - `color` : Final fragment color.
 */
static const char* unlitFragment = R"(
#version 330 core

out vec4 color;
in vec2 texCoord;
in vec3 fragNormal;

uniform sampler2D _texture;

void main() {
    color = texture(_texture, texCoord);
}
)";

#endif // SHADERS_HPP
