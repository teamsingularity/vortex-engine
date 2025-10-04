#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <component/component.hpp>
#include <glm/glm.hpp>

class Camera : public Component
{
public:
    Camera();
    ~Camera();

    void start();
    void update();
    void lateUpdate();
    void destroy();

    float fov;

    glm::mat4 getProjection();
    glm::mat4 getView();

private:
    glm::mat4 proj;
};

#endif 