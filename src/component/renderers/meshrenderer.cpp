#include "meshrenderer.hpp"
#include <engine/render/mesh.hpp>
#include <engine/engine.hpp>
#include "component/core/lightsource.hpp"
#include "shaders.hpp"

MeshRenderer::MeshRenderer()
{
}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::start()
{
}

void MeshRenderer::render()
{
    if (Engine::scene->camera == nullptr) return;

    object->mat->matShader->use();
    object->mat->baseTexture->bind(0);

    object->mat->matShader->uniformMatrix4fv("transform", object->transform.getMatrix());
    object->mat->matShader->uniformMatrix4fv("projection", Engine::scene->camera->getProjection());
    object->mat->matShader->uniformMatrix4fv("view", Engine::scene->camera->getView());
    if (isLit) {
    const auto& lights = Engine::scene->getLightsources();
    int numLights = std::min((int)lights.size(), 4); // например, максимум 4

    Engine::getShader(litFragment)->uniformInt("numLights", numLights);

    for (int i = 0; i < numLights; ++i) {
        Lightsource* l = lights[i];
        std::string prefix = "lights[" + std::to_string(i) + "].";

        Engine::getShader(litFragment)->uniformInt(prefix + "type", l->type);
        Engine::getShader(litFragment)->uniformVec3(prefix + "position", l->position);
        Engine::getShader(litFragment)->uniformVec3(prefix + "direction", l->direction);
        Engine::getShader(litFragment)->uniformVec3(prefix + "color", l->color);

        Engine::getShader(litFragment)->uniformFloat(prefix + "constant", l->constant);
        Engine::getShader(litFragment)->uniformFloat(prefix + "linear", l->linear);
        Engine::getShader(litFragment)->uniformFloat(prefix + "quadratic", l->quadratic);
        Engine::getShader(litFragment)->uniformFloat(prefix + "cutOff", l->cutOff);
        Engine::getShader(litFragment)->uniformFloat(prefix + "outerCutOff", l->outerCutOff);
    }
}


    mesh->draw();
}

void MeshRenderer::destroy()
{
}