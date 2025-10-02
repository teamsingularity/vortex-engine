#include "material.hpp"
#include "engine/render/texture.hpp"

Material::Material(Shader* _shader, Texture* _texture) : matShader(_shader), baseTexture(_texture) {}

Material::~Material() {}