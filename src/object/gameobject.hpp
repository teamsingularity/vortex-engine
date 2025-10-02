#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <engine/render/material.hpp>
#include <component/component.hpp>
#include <component/renderer.hpp>
#include <object/transform.hpp>
#include <vector>
#include <defines.hpp>

class VORTEXAPI GameObject
{
public:
    GameObject();
    ~GameObject();

    Transform transform;

    void addComponent(Component* component);
    void setRenderer(Renderer* renderer);

    void start();
    void update();
    void render();
    void lateUpdate();
    void destroy();

    Material* mat;

private:
    std::vector<Component*> components;

    Renderer* renderer;
};

#endif //GAMEOBJECT_HPP