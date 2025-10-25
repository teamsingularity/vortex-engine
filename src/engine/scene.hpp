#ifndef SCENE_HPP
#define SCENE_HPP

#include <component/core/camera.hpp>
#include <object/gameobject.hpp>
#include <string>
#include <unordered_map>

/**
 * @class Scene
 * @brief Manages game objects and incapsulates method to render scene.
 */
class Scene
{
public:
    /**
     * @brief Creates new scene.
     */
    Scene();

    /**
     * @brief Destroys scene and all game objects.
     */
    ~Scene();

    /**
     * @brief Adds a game object to the scene.
     * @param name Name of the object.
     * @param object Pointer to a GameObject.
     */
    void addGameObject(std::string name, GameObject* object);

    /**
     * @brief Retrieves a game object by name.
     * @param name Name of the game object.
     * @return Pointer to the GameObject, or nullptr if not found.
     */
    GameObject* getGameObject(std::string name);

    /**
     * @brief Pointer to the current main camera.
     */
    Camera* camera;

    /**
     * @brief Updates and renders all game objects
     */
    void render();

private:
    std::unordered_map<std::string, GameObject*> objects;  /**< Scene objects table. */
};

#endif //SCENE_HPP