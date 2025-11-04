#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "engine/render/framebuffer.hpp"
#include "engine/render/mesh.hpp"
#include "engine/scene.hpp"
#include <defines.hpp>
#include <unordered_map>
#include <engine/render/material.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture.hpp>
#include <object/gameobject.hpp>
#include <component/core/camera.hpp>
#include <string>

/**
 * @class Engine
 * @brief Core engine class that manages shaders, textures, materials, game objects, and the main camera.
 */
class VORTEXAPI Engine
{
public:
    /**
     * @brief Initializes the engine, creates window and input systems.
     * @param title Window title.
     * @param width Window width.
     * @param height Window height.
     * @return True if initialization succeeded, false otherwise.
     */
    static bool init(std::string title, int width, int height);

    /**
     * @brief destroys the engine, cleans up window and input systems.
     */
    static void destroy();

    /**
     * @brief Adds a shader to the engine's collection.
     * @param name Name to reference the shader.
     * @param shader Pointer to a Shader object.
     */
    static void addShader(std::string name, Shader* shader);

    /**
     * @brief Retrieves a shader by name.
     * @param name Name of the shader.
     * @return Pointer to the Shader object, or nullptr if not found.
     */
    static Shader* getShader(std::string name);

    /**
     * @brief Adds a texture to the engine's collection.
     * @param name Name to reference the texture.
     * @param texture Pointer to a Texture object.
     */
    static void addTexture(std::string name, Texture* texture);

    /**
     * @brief Retrieves a texture by name.
     * @param name Name of the texture.
     * @return Pointer to the Texture object, or nullptr if not found.
     */
    static Texture* getTexture(std::string name);

    /**
     * @brief Adds a material to the engine's collection.
     * @param name Name to reference the material.
     * @param material Pointer to a Material object.
     */
    static void addMaterial(std::string name, Material* material);

    /**
     * @brief Retrieves a material by name.
     * @param name Name of the material.
     * @return Pointer to the Material object, or nullptr if not found.
     */
    static Material* getMaterial(std::string name);

    /**
     * @brief Creates a new framebuffer with window size and returns pointer to it.
     */
    static Framebuffer* createFramebuffer();

    /**
     * @brief Render one frame, updating all objects.
     * @param framebuffer Framebuffer in which scene should be rendered, do not specify to render directly to screen.
     */
    static void render(Framebuffer* framebuffer = nullptr);

    static void renderQuad(Shader* shader);

    /**
     * @brief Clears the screen (color and depth buffers).
     */
    static void clear();

    /**
     * @brief Pointer to the current main camera.
     */
    static Scene* scene;

    /**
     * @brief Time difference between frames.
     */
    static float deltaTime;

private:
    static std::unordered_map<std::string, Shader*> shaders;      /**< Collection of shaders by name. */
    static std::unordered_map<std::string, Texture*> textures;    /**< Collection of textures by name. */
    static std::unordered_map<std::string, Material*> materials;  /**< Collection of materials by name. */

    static Mesh* quad; /**< Simple 2D fullscreen quad mesh, used for framebuffer rendering and UI. */
};

#endif //ENGINE_HPP
