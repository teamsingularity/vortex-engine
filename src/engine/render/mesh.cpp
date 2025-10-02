#include "mesh.hpp"
Mesh::Mesh(float* vertices, size_t verticesSize, std::vector<int> attributes)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

    int totalStride = 0;
    for (auto attr : attributes)
    {
        totalStride += attr;
    }

    vertexCount = verticesSize / sizeof(float) / totalStride;

    int stride = 0;
    int index = 0;
    for (auto attr : attributes)
    {
        glVertexAttribPointer(index, attr, GL_FLOAT, GL_FALSE, totalStride * sizeof(GLfloat), (GLvoid*)(stride * sizeof(float)));
        glEnableVertexAttribArray(index);
        stride += attr;
        index++;
    }

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void Mesh::draw()
{
    glBindVertexArray(vao); 
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    glBindVertexArray(0);
}