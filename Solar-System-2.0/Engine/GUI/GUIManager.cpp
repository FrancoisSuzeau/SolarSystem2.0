#include "GUIManager.hpp"

using namespace Engine::GUI;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
GUIManager::GUIManager() : m_menu(nullptr), m_hud(nullptr), m_music_infos()
{

}

GUIManager::~GUIManager()
{

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** initGUIs *****************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::initGUIs(std::map < std::string, std::string> map_info)
{
	if (m_menu == nullptr)
	{
		m_menu = new Menu();
		assert(m_menu);
		
	}

	if (m_hud == nullptr)
	{
		m_hud = new HUD();
		assert(m_hud);
		
	}

	menu_selection_value.insert(std::make_pair("quit", false));

	hud_music_selection.insert(std::make_pair("current_track", 0));
	hud_music_selection.insert(std::make_pair("volume", MIX_MAX_VOLUME / 2));
	hud_music_selection.insert(std::make_pair("pause", 0));

	m_music_infos.title = map_info["title"];
	m_music_infos.author = map_info["author"];
	m_music_infos.studio = map_info["studio"];
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** clean *****************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::clean()
{
	if (m_menu != nullptr)
	{
		delete m_menu;
		m_menu = nullptr;
	}

	if (m_hud != nullptr)
	{
		delete m_hud;
		m_hud = nullptr;
	}


}

/***********************************************************************************************************************************************************************/
/***************************************************************************** renderScreenLoad ************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::renderScreenLoad(float progress, std::string path)
{
	ImGuiWindowFlags window_flags = 0;
	ImGuiStyle& style = ImGui::GetStyle();
	float save_frame = style.FrameRounding;
	style.FrameRounding = 15;

	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_NoResize;
	window_flags |= ImGuiWindowFlags_NoBackground;
	window_flags |= ImGuiWindowFlags_NoScrollbar;

	ImGui::SetNextWindowPos(ImVec2(Engine::State::m_width / 2 - 50.f, Engine::State::m_height / 2 - 25.f));
	ImGui::SetNextWindowSize(ImVec2(100, 50.f));
	ImGui::Begin("Application name", NULL, window_flags);
	ImGui::Text("Solar System");
	ImGui::End();

	ImGui::SetNextWindowPos(ImVec2((Engine::State::m_width / 2 - 300), (Engine::State::m_height / 2 - 25.f) + 300));
	ImGui::SetNextWindowSize(ImVec2(600, 50.f));

	ImGui::Begin("Progress Bar", NULL, window_flags);
	ImGui::ProgressBar(progress, ImVec2(-1.f, -1.f));
	ImGui::End();

	ImGui::SetNextWindowPos(ImVec2(Engine::State::m_width / 2 - 250.f, (Engine::State::m_height / 2) + 350));
	ImGui::SetNextWindowSize(ImVec2(500, 200.f));
	ImGui::Begin("Log", NULL, window_flags);
	ImGui::Text(path.c_str());
	ImGui::End();
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* renderMenu **************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::renderMenu(bool render_menu)
{
	if (render_menu && m_menu != nullptr)
	{
		m_menu->render(Engine::State::m_width, Engine::State::m_height, menu_selection_value);
	}
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* renderHUD ***************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::renderHUD(bool render_overlay)
{
	if (render_overlay && m_hud != nullptr)
	{
		m_hud->renderApplicationHUD();
		m_hud->renderMusicHUD(Engine::State::m_width, Engine::State::m_height, hud_music_selection, m_music_infos);
	}
}

void Engine::GUI::GUIManager::changeMusicInfo(std::map<std::string, std::string> map_info)
{
	m_music_infos.title = map_info["title"];
	m_music_infos.author = map_info["author"];
	m_music_infos.studio = map_info["studio"];
}
