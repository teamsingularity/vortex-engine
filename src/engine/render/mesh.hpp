#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>
#include <vector>
#include <defines.hpp>

/**
 * @file Mesh.hpp
 * @brief Mesh class for storing vertex data and drawing it with OpenGL.
 */

/**
 * @class Mesh
 * @brief Represents a 3D mesh with vertices and attributes for rendering.
 *
 * The Mesh class encapsulates a VAO, VBO, and vertex count. It allows
 * drawing the mesh with OpenGL.
 */
class VORTEXAPI Mesh
{
public:
    /**
     * @brief Constructs a mesh with vertex data and attributes.
     * @param vertices Vector of vertex data.
     * @param indices Vector of indices data data array in bytes.
     * @param attributes Vector of integers describing vertex attributes (e.g., positions, normals, UVs).
     */
    Mesh(std::vector<float> vertices, std::vector<GLuint> indices, std::vector<int> attributes);

    /**
     * @brief Destructor for Mesh.
     */
    ~Mesh();

    /**
     * @brief Draws the mesh using OpenGL.
     */
    void draw();

private:
    /**
     * @brief OpenGL Vertex Array Object.
     */
    GLuint vao;

    /**
     * @brief OpenGL Vertex Buffer Object.
     */
    GLuint vbo;

    /**
     * @brief OpenGL Element Buffer Object.
     */
    GLuint ebo;

    /**
     * @brief Number of vertices in the mesh.
     */
    GLuint vertexCount;

    /**
     * @brief Number of indices in the mesh.
     */
    GLuint indexCount;
};

#endif // MESH_HPP
