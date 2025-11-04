#ifndef IMGUI_HPP
#define IMGUI_HPP

#include <defines.hpp>
#include <imgui.h>

/**
 * @brief IMGUI tools to draw debug GUI.
 */
class VORTEXAPI IMGUI
{
public:
    /**
     * @brief Initialize ImGui library and renderer.
     */
    static bool init();

    /**
     * @brief Destroy ImGui library and renderer.
     */
    static void destroy();

    /**
     * @brief Create new UI frame.
     */
    static void newFrame();

    /**
     * @brief Render collected UI.
     */
    static void render();
};

#endif //IMGUI_HPP