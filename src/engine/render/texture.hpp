#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <util/types.hpp>
#include <GL/glew.h>
#include <defines.hpp>

/**
 * @file Texture.hpp
 * @brief Texture wrapper class for OpenGL textures.
 */

/**
 * @class Texture
 * @brief Encapsulates an OpenGL texture and provides utility methods.
 */
class VORTEXAPI Texture
{
public:
    /**
     * @brief Constructs a Texture object with an OpenGL texture ID.
     * @param id OpenGL texture ID.
     */
    Texture(GLuint id);

    /**
     * @brief Destructor, deletes the texture.
     */
    ~Texture();

    /**
     * @brief Loads a texture from RGBA image data.
     * @param image Image structure containing raw RGBA data and size.
     * @return Pointer to a new Texture object.
     */
    static Texture* load(image_t image);

    /**
     * @brief Creates a empty RGB texture.
     * @param width Texture width.
     * @param height Texture height.
     * @return Pointer to a new Texture object.
     */
    static Texture* create(int width, int height);

    /**
     * @brief Binds the texture to a binded framebuffer.
     */
    void bindToFramebuffer();

    /**
     * @brief Binds the texture to a given texture unit.
     * @param index Texture unit index (e.g., 0 for GL_TEXTURE0).
     */
    void bind(int index);

private:
    /**
     * @brief OpenGL texture ID.
     */
    GLuint id;
};

#endif // TEXTURE_HPP
