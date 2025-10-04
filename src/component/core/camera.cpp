#include "camera.hpp"
#include <engine/engine.hpp>
#include <engine/window.hpp>

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::start()
{
    Engine::camera = this;

    fov = 60.0f;
}

void Camera::update()
{
    proj = glm::perspective(glm::radians(fov), (float) Window::width / (float) Window::height, 0.1f, 100.0f);
}

void Camera::lateUpdate()
{
}

void Camera::destroy()
{
    Engine::camera = nullptr;
}

glm::mat4 Camera::getProjection()
{
    return proj;
}

glm::mat4 Camera::getView()
{
    return object->transform.getMatrix();
}