#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <component/component.hpp>
#include <glm/glm.hpp>

/**
 * @class Camera
 * @brief Component that represents a view into the 3D world.
 *
 * The Camera defines how the scene is projected onto the screen.
 * It provides both projection and view matrices 
 
 */
class Camera : public Component
{
public:
    /**
     * @brief Constructs a new Camera component.
     * 
     * Initializes projection and view data.
     */
    Camera();

    /**
     * @brief Destructor.
     * 
     * Cleans up camera-related resources if necessary.
     */
    ~Camera();

    /**
     * @brief Called once when the camera is initialized.
     * 
     * Used to set up default projection parameters or register the camera in the scene.
     */
    void start();

    /**
     * @brief Called every frame before rendering.
     * 
     * Handles per-frame updates such as camera movement.
     */
    void update();

    /**
     * @brief Called after all updates are processed.
     * 
     * Useful for operations that depend on other components being updated first.
     */
    void lateUpdate();

    /**
     * @brief Called when the camera or its GameObject is destroyed.
     * 
     * Cleans up any associated data or unregisters the camera.
     */
    void destroy();

    /**
     * @brief Field of view (in degrees).
     * 
     * Defines the extent of the observable world seen through the camera.
     */
    float fov;

    /**
     * @brief Returns the projection matrix of the camera.
     * 
     * @return The 4x4 projection matrix used to convert 3D space into 2D screen space.
     */
    glm::mat4 getProjection();

    /**
     * @brief Returns the view matrix of the camera.
     * 
     * @return The 4x4 view matrix representing the camera’s position and orientation in the world.
     */
    glm::mat4 getView();

private:
    /**
     * Stored internally to avoid recalculating every frame.
     */
    glm::mat4 proj;
};

#endif // CAMERA_HPP
