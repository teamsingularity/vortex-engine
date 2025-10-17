#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>
#include <defines.hpp>

/**
 * Shader container that contains program ID and incapsulates methods to use it.
 */
class VORTEXAPI Shader {
public:
    /**
     * Normally, shouldn't be used directly, creates shader container instance and sets it's ID.
     * @param id Shader program ID that will be set to created shader container ID.
     */
    Shader(GLuint id);
    /**
     * Deletes shader program.
     */
    ~Shader();
    
    /**
     * Compiles and links OpenGL fragment and vertex shaders.
     * @param vertexCode C-style string pointer that points to GLSL vertex shader code.
     * @param fragmentCode C-style string pointer that points to GLSL fragment shader code.
     * @return Pointer to shader container.
     */
    static Shader* load(const char* vertexCode, const char* fragmentCode);
    
    /**
     * Uses shader program.
     */
    void use();
    
    /**
     * Sends 4x4 float matrix uniform to shader.
     * @param name Uniform name, must be same as in shader.
     * @param matrix GLM matrix that will be sent to shader.
     */
    void uniformMatrix4fv(std::string name, glm::mat4 matrix);

private:
    /**
     * Shader program ID.
     */
    GLuint id;
};

#endif
