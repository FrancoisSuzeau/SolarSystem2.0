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
	#include "DiscreteSimulation.hpp"
	#include "PhysicsEngine.hpp"
	#include "State.hpp"
	#include "GUI/GUIManager.hpp"
	#include "RenderingEngine/PlaneteRenderer.hpp"
	#include "RenderingEngine/RingRenderer.hpp"


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	class EnginesManager
	{
		private:

			GUI::GUIManager m_GUI_manager;
			State* m_state;
			Framebuffer m_framebuffer;

			RenderingEngine::Renderer* m_planete_renderer;
			RenderingEngine::Renderer* m_ring_renderer;
			RenderingEngine::Renderer* m_sphere_renderer;
			RenderingEngine::Renderer* m_square_renderer;

		public:
			EnginesManager();
			~EnginesManager();

			void initRenderEngine(State* state);
			void initGUIEngine();
			void cleanAllEngines();
			void manageGUI();
	};

}

#endif