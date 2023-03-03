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

	#include "RenderingEngine/Framebuffer.hpp"
	#include "DiscreteSimulation.hpp"
	#include "PhysicsEngine.hpp"
	#include "State.hpp"
	#include "GUI/GUIManager.hpp"


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	class EnginesManager
	{
		private:

			GUI::GUIManager m_GUI_manager;
			State* m_state;
			RenderingEngine::Framebuffer m_framebuffer;

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