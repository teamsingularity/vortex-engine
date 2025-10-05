#ifndef SHADERS_HPP
#define SHADERS_HPP

static const char* litVertex = R"(
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoord;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main() {
    gl_Position = projection * view * transform * vec4(position, 1.0);
    texCoord = uv;
}
)";

static const char* litFragment = R"(
#version 330 core

out vec4 color;
in vec2 texCoord;

uniform sampler2D _texture;

void main() {
    color = texture(_texture, texCoord);
}
)";

#endif