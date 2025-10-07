#ifndef INPUT_HPP
#define INPUT_HPP
#include <defines.hpp>

class VORTEXAPI Input 
{
public:
    static bool init();
    static void terminate();

    static bool getKey(int keycode);
    static bool getKeyDown(int keycode);

    static bool getMouseButton(int button);
    static bool getMouseButtonDown(int button);

    static void toggleCursor();

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