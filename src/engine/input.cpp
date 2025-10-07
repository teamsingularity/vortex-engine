#include "input.hpp"
#include <string.h>
#include <engine/window.hpp>
#include "GLFW/glfw3.h"

#define MOUSE_BUTTONS_OFFSET 1024
//Variables
float Input::mouseX = 0.0f;
float Input::mouseY = 0.0f;
bool Input::cursorLocked = false;
bool Input::cursorStarted = false;

bool* Input::keys;
uint* Input::frames;
uint Input::current =0;

float Input::deltaY = 0.0f;
float Input::deltaX = 0.0f;

//Functions
bool Input::getKey(int keycode)
{
    return keys[keycode];
}

bool Input::getKeyDown(int keycode)
{
    return keys[keycode] && (frames[keycode] == current);
}

bool Input::getMouseButton(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button];
}

bool Input::getMouseButtonDown(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button] && (frames[MOUSE_BUTTONS_OFFSET + button] == current);
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (Input::cursorStarted){
        Input::deltaX += xpos-Input::mouseX;
        Input::deltaY += ypos-Input::mouseY;
    }
    else
    {
        Input::cursorStarted = true;
    }
    Input::mouseX = xpos;
    Input::mouseY = ypos;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mode){
	if (action == GLFW_PRESS){
		Input::keys[MOUSE_BUTTONS_OFFSET+button] = true;
		Input::frames[MOUSE_BUTTONS_OFFSET+button] = Input::current;
	}
	else if (action == GLFW_RELEASE){
		Input::keys[MOUSE_BUTTONS_OFFSET+button] = false;
		Input::frames[MOUSE_BUTTONS_OFFSET+button] = Input::current;
    }
}

void keyCallback(GLFWwindow* window , int key, int scancode, int action , int mode){
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
    GLFWwindow* win = Window::win;
    keys = new bool[1032];
    frames = new uint[1032];

    memset(keys, false, 1032*sizeof(bool));
    memset(frames, 0, 1032*sizeof(uint));

    glfwSetKeyCallback(win, keyCallback);
    glfwSetMouseButtonCallback(win, mouseButtonCallback);
    glfwSetCursorPosCallback(win, cursorPositionCallback);

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
    // a stub
}

void Input::toggleCursor()
{
    cursorLocked = !cursorLocked;
	Window::setCursorMode(cursorLocked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}