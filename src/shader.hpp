#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <GL/glew.h>

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexSource, const char* fragmentSource);

    
    void use();


    ~Shader() {
        glDeleteProgram(ID);
    }

private:
    
    GLuint compileShader(GLenum type, const char* source);
};

#endif
