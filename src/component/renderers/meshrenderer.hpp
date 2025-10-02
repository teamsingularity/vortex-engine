#ifndef MESHRENDERER_HPP
#define MESHRENDERER_HPP

#include <defines.hpp>
#include <component/renderer.hpp>
#include <engine/render/mesh.hpp>
#include <object/gameobject.hpp>

class VORTEXAPI MeshRenderer : public Renderer
{
public:
    MeshRenderer();

    ~MeshRenderer();

    Mesh* mesh;

    void start();
    void render();
    void destroy();
};

#endif //MESHRENDERER_HPP