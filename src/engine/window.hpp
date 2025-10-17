#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <defines.hpp>

/**
 * Singleton that incapsulates methods to manipulate window.
 */
class VORTEXAPI Window
{
public:
    /**
     * Initializes GLFW window and OpenGL.
     * @param width Window width.
     * @param height Window height.
     * @param title Window title.
     * @return Boolean status, `false` if initialization failed, `true` if initialization succeeded.
     */
    static bool init(int width, int height, std::string title);

    /**
     * Swaps window buffers.
     */
    static void swapBuffers();

    /**
     * Checks if the window should be closed.
     * @return Boolean state, `false` if window should not be closed, `true` if window should be closed.
     */
    static bool shouldClose();

    /**
     * Cleans up resources and destroys window.
     */
    static void terminate();

    /**
     * Sets cursor mode.
     * @param mode GLFW cursor mode.
     */
    static void setCursorMode(int mode);
    
    /**
     * Sets window title.
     * @param title New window title.
     */
    static void setTitle(std::string title);

    static int width;
    static int height;
    static std::string title;

    static GLFWwindow* win;
};

#endif