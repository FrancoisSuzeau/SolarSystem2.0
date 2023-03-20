/*
AUTHOR : SUZEAU François

DATE : 13/03/2022

MODULE : Music

NAMEFILE : Music.hpp

PURPOSE : header of the Music class
*/

#ifndef MUSIC_H
#define MUSIC_H


/********************************************************************* includes *********************************************************************/
#include <iostream>
#include <SDL2/SDL_mixer.h>


/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace AudioEngine {

		class Music
		{

		private:

			Mix_Music* m_music;

			void playMusic() const;
			int m_ancient_volume;



		public:

			Music();
			~Music();

			void    clean();
			void pause(bool pause);

			void updateTrack(Mix_Music *music);
			void changeVolume(int volume);
			int getVolume() const;
			bool isMusicPlaying() const;
		};
	}

}

#endif