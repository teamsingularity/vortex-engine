#ifndef INPUT_HPP
#define INPUT_HPP

#include <defines.hpp>

/**
 * @class Input
 * @brief Static class for handling keyboard and mouse input.
 */
class VORTEXAPI Input 
{
public:
    /**
     * @brief Initializes input system.
     * @return True if initialization succeeded, false otherwise.
     */
    static bool init();

    /**
     * @brief Terminates input system and releases resources.
     */
    static void terminate();

    /**
     * @brief Checks if a key is currently pressed.
     * @param keycode Key code to check.
     * @return True if key is pressed, false otherwise.
     */
    static bool getKey(int keycode);

    /**
     * @brief Checks if a key was pressed in the current frame.
     * @param keycode Key code to check.
     * @return True if key was pressed this frame, false otherwise.
     */
    static bool getKeyDown(int keycode);

    /**
     * @brief Checks if a mouse button is currently pressed.
     * @param button Mouse button index.
     * @return True if button is pressed, false otherwise.
     */
    static bool getMouseButton(int button);

    /**
     * @brief Checks if a mouse button was pressed in the current frame.
     * @param button Mouse button index.
     * @return True if button was pressed this frame, false otherwise.
     */
    static bool getMouseButtonDown(int button);

    /**
     * @brief Toggles mouse cursor lock.
     */
    static void toggleCursor();

    /// Current mouse X position.
    static float mouseX;

    /// Current mouse Y position.
    static float mouseY;

    /// Is cursor locked to the window.
    static bool cursorLocked;

    /// Has cursor been initialized.
    static bool cursorStarted;

    /// Array of key states.
    static bool* keys;

    /// Array of frame counters for each key.
    static uint* frames;

    /// Current frame counter.
    static uint current;

    /// Mouse movement delta X.
    static float deltaX;

    /// Mouse movement delta Y.
    static float deltaY;

    /**
     * @brief Polls input events from the operating system.
     */
    static void pollEvents();
};

#endif
