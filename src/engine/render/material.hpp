#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <engine/render/shader.hpp>
#include <engine/render/texture.hpp>
#include <defines.hpp>

class VORTEXAPI Material
{
public:
    Material(Shader* Shader, Texture* texture);
    ~Material();

    Shader* matShader;
    Texture* baseTexture;
};

#endif //MATERIAL_HPP