#include "GUIManager.hpp"

using namespace Engine::GUI;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
GUIManager::GUIManager() : m_menu(nullptr), m_hud(nullptr), m_music_infos(), bool_selection(nullptr), float_selection(nullptr), int_selection(nullptr)
{
	
}

GUIManager::~GUIManager()
{

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** initGUIs *****************************************************************************/
/***********************************************************************************************************************************************************************/
void GUIManager::sendToGUI(std::map < std::string, std::string> map_info)
{
	
	m_music_infos.title = map_info["title"];
	m_music_infos.author = map_info["author"];
	m_music_infos.studio = map_info["studio"];
}

void GUIManager::sendToGUI(imguiTexture_datas imgui_datas)
{
	if (m_menu != nullptr)
	{
		m_menu->addImguiTextureData(imgui_datas);
	}
}

void GUIManager::initGUIs()
{
	if (bool_selection == nullptr)
	{
		bool_selection = new std::map<std::string, bool>;
		assert(bool_selection);
		bool_selection->insert(std::make_pair("quit", false));
		bool_selection->insert(std::make_pair("save", false));
		bool_selection->insert(std::make_pair("pause", false));
		bool_selection->insert(std::make_pair("change_ship", false));
	}


	if (float_selection == nullptr)
	{
		float_selection = new std::map<std::string, float>;
		assert(float_selection);
		float_selection->insert(std::make_pair("distance_from_ship", 0.f));
	}


	if (int_selection == nullptr)
	{
		int_selection = new std::map<std::string, int>;
		assert(int_selection);
		int_selection->insert(std::make_pair("current_track", 0));
		int_selection->insert(std::make_pair("volume", MIX_MAX_VOLUME / 2));
		int_selection->insert(std::make_pair("current_radio", 0));
		int_selection->insert(std::make_pair("ship_index", 0));
		int_selection->insert(std::make_pair("current_ship_index", 0));
	}

	if (m_menu == nullptr)
	{
		m_menu = new Menu(bool_selection, float_selection, int_selection);
		assert(m_menu);
	}

	if (m_hud == nullptr)
	{
		m_hud = new HUD(bool_selection, float_selection, int_selection);
		assert(m_hud);
	}
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
		m_menu->render(Engine::State::m_width, Engine::State::m_height);
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
		m_hud->renderMusicHUD(Engine::State::m_width, Engine::State::m_height, m_music_infos);
	}
}

void Engine::GUI::GUIManager::changeMusicInfo(std::map<std::string, std::string> map_info)
{
	m_music_infos.title = map_info["title"];
	m_music_infos.author = map_info["author"];
	m_music_infos.studio = map_info["studio"];
}