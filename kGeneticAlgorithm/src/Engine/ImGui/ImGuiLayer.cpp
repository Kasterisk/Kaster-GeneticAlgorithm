#include "ImGui/ImGuiLayer.h"
#include "Logger.h"

#include <glad/glad.h>

ImGuiLayer::ImGuiLayer(SDL_Window* window, SDL_GLContext& context)
{
	if (!window) {
        LOG_ERROR("Failed to initialize ImGui, window is missing!");
        return;
	}

	if (context == nullptr) {
        LOG_ERROR("Failed to initialize imGui, GL context is missing!");
        return;
	}

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 130");

    ImGui::StyleColorsClassic();

	LOG_INFO("ImGui Initialized");
}

void ImGuiLayer::OnEvent(SDL_Event& event)
{
    ImGui_ImplSDL2_ProcessEvent(&event);
}

void ImGuiLayer::Begin(SDL_Window* window)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
}

void ImGuiLayer::End()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::Clear() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}
