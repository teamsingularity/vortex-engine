#include "shader.hpp"
#include "engine/render/texture.hpp"
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <logger/logger.hpp>

Shader::Shader(GLuint id) : id(id) {}

Shader::~Shader() {
    glDeleteProgram(id);
}

Shader* Shader::load(const char* vertexCode, const char* fragmentCode)
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
        Logger::critical("Failed to compile vertex shader: " + std::string(infoLog));
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
        Logger::critical("Failed to compile fragment shader: " + std::string(infoLog));
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
        Logger::critical("Failed to link shader program: " + std::string(infoLog));
        return nullptr;
    }

    // delete compiled shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return new Shader(shaderProgram);
}

void Shader::use() {
    glUseProgram(id);
}

void Shader::uniformMatrix4fv(std::string name, glm::mat4 matrix)
{
    GLuint loc = glGetUniformLocation(id, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::uniformFloat(const std::string& name, float val)
{
    GLint loc = glGetUniformLocation(id, name.c_str());
    glUniform1f(loc, val);
}

void Shader::uniformInt(const std::string& name, int val)
{
    GLint loc = glGetUniformLocation(id, name.c_str());
    glUniform1i(loc, val);
}

void Shader::uniformVec3(const std::string& name, const glm::vec3& vec)
{
    GLint loc = glGetUniformLocation(id, name.c_str());
    glUniform3fv(loc, 1 , glm::value_ptr(vec));
}

