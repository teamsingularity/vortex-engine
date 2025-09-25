#include "input.hpp"
#include <string.h>
#include "GLFW/glfw3.h"

#define MOUSE_BUTTONS 1024

float Input::mouseX = 0.0f;
float Input::mouseY = 0.0f;
bool Input::cursorLocked = false;
bool Input::cursorStarted = false;

bool* Input::keys;
uint* Input::frames;
uint Input::current =0;

float Input::deltaY = 0.0f;
float Input::deltaX = 0.0f;
bool Input::getKey(int keycode)
{
    return keys[keycode];
}

void getCursorPosition(GLFWwindow* window, double xpos, double ypos)
{
if (Input::cursorStarted)
{
    Input::deltaX += xpos -Input::mouseX;
    Input::deltaY += ypos -Input::mouseY;
} else {
    Input::cursorStarted = true;
}
    Input::mouseX = xpos;
    Input::mouseY = ypos;
}

void getButtonRC(GLFWwindow* window, int button, int action, int mode){
	if (action == GLFW_PRESS){
		Input::keys[MOUSE_BUTTONS+button] = true;
		Input::frames[MOUSE_BUTTONS+button] = Input::current;
	}
	else if (action == GLFW_RELEASE){
		Input::keys[MOUSE_BUTTONS+button] = false;
		Input::frames[MOUSE_BUTTONS+button] = Input::current;
    }
}

void keyRC(GLFWwindow* window , int key, int scancode, int action , int mode){
    if(action == GLFW_PRESS){
        Input::keys[key] = true;
        Input::frames[key] = Input::current;
    } else if (action == GLFW_RELEASE){
        Input::keys[key] = false;
        Input::frames[key] = Input::current;
    }
}

bool Input::init()
{
    GLFWwindow* win = Window::window;
    keys = new bool[1032];
    frames = new uint[1032];

    memset(keys, false, 1032*sizeof(bool));
    memset(frames, 0, 1032*sizeof(uint));

    glfwSetKeyCallback(win, keyRC);
    glfwSetMouseButtonCallback(win, getButtonRC);
    glfwSetCursorPosCallback(win, getCursorPosition);

    return true;
    
}

void Input::pollEvents()
{
    deltaY = 0.0f;
    deltaX = 0.0f;

    current++;
    glfwPollEvents();
}

void Input::terminate()
{
    //jam
}