#include "Menu.hpp"

using namespace Engine::GUI;
//std::map<std::string, bool> menu_selection_value;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Menu::Menu()
{
   
}

Menu::~Menu()
{

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render *******************************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::render(int width, int height, std::map<std::string, bool> &menu_selection_value)
{
    ImGuiWindowFlags window_flags = 0;
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec2 frame_padding_save = style.FramePadding;

    window_flags |= ImGuiWindowFlags_NoResize;
    ImGui::SetNextWindowPos(ImVec2(width / 2 - 200, height / 2 - 200));
    ImGui::SetNextWindowSize(ImVec2(400, 400));


    ImGui::Begin("Settings", NULL, window_flags);


   /* if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
    {
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("Navigation Options"))
        {
            style.FramePadding = frame_padding_save;
            this->manageNavigation(data_manager);
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("HUD"))
        {
            style.FramePadding = frame_padding_save;
            this->manageHUD(data_manager);
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("Performance"))
        {
            style.FramePadding = frame_padding_save;
            this->managePerformance(data_manager);
            ImGui::EndTabItem();
        }

        style.FramePadding = frame_padding_save;
        ImGui::EndTabBar();
    }*/
    style.FramePadding = frame_padding_save;

    ImGui::Separator();

    // if(ImGui::Button("Save Configuration", ImVec2(385.0f, 30.0f)))
    // {
    //     Saving::writeConfig(render_data);
    // }

    if (ImGui::Button("Stop Simulation", ImVec2(385.0f, 30.0f)))
    {
        menu_selection_value["quit"] = true;
    }

    ImGui::End();
}