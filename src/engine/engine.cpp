#include "engine.hpp"
#include <engine/window.hpp>
#include <engine/input.hpp>

std::unordered_map<std::string, Shader*> Engine::shaders;
std::unordered_map<std::string, Texture*> Engine::textures;
std::unordered_map<std::string, Material*> Engine::materials;
std::unordered_map<std::string, GameObject*> Engine::scene;
float Engine::deltaTime;

bool Engine::init(std::string title, int width, int height)
{
    if (!Window::init(width, height, title)) return false;
    if (!Input::init()) return false;
    return true;
}

void Engine::terminate()
{
    Window::terminate();
    Input::terminate();
}

void Engine::addShader(std::string name, Shader* shader)
{
    shaders[name] = shader;
}

Shader* Engine::getShader(std::string name)
{
    return shaders[name];
}

void Engine::addTexture(std::string name, Texture* texture)
{
    textures[name] = texture;
}

Texture* Engine::getTexture(std::string name)
{
    return textures[name];
}

void Engine::addMaterial(std::string name, Material* material)
{
    materials[name] = material;
}

Material* Engine::getMaterial(std::string name)
{
    return materials[name];
}

void Engine::addGameObject(std::string name, GameObject* object)
{
    scene[name] = object;
    object->start();
}

GameObject* Engine::getGameObject(std::string name)
{
    return scene[name];
}

void Engine::update()
{
    for (auto& [name, object] : scene)
        object->update();

    for (auto& [name, object] : scene)
        object->render();

    for (auto& [name, object] : scene)
        object->lateUpdate();
}