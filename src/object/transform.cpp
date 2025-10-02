#include "transform.hpp"
#include <glm/ext/matrix_float2x2.hpp>

Transform::Transform() : position(0), rotation(glm::angleAxis(glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 0.0f))), scale(1, 1, 1),
                    forward(0), right(0)
{
}

Transform::~Transform()
{
}

void Transform::update()
{
    glm::mat4 rotationMatrix = glm::toMat4(rotation);

    forward = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(0, 0, -1, 0)));
    up      = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(0, 1,  0, 0)));
    right   = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(1, 0,  0, 0)));
}

glm::mat4 Transform::getMatrix()
{
    glm::mat4 matrix(1.0f);
    matrix = glm::translate(matrix, position);

    matrix *= glm::toMat4(rotation);

    matrix = glm::scale(matrix, scale);

    return matrix;
}

void Transform::rotate(glm::vec3 rot)
{
    glm::vec3 radians = glm::radians(rot);
    rotation = glm::quat(radians) * rotation;
}

void Transform::translate(glm::vec3 trans)
{
    position += trans;
}

void Transform::resize(glm::vec3 _scale)
{
    scale += _scale;
}
