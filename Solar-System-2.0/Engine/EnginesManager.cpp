#include "EnginesManager.hpp"

using namespace Engine;



/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
EnginesManager::EnginesManager() : m_GUI_manager(), m_state(nullptr), m_framebuffer(), m_planete_renderer(nullptr), m_ring_renderer(nullptr), m_sphere_renderer(nullptr),
m_square_renderer(nullptr), m_solar_system(nullptr), m_skybox(nullptr), m_music_engine(), ancient_track(0)
{

}

EnginesManager::~EnginesManager()
{

}

/***********************************************************************************************************************************************************************/
/************************************************************************* initDiscreteSimEngine ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::initDiscreteSimEngine()
{
	if (m_solar_system == nullptr)
	{
		m_solar_system = new DiscreteSimulationEngine::SolarSystemCreator();
		assert(m_solar_system);
		bool success = m_solar_system->MakingSystem("Solar System");
		assert(success);
	}
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** initRenderEngine ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::initRenderEngine(State* state, std::string function, float progress)
{
	if (function.compare("createBuffers") == 0)
	{
		m_state = state;
		m_GUI_manager.renderScreenLoad(progress, "Asking system to give resources to OpenGL ...");
		m_framebuffer.createBuffers(State::m_width, State::m_height);
	}
	if (function.compare("manageFramebuffers") == 0)
	{
		m_GUI_manager.renderScreenLoad(progress, "Configuring frames: so far so good ...");
		m_framebuffer.manageFramebuffers(State::m_width, State::m_height);
	}
	if (function.compare("renderers") == 0)
	{
		m_GUI_manager.renderScreenLoad(progress, "Summoning the renderers ...");
		if (m_planete_renderer == nullptr)
		{
			m_planete_renderer = new RenderingEngine::PlaneteRenderer(1.f, 70.f, 70.f);
			assert(m_planete_renderer);
		}
		if (m_ring_renderer == nullptr)
		{
			m_ring_renderer = new RenderingEngine::RingRenderer();
			assert(m_ring_renderer);
		}
		if (m_sphere_renderer == nullptr)
		{
			m_sphere_renderer = new RenderingEngine::SphereRenderer(1.f, 70.f, 70.f);
			assert(m_sphere_renderer);
		}
		if (m_square_renderer == nullptr)
		{
			m_square_renderer = new RenderingEngine::SquareRenderer(1.f);
			assert(m_square_renderer);
		}
	}

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** cleanAllEngines **********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::cleanAllEngines()
{
	m_GUI_manager.clean();
	m_framebuffer.clean();
	m_music_engine.clean();

	if (m_skybox != nullptr)
	{
		m_skybox->clean();
		delete m_skybox;
		m_skybox = nullptr;
	}

	if (m_planete_renderer != nullptr)
	{
		m_planete_renderer->clean();
		delete m_planete_renderer;
		m_planete_renderer = nullptr;
	}
	if (m_ring_renderer != nullptr)
	{
		m_ring_renderer->clean();
		delete m_ring_renderer;
		m_ring_renderer = nullptr;
	}
	if (m_sphere_renderer != nullptr)
	{
		m_sphere_renderer->clean();
		delete m_sphere_renderer;
		m_sphere_renderer = nullptr;
	}
	if (m_square_renderer != nullptr)
	{
		m_square_renderer->clean();
		delete m_square_renderer;
		m_square_renderer = nullptr;
	}

	if (m_solar_system != nullptr)
	{
		m_solar_system->cleanSystem();
		delete m_solar_system;
		m_solar_system = nullptr;
	}
	for (std::map<std::string, RenderingEngine::Shader*>::iterator it = map_shader.begin(); it != map_shader.end(); ++it)
	{
		if (it->second != nullptr)
		{
			it->second->clean();
			delete it->second;
			it->second = nullptr;
		}
	}
}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** manage_GUI ************************************************************************/
///***********************************************************************************************************************************************************************/
void EnginesManager::manageGUI(DataManagementLayer::DataManager data_manager)
{
	if (m_state != nullptr)
	{
		m_GUI_manager.renderMenu(m_state->getRenderMenu());
		m_GUI_manager.renderHUD(m_state->getRenderOverlay());
		m_state->setTerminate(m_GUI_manager.menu_selection_value["quit"]);
	}

	this->changeCurrentTrack(data_manager);

}

/***********************************************************************************************************************************************************************/
/**************************************************************************** changeCurrentTrack ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::changeCurrentTrack(DataManagementLayer::DataManager data_manager)
{
	if (ancient_track != m_GUI_manager.hud_music_selection["current_track"])
	{
		if (m_GUI_manager.hud_music_selection["current_track"] == data_manager.getNbMusics())
		{
			m_GUI_manager.hud_music_selection["current_track"] = 0;
		}
		if (m_GUI_manager.hud_music_selection["current_track"] == -1)
		{
			m_GUI_manager.hud_music_selection["current_track"] = data_manager.getNbMusics() - 1;
		}
		data_manager.setAndGetMusicPath(m_GUI_manager.hud_music_selection["current_track"]);
		m_GUI_manager.changeMusicInfo(data_manager.getMusicInfo());
		ancient_track = m_GUI_manager.hud_music_selection["current_track"];
		m_state->setChangeTrack(true);
	}
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** manageAudioEngine ************************************************************************/
/***********************************************************************************************************************************************************************/
void Engine::EnginesManager::manageAudioEngine(DataManagementLayer::DataManager data_manager)
{
	if (m_music_engine.getVolume() != m_GUI_manager.hud_music_selection["volume"])
	{
		m_music_engine.changeVolume(m_GUI_manager.hud_music_selection["volume"]);
	}

	//the music is finish so the track has to be change so we increment the current track value, call the private methode to generate a new load form the json file
	//and the if block under this one will be called
	if (!m_music_engine.isMusicPlaying() && m_GUI_manager.hud_music_selection["pause"] == 0)
	{
		m_GUI_manager.hud_music_selection["current_track"]++;
		this->changeCurrentTrack(data_manager);
	}

	//a user want to change the music or the music
	if (m_state->getChangeTrack())
	{
		m_music_engine.updateTrack(data_manager.getMusic());
		m_state->setChangeTrack(false);
	}
	m_music_engine.pause(m_GUI_manager.hud_music_selection["pause"] == 1);
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** addToEngine ************************************************************************/
/***********************************************************************************************************************************************************************/
void Engine::EnginesManager::addToEngine(float progress, std::string text, std::string type, DataManagementLayer::DataManager data_manager)
{
	if (type.compare("skybox") == 0)
	{
		if (m_skybox == nullptr)
		{
			m_skybox = new DiscreteSimulationEngine::Skybox(data_manager.getSkyboxTexture());
		}
	}
	if (type.compare("body_texture") == 0)
	{
		//data_manager.getTextureId(text);
		//m_solar_system->loadSystem();
	}
	if (type.compare("shader") == 0)
	{
		std::map < std::string, std::string> mapp = data_manager.getShaderPaths();
		map_shader.insert({mapp["name"], new RenderingEngine::Shader(mapp["v_path"],
			mapp["f_path"], mapp["g_path"])});
		assert(map_shader[mapp["name"]]);
		bool success = map_shader[mapp["name"]]->loadShader();
		assert(success);
	}
	if (type.compare("spaceship") == 0)
	{
		//data_manager.getBlenderModel(text);
	}
	if (type.compare("music") == 0)
	{
		m_GUI_manager.initGUIs(data_manager.getMusicInfo());
		m_music_engine.updateTrack(data_manager.getMusic());

	}
	
	m_GUI_manager.renderScreenLoad(progress, text);
}