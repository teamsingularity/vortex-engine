#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <defines.hpp>

/**
 * @brief Represents position, rotation, and scale of an object in 3D space.
 *
 * Transform stores spatial data for any scene object and provides helper 
 * methods for movement, rotation, and scaling. It also calculates the 
 * model matrix used in rendering.
 */
class VORTEXAPI Transform
{
public:
    /**
     * @brief Constructs a Transform 
     */
    Transform();

    /**
     * @brief Destroys the Transform instance.
     */
    ~Transform();

    /**
     * @brief World position of the object.
     */
    glm::vec3 position;

    /**
     * @brief Rotation of the object represented as a quaternion.
     */
    glm::quat rotation;

    /**
     * @brief Scale of the object along each axis.
     */
    glm::vec3 scale;

    /**
     * @brief Forward direction vector derived from the rotation.
     */
    glm::vec3 forward;

    /**
     * @brief Up direction vector derived from the rotation.
     */
    glm::vec3 up;

    /**
     * @brief Right direction vector derived from the rotation.
     */
    glm::vec3 right;

    /**
     * @brief Rotates the transform by the specified Euler angles.
     * @param rot Euler angles (in radians) representing rotation delta.
     */
    void rotate(glm::vec3 rot);

    /**
     * @brief Moves the transform by the given offset.
     * @param trans Offset vector representing translation delta.
     */
    void translate(glm::vec3 trans);

    /**
     * @brief Scales the transform by the given factor.
     * @param scale Scale vector representing new scale multiplier.
     */
    void resize(glm::vec3 scale);

    /**
     * @brief Calculates and returns the 4x4 transformation matrix.
     * @return Model matrix combining position, rotation, and scale.
     */
    glm::mat4 getMatrix();

    /**
     * @brief Updates direction vectors (forward, up, right) based on rotation.
     */
    void update();
};

#endif //TRANSFORM_HPP
