#include "shader.hpp"
#include <iostream>

shader::shader(GLuint id) : id(id) {}

shader::~shader() {
    glDeleteProgram(id);
}

shader* shader::loadShader(const char* vertexCode, const char* fragmentCode)
{
    /* Compile shaders */
    GLint success;
    GLchar infoLog[512];

    /* Compile vertex shader */
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexCode, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "Failed to link shader program: " << infoLog << std::endl;
        return nullptr;
    }

    /* Compile fragment shader */
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "Failed to link shader program: " << infoLog << std::endl;
        return nullptr;
    }

    /* Link shaders into a program */
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "Failed to link shader program: " << infoLog << std::endl;
        return nullptr;
    }

    // delete compiled shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return new shader(shaderProgram);
}

void shader::use() {
    glUseProgram(id);
}
