#include "HUD.hpp"

using namespace Engine::GUI;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
HUD::HUD()
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

void HUD::renderMusicHUD(int width, int height, std::map<std::string, int>& hud_music_selection, music_info infos)
{
    ImGuiWindowFlags window_flags = 0;
    ImGuiStyle& style = ImGui::GetStyle();

    //int vol = data_manager.getVolume();
    //bool pause_music = data_manager.getPause();

    window_flags |= ImGuiWindowFlags_NoResize;

    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.04f, 0.04f, 0.04f, 1.0f));
    ImGui::SetNextWindowPos(ImVec2(width - 380, height - 170));
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
    if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { hud_music_selection["current_track"]--; }
    ImGui::SameLine(0.0f, spacing);
    ImGui::Text(infos.title.c_str());
    ImGui::SameLine(0.0f, spacing);
    if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { hud_music_selection["current_track"]++; }
    ImGui::PopButtonRepeat();

    std::string tmp = "Author :    " + infos.author;
    ImGui::Text(tmp.c_str());

    tmp = "Studio :    " + infos.studio;
    ImGui::Text(tmp.c_str());

    ImGui::SliderInt("Volume", &hud_music_selection["volume"], 0, 128);

    bool pause = hud_music_selection["pause"] == 1;
    ImGui::Checkbox("Mute music", &pause);
    hud_music_selection["pause"] = pause ? 1 : 0;

    const char* items[] = { "Epic Orchestra", "-Error Canal Transmission-", "-Error Canal Transmission-", "-Error Canal Transmission-" };
    static int item_current = 0;
    ImGui::Combo("Radio", &item_current, items, IM_ARRAYSIZE(items));

    //ImGui::SameLine();
    //std::string t_mp = "For now there only is one radio available until NASA engineers upgrade their Deep Space Network.";
    //// RenderData::HelpMarker(t_mp);

    style.FrameRounding = save_frame;
    style.GrabRounding = save_grab;

    ImGui::PopStyleColor();
    ImGui::End();
}
