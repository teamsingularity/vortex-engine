#include "texture.hpp"
#include <string.h>
#include <stdlib.h>

// simple method to flip RGBA8888 image
void flip_vertical(unsigned char* data, int width, int height)
{
    int row_size = width * 4; // 4 bytes per pixel (RGBA8)
    unsigned char* row_buffer = (unsigned char*)malloc(row_size);

    for (int y = 0; y < height / 2; ++y)
    {
        unsigned char* row_top = data + y * row_size;
        unsigned char* row_bottom = data + (height - 1 - y) * row_size;

        memcpy(row_buffer, row_top, row_size);
        memcpy(row_top, row_bottom, row_size);
        memcpy(row_bottom, row_buffer, row_size);
    }

    free(row_buffer);
}

Texture::Texture(GLuint id) : id(id) {}

Texture::~Texture()
{
    glDeleteTextures(1, &id);
}

Texture* Texture::load(image_t image)
{
    GLuint _texture;

    glGenTextures(1, &_texture);
    
    glBindTexture(GL_TEXTURE_2D, _texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    flip_vertical(image.data, image.width, image.height);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);

    return new Texture(_texture);
}

Texture* Texture::create(int width, int height)
{
    GLuint _texture;

    glGenTextures(1, &_texture);
    
    glBindTexture(GL_TEXTURE_2D, _texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    
    glBindTexture(GL_TEXTURE_2D, 0);

    return new Texture(_texture);
}

void Texture::bindToFramebuffer()
{
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, id, 0);
}

void Texture::bind(int index)
{
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, id);
}