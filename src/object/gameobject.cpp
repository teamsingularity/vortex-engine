#include "gameobject.hpp"
#include "component/component.hpp"
#include "object/transform.hpp"

GameObject::GameObject() : transform(), renderer(nullptr), mat(nullptr)
{
}

GameObject::~GameObject()
{
}

void GameObject::start()
{
    for (auto component : components)
        if (component) component->start();

    if (renderer) renderer->start();
}

void GameObject::update()
{
    for (auto component : components)
        if (component) component->update();
}

void GameObject::render()
{   
    if (renderer) renderer->render();
}

void GameObject::lateUpdate()
{
    for (auto component : components)
        if (component) component->lateUpdate();
}

void GameObject::destroy()
{
    for (auto component : components)
        if (component) component->destroy();
    if (renderer) renderer->destroy();
}

void GameObject::addComponent(Component* component)
{
    components.push_back(component);
    component->object = this;
}

void GameObject::setRenderer(Renderer* _renderer)
{
    renderer = _renderer;
    renderer->object = this;
}