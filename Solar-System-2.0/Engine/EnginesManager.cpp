#include "EnginesManager.hpp"

using namespace Engine;



/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
EnginesManager::EnginesManager() : m_GUI_manager(), m_state(nullptr), m_framebuffer(), m_planete_renderer(nullptr), m_ring_renderer(nullptr), m_sphere_renderer(nullptr),
m_square_renderer(nullptr), m_solar_system(nullptr), m_skybox(nullptr), m_music_engine(), ancient_track(0), ancient_radio("Epic Orchestra")
,m_camera(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 1.f)), m_ship(nullptr), m_star_renderer(nullptr)
{

}

EnginesManager::~EnginesManager()
{

}

/***********************************************************************************************************************************************************************/
/************************************************************************* initDiscreteSimEngine ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::initDiscreteSimEngine(DataManagementLayer::DataManager data_manager)
{
	if (m_solar_system == nullptr)
	{
		assert(m_state);
		m_solar_system = new DiscreteSimulationEngine::SolarSystemCreator();
		assert(m_solar_system);
		bool success = m_solar_system->MakingSystem("Solar System", data_manager.getSunData(), m_state);
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
			m_planete_renderer = new RenderingEngine::PlaneteRenderer(1.f, 70, 70, m_state);
			assert(m_planete_renderer);
		}
		if (m_ring_renderer == nullptr)
		{
			m_ring_renderer = new RenderingEngine::RingRenderer();
			assert(m_ring_renderer);
		}
		if (m_sphere_renderer == nullptr)
		{
			m_sphere_renderer = new RenderingEngine::SphereRenderer(1.f, 70, 70, m_state);
			assert(m_sphere_renderer);
		}
		if (m_square_renderer == nullptr)
		{
			m_square_renderer = new RenderingEngine::SquareRenderer(1.f);
			assert(m_square_renderer);
		}
		if (m_star_renderer == nullptr)
		{
			m_star_renderer = new RenderingEngine::StarRenderer(1.f, 70, 70, m_state);
			assert(m_star_renderer);
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
	if (m_star_renderer != nullptr)
	{
		m_star_renderer->clean();
		delete m_star_renderer;
		m_star_renderer = nullptr;
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

	if (m_ship != nullptr)
	{
		m_ship->clean();
		delete m_ship;
		m_ship = nullptr;
	}
}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** manage_GUI ************************************************************************/
///***********************************************************************************************************************************************************************/
void EnginesManager::manageGUI(DataManagementLayer::DataManager data_manager)
{
	this->changeCurrentTrack(data_manager);
	this->correctIncrement("ship_index", data_manager.getNbSpaceships());
	if (m_GUI_manager.bool_selection->at("change_ship"))
	{
		if (m_ship != nullptr)
		{
			std::string path = data_manager.setAndGetSpaceshipPath(m_GUI_manager.int_selection->at("ship_index"));

			m_ship->clean();
			m_ship->buildModel(path, m_GUI_manager.int_selection->at("ship_index"));
			m_GUI_manager.int_selection->insert_or_assign("current_ship_index", m_GUI_manager.int_selection->at("ship_index"));
		}
		m_GUI_manager.bool_selection->insert_or_assign("change_ship", false);
	}

	if (m_state != nullptr)
	{
		m_GUI_manager.renderMenu(m_state->getRenderMenu());
		m_GUI_manager.renderHUD(m_state->getRenderOverlay());
		m_state->setTerminate(m_GUI_manager.bool_selection->at("quit"));
		m_state->setDistanceFromShip(m_GUI_manager.float_selection->at("distance_from_ship"));
		
	}

}

/***********************************************************************************************************************************************************************/
/**************************************************************************** changeCurrentTrack ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::changeCurrentTrack(DataManagementLayer::DataManager data_manager)
{
	std::string music_path = "NONE";
	std::string items[] = { "Epic Orchestra", "Citadel radio", "Retro Wave 86", "-Error Canal Transmission-" };
	if (ancient_track != m_GUI_manager.int_selection->at("current_track"))
	{
		int direction = (m_GUI_manager.int_selection->at("current_track") > ancient_track ? 1 : -1);
		while (music_path == "NONE")
		{
			this->correctIncrement("current_track", data_manager.getNbMusics());
			music_path = data_manager.setAndGetMusicPath(m_GUI_manager.int_selection->at("current_track"), items[m_GUI_manager.int_selection->at("current_radio")]);
			if (music_path != "NONE")
			{
				break;
			}
			else
			{
				int a = m_GUI_manager.int_selection->at("current_track") + direction;
				m_GUI_manager.int_selection->insert_or_assign("current_track", a);
			}
		}
		m_GUI_manager.changeMusicInfo(data_manager.getMusicInfo());
		ancient_track = m_GUI_manager.int_selection->at("current_track");
		m_state->setChangeTrack(true);
	}
}

void EnginesManager::correctIncrement(std::string key, int max)
{
	if (m_GUI_manager.int_selection->at(key) == max)
	{
		m_GUI_manager.int_selection->insert_or_assign(key, 0);
	}
	if (m_GUI_manager.int_selection->at(key) == -1)
	{
		m_GUI_manager.int_selection->insert_or_assign(key, max - 1);
	}
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** manageAudioEngine ************************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::manageAudioEngine(DataManagementLayer::DataManager data_manager)
{
	if (m_music_engine.getVolume() != m_GUI_manager.int_selection->at("volume"))
	{
		m_music_engine.changeVolume(m_GUI_manager.int_selection->at("volume"));
	}

	//the music is finish so the track has to be change so we increment the current track value, call the private methode to generate a new load form the json file
	//and the if block under this one will be called
	if (!m_music_engine.isMusicPlaying() && m_GUI_manager.bool_selection->at("pause") == false)
	{
		int a = m_GUI_manager.int_selection->at("current_track") + 1;
		m_GUI_manager.int_selection->insert_or_assign("current_track", a);
		this->changeCurrentTrack(data_manager);
	}

	std::string items[] = { "Epic Orchestra", "Citadel radio", "Retro Wave 86", "-Error Canal Transmission-" };
	
	if (ancient_radio != items[m_GUI_manager.int_selection->at("current_radio")])
	{
		if (items[m_GUI_manager.int_selection->at("current_radio")] != "-Error Canal Transmission-")
		{
			m_GUI_manager.int_selection->insert_or_assign("current_track", 0);
			this->changeCurrentTrack(data_manager);
		}
		
		ancient_radio = items[m_GUI_manager.int_selection->at("current_radio")];
	}

	//a user want to change the music or the music
	if (m_state->getChangeTrack())
	{
		m_music_engine.updateTrack(data_manager.getMusic());
		m_state->setChangeTrack(false);
	}
	m_music_engine.pause(m_GUI_manager.bool_selection->at("pause"));
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** addToEngine ************************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::addToEngine(float progress, std::string text, std::string type, DataManagementLayer::DataManager data_manager)
{
	if (type.compare("GUI") == 0)
	{
		m_GUI_manager.initGUIs();
		std::vector<DataManagementLayer::imgui_datas> tmp = data_manager.getImGuiTexture();
		for (std::vector<DataManagementLayer::imgui_datas>::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			m_GUI_manager.sendToGUI({it[0].img_width, it[0].img_height, it[0].text_id, it[0].name});
		}
	}
	if (type.compare("skybox") == 0)
	{
		if (m_skybox == nullptr)
		{
			std::vector<std::string> skybox_paths = data_manager.getSkyboxPath();
			m_skybox = new DiscreteSimulationEngine::Skybox(data_manager.getSkyboxTexture(skybox_paths));
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
		if (m_ship == nullptr)
		{
			m_ship = new DiscreteSimulationEngine::Objects::OpenGL::Spaceship("model", m_state);
			assert(m_ship);
			m_ship->buildModel(text, data_manager.getIfrom("spaceship"));
			m_camera.setShip(m_ship);
			m_GUI_manager.int_selection->insert_or_assign("ship_index", data_manager.getIfrom("spaceship"));
			m_GUI_manager.int_selection->insert_or_assign("current_ship_index", data_manager.getIfrom("spaceship"));
			m_GUI_manager.float_selection->insert_or_assign("distance_from_ship", m_state->getDistancteFromShip());
		}
	}
	if (type.compare("music") == 0)
	{
		m_GUI_manager.sendToGUI(data_manager.getMusicInfo());
		m_music_engine.updateTrack(data_manager.getMusic());
		ancient_track = data_manager.getIfrom("music");
		m_GUI_manager.int_selection->insert(std::make_pair("current_track", (ancient_track >= 0 ? ancient_track : 0)));
	}
	m_GUI_manager.renderScreenLoad(progress, text);
}

void EnginesManager::manageSkyboxShader()
{
	if (map_shader["skybox"] != nullptr && m_state->getPass() == COLOR_FBO)
	{
		glUseProgram(map_shader["skybox"]->getProgramID());
			glm::mat4 view = glm::mat4(glm::mat3(m_state->getViewMat()));
			map_shader["skybox"]->setMat4("view", view);
			map_shader["skybox"]->setMat4("projection", m_state->getProjMat());
			map_shader["skybox"]->setTexture("skybox", 0);
		glUseProgram(0);
	}
}

void EnginesManager::manageSpaceshipShader()
{
	if ((map_shader[m_ship->getType()] != nullptr) && (m_state->getPass() == COLOR_FBO))
	{
		glUseProgram(map_shader[m_ship->getType()]->getProgramID());
		map_shader[m_ship->getType()]->setMat4("projection", m_state->getProjMat());
		map_shader[m_ship->getType()]->setMat4("view", m_state->getViewMat());
		map_shader[m_ship->getType()]->setMat4(m_ship->getType(), m_ship->getModelMat());
		map_shader[m_ship->getType()]->setVec3("viewPos", m_state->getCamPos());
		map_shader[m_ship->getType()]->setVec3("sunPos", m_state->getSunPos());
		glUseProgram(0);
	}
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** makeAllChanges ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::manageShaders()
{
	if (m_skybox != nullptr)
	{
		this->manageSkyboxShader();
	}

	if (m_ship != nullptr)
	{
		this->manageSpaceshipShader();
	}
	
    /*
    

    std::vector<glm::mat4> shadowTransforms = m_data_manager.getLightSpaceMatrix();
    glUseProgram(m_data_manager.getShader("depth_map")->getProgramID());
        for(int i = 0; i < 6; ++i)
        {
            m_data_manager.getShader("depth_map")->setMat4("shadowMatrices[" + std::to_string(i) + "]", shadowTransforms[i]);
        }
        m_data_manager.getShader("depth_map")->setFloat("far_plane", m_data_manager.getFar());
        m_data_manager.getShader("depth_map")->setVec3("sunPos", m_data_manager.getSunPos());
    glUseProgram(0);*/
}

void EnginesManager::pushIntoFramebuffer(int type)
{
	    m_framebuffer.bindFramebuffer(type);
    
        if(m_state->getPass() == DEPTH_FBO)
        {
            glViewport(0, 0, State::m_width, State::m_width);
            glClear(GL_DEPTH_BUFFER_BIT);
            glCullFace(GL_FRONT);
        }
        else
        {
            glViewport(0, 0, State::m_width, State::m_height);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        /******************************************************************* RENDER SCENE *********************************************************************/
            this->renderScene();
        //======================================================================================================================================================

        if(m_state->getPass() == DEPTH_FBO)
        {
            glCullFace(GL_BACK);
            m_framebuffer.unbindFramebuffer();
        }
}

void EnginesManager::renderFrameBuffer()
{
	m_framebuffer.unbindFramebuffer();
	m_framebuffer.renderFrame(map_shader["blur"], map_shader["screen"], m_state->getBloomStrength(), m_state->getBloom());
}

void Engine::EnginesManager::changeView()
{
	m_state->listenEvents();
	m_camera.setDistFromShip(m_state->getDistancteFromShip());
	m_camera.move(m_state->getMouseInput(), m_state->getRenderMenu());
	m_state->setViewMat(m_camera.getViewMatrix());
	m_state->setCamPos(m_camera.getPosition());

	if (m_ship != nullptr)
	{
		if ((!m_state->getRenderMenu()))
		{
			m_ship->transform(glm::vec3(0.f));
			m_state->setShipPos(m_ship->getPosition());
			/*m_state->setShipOrientation(ship->getOrientation()); */
		}
	}

	if (m_solar_system != nullptr)
	{
		m_solar_system->makeChanges();
	}
}

void EnginesManager::renderScene()
{
	
    if(!m_state->getRenderMenu() && (m_state->getPass() == COLOR_FBO) && (map_shader[m_ship->getType()] != nullptr))
    {
        m_ship->render(map_shader[m_ship->getType()]);
    }
    if(m_skybox != nullptr)
    {
        m_skybox->render(map_shader["skybox"]->getProgramID());
    }

    if(m_solar_system != nullptr)
    {
		DiscreteSimulationEngine::Objects::OpenGL::Object* body = m_solar_system->getCelestialBody("sun");
		if ((body != nullptr) && (m_star_renderer != nullptr) && (m_state->getPass() == COLOR_FBO))
		{
			m_star_renderer->render(map_shader, body);
		}
        /*
		* m_solar_system->render(m_data_manager);
        m_solar_system->renderRing(m_data_manager);
        m_solar_system->renderAtmosphere(m_data_manager);*/
    }
}
