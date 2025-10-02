#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <defines.hpp>

class VORTEXAPI Transform
{
public:
    Transform();
    ~Transform();

    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    glm::vec3 forward;
    glm::vec3 up;
    glm::vec3 right;

    void rotate(glm::vec3 rot);
    void translate(glm::vec3 trans);
    void resize(glm::vec3 scale);

    glm::mat4 getMatrix();
    void update();
};

#endif //TRANSFORM_HPP