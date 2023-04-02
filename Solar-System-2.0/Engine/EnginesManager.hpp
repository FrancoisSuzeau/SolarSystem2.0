/*
AUTHOR : SUZEAU François

DATE : 26/02/2023

MODULE : EnginesManager

NAMEFILE : EnginesManager.hpp

PURPOSE : header of the EnginesManager class
*/

#ifndef ENGINESMANAGER_H
#define ENGINESMANAGER_H


/*************************************************************************** includes ***********************************************************************/

#include "Framebuffer.hpp"
#include "PhysicsEngine.hpp"
#include "State.hpp"
#include "GUI/GUIManager.hpp"
#include "RenderingEngine/PlaneteRenderer.hpp"
#include "RenderingEngine/RingRenderer.hpp"
#include "DiscreteSimulationEngine/SolarSystemCreator.hpp"
#include "RenderingEngine/Shader.hpp"
#include "DiscreteSimulationEngine/Skybox.hpp"
#include "../DataManagementLayer/DataManager.hpp"
#include "AudioEngine/Music.hpp"
#include "Camera.hpp"
#include "DiscreteSimulationEngine/Objects/OpenGL/Spaceship.hpp"

#include <assimp/scene.h>


#define BEGIN   0
#define END     1


/********************************************************************* class definition *********************************************************************/

namespace Engine {


	class EnginesManager
	{
		private:

			GUI::GUIManager m_GUI_manager;
			State* m_state;
			Framebuffer m_framebuffer;
			DiscreteSimulationEngine::SystemCreator* m_solar_system;
			AudioEngine::Music m_music_engine;

			RenderingEngine::Renderer* m_planete_renderer;
			RenderingEngine::Renderer* m_ring_renderer;
			RenderingEngine::Renderer* m_sphere_renderer;
			RenderingEngine::Renderer* m_square_renderer;

			std::map<std::string, RenderingEngine::Shader*> map_shader;
			DiscreteSimulationEngine::Skybox *m_skybox;
			int ancient_track;
			std::string ancient_radio;
			Camera		m_camera;
			DiscreteSimulationEngine::Objects::OpenGL::Spaceship* m_ship;

			void changeCurrentTrack(DataManagementLayer::DataManager data_manager);
			void correctIncrement(std::string key, int max);
			void manageSkyboxShader();
			void manageSpaceshipShader();

			void renderScene();

		public:
			EnginesManager();
			~EnginesManager();

			void initRenderEngine(State* state, std::string function, float progress);
			void initDiscreteSimEngine(DataManagementLayer::DataManager data_manager);
			void addToEngine(float progress, std::string text, std::string type, DataManagementLayer::DataManager data_manager);

			void cleanAllEngines();

			void manageGUI(DataManagementLayer::DataManager data_manager);
			void manageAudioEngine(DataManagementLayer::DataManager data_manager);

			void manageShaders();

			void pushIntoFramebuffer(int type);
			void renderFrameBuffer();
			
			void changeView();

		};

}

#endif