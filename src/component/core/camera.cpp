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
    Engine::scene->camera = this;

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
    Engine::scene->camera = nullptr;
}

glm::mat4 Camera::getProjection()
{
    return proj;
}

glm::mat4 Camera::getView()
{
    return glm::inverse(object->transform.getMatrix());
}