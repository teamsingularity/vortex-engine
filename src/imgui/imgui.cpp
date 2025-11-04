#include "imgui.hpp"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <engine/window.hpp>

bool IMGUI::init()
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(Window::win, true);
    ImGui_ImplOpenGL3_Init("#version 330 core"); // GLSL version

    return true;
}

void IMGUI::destroy()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void IMGUI::newFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void IMGUI::render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}