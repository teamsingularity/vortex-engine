#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <util/types.hpp>
#include <GL/glew.h>

class texture
{
public:
    texture(GLuint id);
    ~texture();

    static texture* load(image_t image);

    void bind(int index);

private:
    GLuint id;
};

#endif //TEXTURE_HPP