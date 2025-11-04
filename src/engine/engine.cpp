#include "engine.hpp"
#include <GL/gl.h>
#include <engine/render/framebuffer.hpp>
#include <engine/render/mesh.hpp>
#include <engine/render/shader.hpp>
#include <GLFW/glfw3.h>
#include <engine/window.hpp>
#include <engine/input.hpp>
#include <engine/audio.hpp>
#include <engine/render/texture.hpp>

std::unordered_map<std::string, Shader*> Engine::shaders;
std::unordered_map<std::string, Texture*> Engine::textures;
std::unordered_map<std::string, Material*> Engine::materials;
Scene* Engine::scene;
float Engine::deltaTime;
Mesh* Engine::quad;

float lastTime = 0.0f;

bool Engine::init(std::string title, int width, int height)
{
    if (!Window::init(width, height, title)) return false;
    if (!Input::init()) return false;
    if (!Audio::init()) return false;

    glEnable(GL_DEPTH_TEST);

    quad = new Mesh({
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // bottom-left
         1.0f, -1.0f, 0.0f,  1.0f, 0.0f,  // bottom-right
         1.0f,  1.0f, 0.0f,  1.0f, 1.0f,  // top-right
        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f   // top-left
    }, {0, 1, 2, 2, 3, 0}, {3, 2});
    
    return true;
}

void Engine::terminate()
{
    Window::terminate();
    Input::terminate();
    Audio::terminate();
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

Framebuffer* Engine::createFramebuffer()
{
    Texture* texture = Texture::create(Window::width, Window::height);
    Framebuffer* framebuffer = Framebuffer::create(texture, Window::width, Window::height);
    
    return framebuffer;
}

void Engine::render(Framebuffer* framebuffer)
{
    float currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    Input::pollEvents();
    Audio::update();

    if (framebuffer != nullptr)
    {
        framebuffer->bind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
    }
    
    scene->render();

    if (framebuffer != nullptr)
    {
        framebuffer->unbind();
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void Engine::renderQuad(Shader *shader)
{
    glDisable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    quad->draw();
    glEnable(GL_DEPTH_TEST);
}

void Engine::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}