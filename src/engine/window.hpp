#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <defines.hpp>

class VORTEXAPI Window
{
public:
    static bool init(int width, int height, std::string title);

    static void swapBuffers();
    static bool shouldClose();
    static void terminate();

    static int width;
    static int height;
    static std::string title;

    static GLFWwindow* win;
};

#endif