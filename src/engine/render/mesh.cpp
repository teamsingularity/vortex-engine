#include "mesh.hpp"

Mesh::Mesh(std::vector<float> vertices, std::vector<GLuint> indices, std::vector<int> attributes)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    int totalStride = 0;
    for (auto attr : attributes)
    {
        totalStride += attr;
    }

    vertexCount = vertices.size() / totalStride;
    indexCount = indices.size();

    int stride = 0;
    int index = 0;
    for (auto attr : attributes)
    {
        glVertexAttribPointer(index, attr, GL_FLOAT, GL_FALSE, totalStride * sizeof(GLfloat), (GLvoid*)(stride * sizeof(float)));
        glEnableVertexAttribArray(index);
        stride += attr;
        index++;
    }

    // EBO creation
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW); 


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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}