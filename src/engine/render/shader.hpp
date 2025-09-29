#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <GL/glew.h>

class shader {
public:

    shader(GLuint id);
    ~shader();
    
    /*
    I used const char* instead of std::string bc OpenGL requires shader code to be a char pointer
    */
   static shader* loadShader(const char* vertexCode, const char* fragmentCode);
   
   void use();

private:
    GLuint id;
};

#endif
