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
/*********************************************************************** renderNavigationTab ***************************************************************************/
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
        m_bool_selection->insert_or_assign("changes", true);
    }
}

/***********************************************************************************************************************************************************************/
/*************************************************************************** renderHUDTab ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::renderHUDTab()
{
    ImGui::Text("General");
    bool over_rend = m_bool_selection->at("render_overlay");
    ImGui::Bullet();
    ImGui::SameLine();
    if (ImGui::Checkbox("Display Overlay", &over_rend))
    {
        m_bool_selection->insert_or_assign("render_overlay", over_rend);
        m_bool_selection->insert_or_assign("changes", true);
    }

    bool name_rend = m_bool_selection->at("render_name");
    ImGui::Bullet();
    ImGui::SameLine();
    if (ImGui::Checkbox("Display Name", &name_rend))
    {
        m_bool_selection->insert_or_assign("render_name", name_rend);
        m_bool_selection->insert_or_assign("changes", true);
    }

    bool info_rend = m_bool_selection->at("render_info");
    ImGui::Bullet();
    ImGui::SameLine();
    if (ImGui::Checkbox("Display Planete Information", &info_rend))
    {
        m_bool_selection->insert_or_assign("render_info", info_rend);
        m_bool_selection->insert_or_assign("changes", true);
    }
    ImGui::SameLine();
    this->HelpMarker("It is possible to activate this functionality with the 'SPACE' key.");

    
    ImGui::Separator();

    this->HelpMarker("More in coming like the possibility to manage the style of the different windows.");
}

/***********************************************************************************************************************************************************************/
/*************************************************************************** renderPerformanceTab **********************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::renderPerformanceTab()
{
    ImGui::Text("Rendering");

    ImGui::BulletText("Highlight Sun");
    ImGui::SameLine();
    if (ImGui::Button("Enabled"))
    {
        m_bool_selection->insert_or_assign("highligh_sun", true);
        m_bool_selection->insert_or_assign("changes", true);
    }
    ImGui::SameLine();
    if (ImGui::Button("Disabled"))
    {
        m_bool_selection->insert_or_assign("highligh_sun", false);
        m_bool_selection->insert_or_assign("changes", true);
    }

    bool bloom = m_bool_selection->at("bloom");
    int bloom_str = m_int_selection->at("bloom_str");
    if (ImGui::Button("Set Bloom"))
        ImGui::OpenPopup("my_bloom_popup");
    if (ImGui::BeginPopup("my_bloom_popup"))
    {
        ImGui::Text("Set Bloom");
        if (ImGui::Checkbox("Enabled/Disabled", &bloom))
        {
            m_bool_selection->insert_or_assign("bloom", bloom);
            m_bool_selection->insert_or_assign("changes", true);
        }
        

        ImGui::BulletText("Set Bloom Strength");
        ImGui::SameLine();
        if (ImGui::SliderInt(" ", &bloom_str, 2, 10))
        {
            m_int_selection->insert_or_assign("bloom_str", bloom_str);
            m_bool_selection->insert_or_assign("changes", true);
        }

        if (ImGui::Button("Close"))
            ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }

    bool render_shadow = m_bool_selection->at("render_shadow");
    if (ImGui::Checkbox("Render shadow", &render_shadow))
    {
        m_bool_selection->insert_or_assign("render_shadow", render_shadow);
        m_bool_selection->insert_or_assign("changes", true);
    }
    
    ImGui::Separator();

    ImGui::Text("Textures");
    bool normal_render = m_bool_selection->at("render_normal");
    ImGui::BulletText("Show Ground relief");
    ImGui::SameLine();
    if (ImGui::Checkbox("Activated/Disabled", &normal_render))
    {
        m_bool_selection->insert_or_assign("render_normal", normal_render);
        m_bool_selection->insert_or_assign("changes", true);
    }
    
    ImGui::Text("Asteroid Quantity");
    ImGui::SameLine();
    this->HelpMarker("Astroid count influence the performance so you can now chose the amount.");
    ImGui::Bullet();
    int asteroid_count = m_int_selection->at("asteroid_count");
    if (ImGui::SliderInt("Count", &asteroid_count, 2000, 10000))
    {
        m_int_selection->insert_or_assign("asteroid_count", asteroid_count);
        m_bool_selection->insert_or_assign("changes", true);
    }
    ImGui::Separator();

    static int selected = -1;
    int fps[] = { 25, 60, 120, 144, 240 };
    const char* names[] = { "25", "60", "120", "144", "240" };
    if (ImGui::Button("Select.."))
        ImGui::OpenPopup("my_select_popup");
    ImGui::SameLine();
    ImGui::Text("FPS Count : ");
    ImGui::SameLine();
    ImGui::TextUnformatted(selected == -1 ? "default" : names[selected]);
    if (ImGui::BeginPopup("my_select_popup"))
    {
        if (ImGui::Selectable("default"))
            selected = -1;
        ImGui::Separator();
        for (int i = 0; i < IM_ARRAYSIZE(names); i++)
            if (ImGui::Selectable(names[i]))
               selected = i;
        ImGui::EndPopup();
    }

    if ((selected >= 0) && (selected < 5) && (m_int_selection->at("fps")) != fps[selected])
    {
        m_int_selection->insert_or_assign("fps", fps[selected]);
        m_bool_selection->insert_or_assign("changes", true);
    }
}

/***********************************************************************************************************************************************************************/
/************************************************************************************* HelpMarker **********************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::HelpMarker(std::string sentence)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(sentence.c_str());
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
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
    window_flags |= ImGuiWindowFlags_AlwaysAutoResize;
    window_flags |= ImGuiWindowFlags_NoScrollbar;
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
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("HUD"))
        {
            style.FramePadding = frame_padding_save;
            this->renderHUDTab();
            ImGui::EndTabItem();
        }
        style.FramePadding = ImVec2(25, 3);
        if (ImGui::BeginTabItem("Performance"))
        {
            style.FramePadding = frame_padding_save;
            this->renderPerformanceTab();
            ImGui::EndTabItem();
        }

        style.FramePadding = frame_padding_save;
        ImGui::EndTabBar();
    }
    style.FramePadding = frame_padding_save;

    ImGui::Separator();

     if(ImGui::Button("Save Configuration", ImVec2(385.0f, 30.0f)))
     {
         m_bool_selection->insert_or_assign("save", true);
         m_bool_selection->insert_or_assign("changes", true);
     }

    if (ImGui::Button("Stop Simulation", ImVec2(385.0f, 30.0f)))
    {
        m_bool_selection->insert_or_assign("quit", true);
        m_bool_selection->insert_or_assign("changes", true);
    }

    ImGui::End();
}

/***********************************************************************************************************************************************************************/
/************************************************************************* addImguiTextureData *************************************************************************/
/***********************************************************************************************************************************************************************/
void Menu::addImguiTextureData(imguiTexture_datas imgui_datas)
{
    textures_data.push_back(imgui_datas);
}
