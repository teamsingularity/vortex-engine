#ifndef INPUT_HPP
#define INPUT_HPP
#include "Window.hpp"

class Input 
{
public:
    static bool init();
    static void terminate();

    static bool getKey(int keycode);
    static bool getKeyDown();

    static bool getMouseButton();
    static bool getMouseButtonDown();

    static float mouseX, mouseY;
    static bool cursorLocked;
    static bool cursorStarted;
    static bool* keys;
    static uint* frames;
    static uint current;

    static float deltaY, deltaX;

    static void pollEvents();

};



#endif 