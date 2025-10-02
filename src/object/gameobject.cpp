#include "gameobject.hpp"
#include "component/component.hpp"
#include "object/transform.hpp"

GameObject::GameObject() : transform()
{
}

GameObject::~GameObject()
{
}

void GameObject::start()
{
    for (auto component : components)
        component->start();
    renderer->start();
}

void GameObject::update()
{
    for (auto component : components)
        component->update();
}

void GameObject::render()
{
    renderer->render();
}

void GameObject::lateUpdate()
{
    for (auto component : components)
        component->lateUpdate();
}

void GameObject::destroy()
{
    for (auto component : components)
        component->destroy();
    renderer->destroy();
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