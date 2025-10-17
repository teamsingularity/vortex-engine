#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <engine/render/material.hpp>
#include <component/component.hpp>
#include <component/renderer.hpp>
#include <object/transform.hpp>
#include <vector>
#include <defines.hpp>

/**
 * @brief Core entity class that represents any object in the scene.
 *
 * GameObject acts as a container for Components such as Renderers, 
 * AudioSources, Colliders, etc. It defines a Transform for position, 
 * rotation and scale in the scene.
 */
class VORTEXAPI GameObject
{
public:
    /**
     * @brief Creates an empty GameObject with a default Transform.
     */
    GameObject();

    /**
     * @brief Destroys the GameObject and all attached Components.
     */
    ~GameObject();

    /**
     * @brief Spatial transform of the GameObject (position, rotation, scale).
     */
    Transform transform;

    /**
     * @brief Attaches a new Component to the GameObject.
     * @param component Pointer to the Component instance to attach.
     */
    void addComponent(Component* component);

    /**
     * @brief Assigns a Renderer Component to this GameObject.
     * @param renderer Pointer to the Renderer instance.
     */
    void setRenderer(Renderer* renderer);

    /**
     * @brief Called when the GameObject is initialized.
     */
    void start();

    /**
     * @brief Called once per frame to update attached Components.
     */
    void update();

    /**
     * @brief Renders the GameObject using its assigned Renderer and Material.
     */
    void render();

    /**
     * @brief Called after all updates in the frame are processed.
     */
    void lateUpdate();

    /**
     * @brief Destroys all attached Components and frees resources.
     */
    void destroy();

    /**
     * @brief Material used by the Renderer when drawing this GameObject.
     */
    Material* mat;

private:
    /**
     * @brief List of all attached Components.
     */
    std::vector<Component*> components;

    /**
     * @brief Pointer to the Renderer responsible for visual representation.
     */
    Renderer* renderer;
};

#endif //GAMEOBJECT_HPP
