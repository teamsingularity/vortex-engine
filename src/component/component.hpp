#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <defines.hpp>

class VORTEXAPI GameObject;

/**
 * @brief Base class for all components that can be attached to a GameObject.
 * 
 * Components define behavior and functionality for GameObjects in the scene.
 */
class VORTEXAPI Component
{
public:
    /**
     * @brief Virtual destructor for proper cleanup in derived classes.
     */
    virtual ~Component() = default;

    /**
     * @brief Pointer to the GameObject this component is attached to.
     */
    GameObject* object;

    /**
     * @brief Called once when the GameObject appears on the scene.
     * 
     * Should be used for initialization logic.
     */
    virtual void start() = 0;

    /**
     * @brief Called on every frame before rendering.
     * 
     * Main update logic for the component should go here.
     */
    virtual void update() = 0;

    /**
     * @brief Called on every frame after rendering.
     * 
     * Use for post-update logic that should run after all rendering.
     */
    virtual void lateUpdate() = 0;

    /**
     * @brief Called once when the GameObject is being destroyed.
     */
    virtual void destroy() = 0;
};

#endif //COMPONENT_HPP
