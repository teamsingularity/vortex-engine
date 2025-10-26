#include "framebuffer.hpp"
#include <iostream>

Framebuffer::Framebuffer(GLuint id) : id(id)
{
}

Framebuffer::~Framebuffer()
{
    glDeleteFramebuffers(1, &id);
}

Framebuffer* Framebuffer::create(Texture *texture)
{
    GLuint fbo;
    glGenFramebuffers(1, &fbo);

    glBindFramebuffer(GL_FRAMEBUFFER, fbo);


    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        std::cout << "Failed to create framebuffer: framebuffer incomplete!" << std::endl;
        return nullptr;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);   

    return new Framebuffer(fbo);
}