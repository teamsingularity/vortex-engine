#ifndef ENGINE_HPP
#define ENGINE_HPP

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
     * @brief Terminates the engine, cleans up window and input systems.
     */
    static void terminate();

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
     * @brief Adds a game object to the engine's scene.
     * @param name Name to reference the object.
     * @param object Pointer to a GameObject.
     */
    static void addGameObject(std::string name, GameObject* object);

    /**
     * @brief Retrieves a game object by name.
     * @param name Name of the game object.
     * @return Pointer to the GameObject, or nullptr if not found.
     */
    static GameObject* getGameObject(std::string name);

    /**
     * @brief Updates all game objects in the scene.
     */
    static void update();

    /**
     * @brief Clears the screen (color and depth buffers).
     */
    static void clear();

    /**
     * @brief Pointer to the current main camera.
     */
    static Camera* camera;

    /**
     * @brief Time difference between frames.
     */
    static float deltaTime;

private:
    static std::unordered_map<std::string, Shader*> shaders;      /**< Collection of shaders by name. */
    static std::unordered_map<std::string, Texture*> textures;    /**< Collection of textures by name. */
    static std::unordered_map<std::string, Material*> materials;  /**< Collection of materials by name. */
    static std::unordered_map<std::string, GameObject*> scene;    /**< Collection of game objects by name. */
};

#endif //ENGINE_HPP
