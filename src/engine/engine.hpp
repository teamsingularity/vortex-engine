#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <defines.hpp>
#include <unordered_map>
#include <engine/render/material.hpp>
#include <engine/render/shader.hpp>
#include <engine/render/texture.hpp>
#include <object/gameobject.hpp>
#include <component/core/camera.hpp>
#include <string>

class VORTEXAPI Engine
{
public:
    static bool init(std::string title, int width, int height);
    static void terminate();

    static void addShader(std::string name, Shader* shader);
    static Shader* getShader(std::string name);

    static void addTexture(std::string name, Texture* texture);
    static Texture* getTexture(std::string name);

    static void addMaterial(std::string name, Material* material);
    static Material* getMaterial(std::string name);

    static void addGameObject(std::string name, GameObject* object);
    static GameObject* getGameObject(std::string name);

    static void update();
    static void clear();

    static Camera* camera;
    static float deltaTime;

private:
    static std::unordered_map<std::string, Shader*> shaders;
    static std::unordered_map<std::string, Texture*> textures;
    static std::unordered_map<std::string, Material*> materials;
    static std::unordered_map<std::string, GameObject*> scene;
};

#endif //ENGINE_HPP