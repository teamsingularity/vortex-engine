#include "window.hpp"
#include <iostream>

int window::width;
int window::height;
std::string window::title;
GLFWwindow* window::win;

bool window::init(int w, int h, std::string title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    win = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
    if (win == nullptr)
    {
        std::cerr << "Failed to create window!" << std::endl;
        glfwTerminate();
        return false;
    }

    width = w;
    height = h;

    glfwMakeContextCurrent(win);

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

void window::swapBuffers()
{
    glfwSwapBuffers(win);
}

bool window::shouldClose()
{
    return glfwWindowShouldClose(win);
}

void window::terminate()
{
    glfwTerminate();
}