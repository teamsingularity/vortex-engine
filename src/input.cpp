#include "input.hpp"
#include <string.h>
#include <iostream>
#include "GLFW/glfw3.h"

#define MOUSE_BUTTONS_OFFSET 1024
//Variables
float input::mouseX = 0.0f;
float input::mouseY = 0.0f;
bool input::cursorLocked = false;
bool input::cursorStarted = false;

bool* input::keys;
uint* input::frames;
uint input::current =0;

float input::deltaY = 0.0f;
float input::deltaX = 0.0f;

//Functions
bool input::getKey(int keycode)
{
    return keys[keycode];
}

bool input::getKeyDown(int keycode)
{
    return keys[keycode] && (frames[keycode] == current);
}

bool input::getMouseButton(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button];
}

bool input::getMouseButtonDown(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button] && (frames[MOUSE_BUTTONS_OFFSET + button] == current);
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (input::cursorStarted)
    {
        input::deltaX += xpos -input::mouseX;
        input::deltaY += ypos -input::mouseY;
    } else {
        input::cursorStarted = true;
    }

    input::mouseX = xpos;
    input::mouseY = ypos;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mode){
	if (action == GLFW_PRESS){
		input::keys[MOUSE_BUTTONS_OFFSET+button] = true;
		input::frames[MOUSE_BUTTONS_OFFSET+button] = input::current;
	}
	else if (action == GLFW_RELEASE){
		input::keys[MOUSE_BUTTONS_OFFSET+button] = false;
		input::frames[MOUSE_BUTTONS_OFFSET+button] = input::current;
    }
}

void keyCallback(GLFWwindow* window , int key, int scancode, int action , int mode){
    if(action == GLFW_PRESS){
        input::keys[key] = true;
        input::frames[key] = input::current;
    } else if (action == GLFW_RELEASE){
        input::keys[key] = false;
        input::frames[key] = input::current;
    }
}

bool input::init()
{
    GLFWwindow* win = window::win;
    keys = new bool[1032];
    frames = new uint[1032];

    memset(keys, false, 1032*sizeof(bool));
    memset(frames, 0, 1032*sizeof(uint));

    glfwSetKeyCallback(win, keyCallback);
    glfwSetMouseButtonCallback(win, mouseButtonCallback);
    glfwSetCursorPosCallback(win, cursorPositionCallback);

    return true;
}

void input::pollEvents()
{
    deltaY = 0.0f;
    deltaX = 0.0f;

    current++;
    glfwPollEvents();
}

void input::terminate()
{
    // a stub
}