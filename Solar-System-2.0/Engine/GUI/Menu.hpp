/*
AUTHOR : SUZEAU François

DATE : 02/03/2023

MODULE : Menu

NAMEFILE : Menu.hpp

PURPOSE : header of the Menu class
*/

#ifndef MENU_H
#define MENU_H


/*************************************************************************** includes ***********************************************************************/

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <string>
#include <map>


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace GUI {

		

		class Menu
		{
			private:

			public:
				Menu();
				~Menu();

				void render(int width, int height, std::map<std::string, bool> &menu_selection_value);
				
		};
	}
}


#endif