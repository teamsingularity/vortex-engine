#include "framebuffer.hpp"
#include "engine/render/texture.hpp"
#include <iostream>

Framebuffer::Framebuffer(GLuint id, GLuint depth, Texture* texture) : id(id), depth(depth), texture(texture)
{
}

Framebuffer::~Framebuffer()
{
    glDeleteFramebuffers(1, &id);
    glDeleteRenderbuffers(1, &depth);
}

Framebuffer* Framebuffer::create(Texture *texture, int width, int height)
{
    GLuint fbo;
    glGenFramebuffers(1, &fbo);

    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    texture->bindToFramebuffer();

    GLuint depth;
    glGenRenderbuffers(1, &depth);
    glBindRenderbuffer(GL_RENDERBUFFER, depth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depth);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        std::cout << "Failed to create framebuffer: framebuffer incomplete!" << std::endl;
        return nullptr;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return new Framebuffer(fbo, depth, texture);
}

void Framebuffer::bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, id);
}

void Framebuffer::unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}