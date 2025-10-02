#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <defines.hpp>

class VORTEXAPI GameObject;

class VORTEXAPI Component
{
public:
    virtual ~Component() = default;

    GameObject* object;

    /*
    start() is called once when object appears on scene.
    */
    virtual void start() = 0;

    /*
    update() is called on each frame before rendering.
    */
    virtual void update() = 0;

    /*
    lateUpdate() is called on each frame after rendering.
    */
    virtual void lateUpdate() = 0;

    /*
    destroy() is called once when object is being destroyed.
    */
    virtual void destroy() = 0;
};

#endif //COMPONENT_HPP