#include "meshrenderer.hpp"
#include "engine/render/mesh.hpp"

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
    object->mat->matShader->use();
    object->mat->baseTexture->bind(0);

    object->mat->matShader->uniformMatrix4fv("transform", object->transform.getMatrix());

    mesh->draw();
}

void MeshRenderer::destroy()
{
}