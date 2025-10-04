#include "meshrenderer.hpp"
#include <engine/render/mesh.hpp>
#include <engine/engine.hpp>

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
    if (Engine::camera == nullptr) return;

    object->mat->matShader->use();
    object->mat->baseTexture->bind(0);

    object->mat->matShader->uniformMatrix4fv("transform", object->transform.getMatrix());
    object->mat->matShader->uniformMatrix4fv("projection", Engine::camera->getProjection());
    object->mat->matShader->uniformMatrix4fv("view", Engine::camera->getView());

    mesh->draw();
}

void MeshRenderer::destroy()
{
}