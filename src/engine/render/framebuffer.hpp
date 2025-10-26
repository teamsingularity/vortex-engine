#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <defines.hpp>
#include <engine/render/texture.hpp>
#include <GL/glew.h>

class VORTEXAPI Framebuffer
{
public:
    Framebuffer(GLuint id);
    ~Framebuffer();

    static Framebuffer* create(Texture* texture);

    void bind();

private:
    GLuint id;
};

#endif //FRAMEBUFFER_HPP