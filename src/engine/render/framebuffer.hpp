#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <defines.hpp>
#include <engine/render/texture.hpp>
#include <GL/glew.h>

/**
 * @brief Framebuffer container.
 */
class VORTEXAPI Framebuffer
{
public:
    /**
     * @brief Constructs a new framebuffer container using ID of FBO and depth renderbuffer.
     * @param id FBO ID
     * @param depth depth renderbuffer ID
     */
    Framebuffer(GLuint id, GLuint depth, Texture* texture);

    /**
     * @brief Deletes framebuffer and attached depth renderbuffer.
     */
    ~Framebuffer();

    /**
     * @brief Creates a new framebuffer and attachs a texture to it.
     * @param texture Texture container pointer that will be attached as color buffer.
     * @param width Framebuffer width.
     * @param height Framebuffer height.
     * @return Pointer to a new Framebuffer object or nullptr if creation failed.
     */
    static Framebuffer* create(Texture* texture, int width, int height);

    /**
     * @brief Binds framebuffer.
     */
    void bind();

    /**
     * @brief Unbinds framebuffer.
     */
    void unbind();

    /**
     * @brief Attached texture container.
     */
    Texture* texture;

private:
    /**
     * @brief ID of a FBO object.
     */
    GLuint id;

    /**
     * @brief ID of a depth renderbuffer.
     */
    GLuint depth;
};

#endif //FRAMEBUFFER_HPP