#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include <defines.hpp>

class VORTEXAPI Shader {
public:
    Shader(GLuint id);
    ~Shader();
    
    /*
    I used const char* instead of std::string bc OpenGL requires shader code to be a char pointer
    */
   static Shader* load(const char* vertexCode, const char* fragmentCode);
   
   void use();
   void uniformMatrix4fv(std::string name, glm::mat4 matrix);

private:
   GLuint id;
};

#endif
