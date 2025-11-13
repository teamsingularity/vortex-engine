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

out vec2 TexCoord;
out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(model))) * normal;
    TexCoord = uv;

    gl_Position = projection * view * vec4(FragPos, 1.0);
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

out vec4 FragColor;

in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D _texture;
uniform vec3 viewPos;


#define MAX_LIGHTS 4

struct Light {
    int type; //(0 - directional, 1 - point, 2 - spot)
    vec3 position;
    vec3 direction;
    vec3 color;


    float constant;
    float linear;
    float quadratic;


    float cutOff;
    float outerCutOff;
};

uniform Light lights[MAX_LIGHTS];
uniform int numLights;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 texColor = texture(_texture, TexCoord).rgb;

    vec3 result = vec3(0.0);

    for (int i = 0; i < numLights; i++) {
        Light light = lights[i];
        vec3 lightDir;
        float attenuation = 1.0;


        if (light.type == 0) {
            lightDir = normalize(-light.direction);
        }

        else if (light.type == 1) {
            lightDir = normalize(light.position - FragPos);
            float distance = length(light.position - FragPos);
            attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
        }

        else if (light.type == 2) {
            lightDir = normalize(light.position - FragPos);
            float distance = length(light.position - FragPos);
            attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

            float theta = dot(lightDir, normalize(-light.direction));
            float epsilon = light.cutOff - light.outerCutOff;
            float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
            attenuation *= intensity;
        }


        vec3 ambient = 0.1 * light.color;


        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * light.color;


        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = 0.5 * spec * light.color;


        result += (ambient + diffuse + specular) * attenuation;
    }

    FragColor = vec4(result * texColor, 1.0);
}

)";

/**
 * @brief Vertex shader for unlit objects.
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
 * @brief Fragment shader for unlit objects.
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

/**
 * @brief Vertex shader for screen quad.
 *
 * Inputs:
 * - `position` Vertex position.
 * - `uv` Texture coordinate.
 *
 * Outputs:
 * - `texCoord` : Texture coordinate for fragment shader.
 */
static const char* quadVertex = R"(
#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoord;

void main() {
    gl_Position = vec4(position.x, position.y, 0.0, 1.0);
    texCoord = uv;
}
)";

/**
 * @brief Fragment shader for screen quad.
 *
 * Inputs:
 * - `texCoord` : Interpolated texture coordinates from vertex shader.
 *
 * Uniforms:
 * - `_texture` : Texture sampler.
 *
 * Outputs:
 * - `color` : Final fragment color.
 */
static const char* quadFragment = R"(
#version 330 core

out vec4 color;
in vec2 texCoord;

uniform sampler2D _texture;

void main() {
    color = texture(_texture, texCoord);
}
)";

#endif // SHADERS_HPP
