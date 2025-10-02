#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <defines.hpp>

class VORTEXAPI GameObject;

class VORTEXAPI Renderer
{
public:
    virtual ~Renderer() = default;

    GameObject* object;

    /*
    start() is called once when object appears on scene.
    */
    virtual void start() = 0;

    /*
    render() is called on each frame after all updates but before late updates.
    */
    virtual void render() = 0;

    /*
    destroy() is called once when object is being destroyed.
    */
    virtual void destroy() = 0;
};

#endif //RENDERER_HPP