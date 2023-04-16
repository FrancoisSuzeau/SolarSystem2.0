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
#include <vector>

/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace GUI {

		typedef struct imguiTexture_datas {

			int img_width;
			int img_height;
			GLuint text_id;
			std::string name;

		} imguiTexture_datas;

		

		class Menu
		{
			private:

				void renderNavigationTab();
				void renderPerformanceTab();
				void renderHUDTab();
				void HelpMarker(std::string sentence);
				std::vector<float> min_distance;

				std::map<std::string, bool>* m_bool_selection;
				std::map<std::string, float>* m_float_selection;
				std::map<std::string, int>* m_int_selection;

				std::vector<imguiTexture_datas> textures_data;

			public:
				Menu(std::map<std::string, bool>* bool_selection, std::map<std::string, float>* float_selection, std::map<std::string, int>* int_selection);
				~Menu();

				void render(int width, int height);
				void addImguiTextureData(imguiTexture_datas imgui_datas);
		};
	}
}


#endif