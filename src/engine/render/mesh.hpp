#ifndef MESH_HPP
#define MESH_HPP

#include <GL/glew.h>
#include <vector>
#include <defines.hpp>

class VORTEXAPI Mesh
{
public:
    Mesh(float* vertices, size_t verticesSize, std::vector<int> attributes);
    ~Mesh();

    void draw();
private:
    GLuint vao;
    GLuint vbo;
    GLuint vertexCount;
};

#endif //MESH_HPP