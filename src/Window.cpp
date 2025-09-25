#include "Window.hpp"
#include <iostream>
#include <Util/MessageBox.hpp>

int Window::width;
int Window::height;
std::string Window::title;
GLFWwindow* Window::window;

bool Window::init(int w, int h, std::string title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        MSG_ERROR("GLFW error", "Failed to create window!");
        glfwTerminate();
        return false;
    }

    width = w;
    height = h;

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to init GLEW!" << std::endl;
        glfwTerminate();
        return false;
    }

    glViewport(0, 0, width, height);

    return true;
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::terminate()
{
    glfwTerminate();
}
