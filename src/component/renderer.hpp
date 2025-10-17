#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <defines.hpp>

class VORTEXAPI GameObject;

/**
 * @brief Base class for all renderers that can be attached to a GameObject.
 * 
 * Renderers handle drawing of GameObjects each frame.
 */
class VORTEXAPI Renderer
{
public:
    /**
     * @brief Virtual destructor for proper cleanup in derived classes.
     */
    virtual ~Renderer() = default;

    /**
     * @brief Pointer to the GameObject this renderer is attached to.
     */
    GameObject* object;

    /**
     * @brief Called once when the GameObject appears on the scene.
     * 
     * Initialization logic for the renderer should go here.
     */
    virtual void start() = 0;

    /**
     * @brief Called on every frame after all updates but before late updates.
     * 
     * Use this method to render the GameObject.
     */
    virtual void render() = 0;

    /**
     * @brief Called once when the GameObject is being destroyed.
     * 
     * Cleanup logic for the renderer should go here.
     */
    virtual void destroy() = 0;
};

#endif //RENDERER_HPP
