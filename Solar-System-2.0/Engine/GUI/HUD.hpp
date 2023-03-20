/*
AUTHOR : SUZEAU Fran�ois

DATE : 02/03/2023

MODULE : HUD

NAMEFILE : HUD.hpp

PURPOSE : header of the HUD class
*/

#ifndef HUD_H
#define HUD_H

#define _CRT_SECURE_NO_WARNINGS


/*************************************************************************** includes ***********************************************************************/

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <ctime>
#include <string>
#include <map>


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace GUI {

		typedef struct music_info {

			std::string title;
			std::string author;
			std::string studio;

		} music_info;

		class HUD
		{
		private:


		public:
			HUD();
			~HUD();

			void renderApplicationHUD();
			void renderMusicHUD(int width, int height, std::map<std::string, int>& hud_music_selection, music_info infos);
		};
	}
}


#endif