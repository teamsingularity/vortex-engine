#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <util/types.hpp>
#include <GL/glew.h>
#include <defines.hpp>

class VORTEXAPI Texture
{
public:
    Texture(GLuint id);
    ~Texture();

    static Texture* load(image_t image);

    void bind(int index);

private:
    GLuint id;
};

#endif //TEXTURE_HPP