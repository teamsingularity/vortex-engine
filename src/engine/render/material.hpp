#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <engine/render/shader.hpp>
#include <engine/render/texture.hpp>
#include <defines.hpp>

/**
 * @file Material.hpp
 * @brief Material class for assigning shaders and textures to meshes.
 */

/**
 * @class Material
 * @brief Represents a material used for rendering meshes.
 *
 * Material stores a shader and a base texture, which can be applied
 * to a mesh to define its visual appearance.
 */
class VORTEXAPI Material
{
public:
    /**
     * @brief Constructs a material with a shader and a texture.
     * @param Shader Pointer to the shader to use.
     * @param texture Pointer to the texture to use.
     */
    Material(Shader* Shader, Texture* texture);

    /**
     * @brief Destructor for Material.
     */
    ~Material();

    /**
     * @brief Shader assigned to the material.
     */
    Shader* matShader;

    /**
     * @brief Base texture assigned to the material.
     */
    Texture* baseTexture;
};

#endif // MATERIAL_HPP
