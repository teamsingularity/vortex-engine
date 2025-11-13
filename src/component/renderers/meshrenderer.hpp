#ifndef MESHRENDERER_HPP
#define MESHRENDERER_HPP

#include <defines.hpp>
#include <component/renderer.hpp>
#include <engine/render/mesh.hpp>
#include <object/gameobject.hpp>

/**
 * @class MeshRenderer
 * @brief Component responsible for rendering 3D meshes.
 
 * The MeshRenderer handles drawing a Mesh using the active camera and material.

 */
class VORTEXAPI MeshRenderer : public Renderer
{
public:
    /**
     * @brief Constructs a MeshRenderer instance.
     * 
     * Initializes internal rendering data.
     */
    MeshRenderer();

    /**
     * @brief Destructor.
     * 
     * Cleans up mesh and renderer resources.
     */
    ~MeshRenderer();

    /** 
     * @brief Pointer to the Mesh that will be rendered. 
     */
    Mesh* mesh;

    /**
     * @brief Called when the component is first initialized.
     */
    void start();

    /**
     * @brief Called every frame to draw the mesh.
  
     */
    void render();

    /**
     * @brief Called when the component or object is destroyed.
     * 
     * Frees any allocated graphics resources.
     */
    void destroy();
private:
    bool isLit = true;
};

#endif // MESHRENDERER_HPP
