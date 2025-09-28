#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <GL/glew.h>

class shader {
public:
    GLuint id;

    shader(GLuint id);
    
    void use();

    /*
    I used const char* instead of std::string bc OpenGL requires shader code to be a char pointer
    */
    static shader* loadShader(const char* vertexCode, const char* fragmentCode);

    ~shader();
};

#endif
