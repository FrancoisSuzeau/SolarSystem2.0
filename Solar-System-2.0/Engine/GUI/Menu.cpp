#include "Menu.hpp"

using namespace Engine::GUI;


/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Menu::Menu(std::map<std::string, bool>* bool_selection, std::map<std::string, float>* float_selection, std::map<std::string, int>* int_selection) : m_bool_selection(bool_selection),
m_float_selection(float_selection), m_int_selection(int_selection)
{
    min_distance.push_back(2.0f);
    min_distance.push_back(1.180f);
    min_distance.push_back(1.6f);
}

Menu::~Menu()
{

}

/***********************************************************************************************************************************************************************/
/*********************************************************************** manageNavigation ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::renderNavigationTab()
{
    float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
    int index = m_int_selection->at("ship_index");

    ImGui::BulletText("Choose your vessel : ");
   
    ImGui::PushButtonRepeat(true);
    
    if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { m_int_selection->insert_or_assign("ship_index", index - 1); }
    ImGui::SameLine(0.0f, spacing);
    if (ImGui::ImageButton((void*)(intptr_t)textures_data[index].text_id, ImVec2(textures_data[index].img_width * 0.5f, textures_data[index].img_height * 0.5f), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f)))
    {
        m_bool_selection->insert_or_assign("change_ship", true);
        
    }
    ImGui::SameLine(0.0f, spacing);
    if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { m_int_selection->insert_or_assign("ship_index", index + 1); }
    ImGui::PopButtonRepeat();
    ImGui::Text(textures_data[index].name.c_str());
    ImGui::Separator();

    float distance = m_float_selection->at("distance_from_ship");
    int current_index = m_int_selection->at("current_ship_index");
    ImGui::BulletText("Distance from ship");
    if (ImGui::SliderFloat(" ", &distance, min_distance[current_index], 10.0f))
    {
        m_float_selection->insert_or_assign("distance_from_ship", distance);
    }
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render *******************************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::render(int width, int height)
{
    ImGuiWindowFlags window_flags = 0;
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec2 frame_padding_save = style.FramePadding;

    window_flags |= ImGuiWindowFlags_NoResize;
    ImGui::SetNextWindowPos(ImVec2(((float)width / 2.f) - 200.f, ((float)height / 2.f) - 200.f));
    ImGui::SetNextWindowSize(ImVec2(400, 400));


    ImGui::Begin("Settings", NULL, window_flags);


   if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
    {
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("Navigation Options"))
        {
            style.FramePadding = frame_padding_save;
            this->renderNavigationTab();
            ImGui::EndTabItem();
        }
        /*style.FramePadding = ImVec2(25, 3);
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
        }*/

        style.FramePadding = frame_padding_save;
        ImGui::EndTabBar();
    }
    style.FramePadding = frame_padding_save;

    ImGui::Separator();

     if(ImGui::Button("Save Configuration", ImVec2(385.0f, 30.0f)))
     {
         m_bool_selection->insert_or_assign("save", true);
     }

    if (ImGui::Button("Stop Simulation", ImVec2(385.0f, 30.0f)))
    {
        m_bool_selection->insert_or_assign("quit", true);
    }

    ImGui::End();
}

void Menu::addImguiTextureData(imguiTexture_datas imgui_datas)
{
    textures_data.push_back(imgui_datas);
}
