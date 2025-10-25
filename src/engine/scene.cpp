#include "scene.hpp"
#include "object/gameobject.hpp"
#include <string>

Scene::Scene()
{
}

Scene::~Scene()
{
    for (auto& [name, object] : objects)
    {
        object->destroy();
    }
}

void Scene::addGameObject(std::string name, GameObject* object)
{
    objects[name] = object;
    object->start();
}

GameObject* Scene::getGameObject(std::string name)
{
    return objects[name];
}

void Scene::render()
{
    for (auto& [name, object] : objects)
        object->transform.update();

    for (auto& [name, object] : objects)
        object->update();

    for (auto& [name, object] : objects)
        object->render();

    for (auto& [name, object] : objects)
        object->lateUpdate();
}