/*
AUTHOR : SUZEAU François

DATE : 02/03/2023

MODULE : GUIManager

NAMEFILE : GUIManager.hpp

PURPOSE : header of the GUIManager class
*/

#ifndef GUIMANAGER_H
#define GUIMANAGER_H


/*************************************************************************** includes ***********************************************************************/

	#if defined(IMGUI_IMPL_OPENGL_ES2)
	#include <SDL_opengles2.h>
	#else
	#include <SDL2/SDL_opengl.h>
	#endif
	#include "imgui.h"
	#include "imgui_impl_sdl.h"
	#include "imgui_impl_opengl3.h"

	#include "../State.hpp"
	#include "Menu.hpp"
	#include "HUD.hpp"

	#include <map>
	#include <string>


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace GUI {

		

		class GUIManager
		{
			private:

				Menu *m_menu;
				HUD* m_hud;
				std::map<std::string, bool> menu_selection_value;

				

			public:
				GUIManager();
				~GUIManager();

				void initGUIs();
				void clean();

				static void renderScreenLoad(int assets_loaded);
				void renderMenu(bool render_menu);
				void renderHUD(bool render_overlay);
				void applyUserChoice(Engine::State* state);
		};
	}
}


#endif