#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Window.hpp>

#define WIDTH 1280
#define HEIGHT 720

int main(void){
    
    if (!Window::init(WIDTH, HEIGHT, "Vortex Engine"))
    {
        std::cerr << "Failed to initialize window!" << std::endl;
        return 1;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    while (!Window::shouldClose())
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        Window::swapBuffers();
    }

    glfwTerminate();
    return 0;
}