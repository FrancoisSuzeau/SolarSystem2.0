#include "HUD.hpp"

using namespace Engine::GUI;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
HUD::HUD(std::map<std::string, bool>* bool_selection, std::map<std::string, float>* float_selection, std::map<std::string, int>* int_selection) : m_bool_selection(bool_selection),
m_float_selection(float_selection), m_int_selection(int_selection)
{

}

HUD::~HUD()
{

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render *******************************************************************************/
/***********************************************************************************************************************************************************************/
void HUD::renderApplicationHUD()
{
    time_t local_time = time(0);
    std::string time = ctime(&local_time);

    ImGuiWindowFlags window_flags = 0;
    ImGuiIO& io = ImGui::GetIO();

    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoBackground;

    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.04f, 0.04f, 0.04f, 1.0f));
    ImGui::SetNextWindowPos(ImVec2(0.0, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(380, 150));

    ImGui::Begin("Application Information", NULL, window_flags);

    ImGui::Text("Application Information : ");

    std::string tmp = "Time : " + time;
    ImGui::Bullet();
    ImGui::Text(tmp.c_str());

    ImGui::Bullet();
    ImGui::Text("Application average : %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    if (ImGui::TreeNode("Mouse State"))
    {
        if (ImGui::IsMousePosValid())
            ImGui::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
        else
            ImGui::Text("Mouse pos: <INVALID>");
        ImGui::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);

        int count = IM_ARRAYSIZE(io.MouseDown);
        ImGui::Text("Mouse down:");         for (int i = 0; i < count; i++) if (ImGui::IsMouseDown(i)) { ImGui::SameLine(); ImGui::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]); }
        ImGui::TreePop();
    }

    ImGui::PopStyleColor();
    ImGui::End();
}

void HUD::renderMusicHUD(int width, int height, music_info infos)
{
    ImGuiWindowFlags window_flags = 0;
    ImGuiStyle& style = ImGui::GetStyle();

    window_flags |= ImGuiWindowFlags_NoResize;

    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.04f, 0.04f, 0.04f, 1.0f));
    ImGui::SetNextWindowPos(ImVec2((float)width - 380.f, (float)height - 170.f));
    ImGui::SetNextWindowSize(ImVec2(380, 170));

    float save_frame = style.FrameRounding;
    float save_grab = style.GrabRounding;
    style.FrameRounding = 15;
    style.GrabRounding = 15;

    ImGui::Begin("Music Information", NULL, window_flags);

    ImGui::AlignTextToFramePadding();
    ImGui::Text("Title :");
    ImGui::SameLine();

    float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
    ImGui::PushButtonRepeat(true);
    int a = m_int_selection->at("current_track");
    if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { m_int_selection->insert_or_assign("current_track", a - 1); }
    ImGui::SameLine(0.0f, spacing);
    ImGui::Text(infos.title.c_str());
    ImGui::SameLine(0.0f, spacing);
    if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { m_int_selection->insert_or_assign("current_track", a + 1); }
    ImGui::PopButtonRepeat();

    std::string tmp = "Author :    " + infos.author;
    ImGui::Text(tmp.c_str());

    tmp = "Studio :    " + infos.studio;
    ImGui::Text(tmp.c_str());
    a = m_int_selection->at("volume");
    ImGui::SliderInt("Volume", &a, 0, 128);
    m_int_selection->insert_or_assign("volume", a);

    bool pause = m_bool_selection->at("pause");
    ImGui::Checkbox("Mute music", &pause);
    m_bool_selection->insert_or_assign("pause", pause);

    const char* items[] = { "Epic Orchestra", "Citadel radio", "Retro Wave 86", "-Error Canal Transmission-" };
    a = m_int_selection->at("current_radio");
    ImGui::Combo("Radio", &a, items, IM_ARRAYSIZE(items));
    m_int_selection->insert_or_assign("current_radio", a);

    style.FrameRounding = save_frame;
    style.GrabRounding = save_grab;

    ImGui::PopStyleColor();
    ImGui::End();
}
