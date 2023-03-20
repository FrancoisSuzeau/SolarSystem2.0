/*
AUTHOR : SUZEAU Fran�ois

DATE : 13/03/2021

MODULE : Music

NAMEFILE : Music.hpp*/


#include "Music.hpp"
using namespace Engine::AudioEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Music::Music() : m_music(NULL), m_ancient_volume(0)
{

}

Music::~Music()
{

}

/***********************************************************************************************************************************************************************/
/********************************************************************************* clean ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Music::clean()
{
    Mix_HaltMusic();
    if (m_music != NULL)
    {
        Mix_FreeMusic(m_music);
    }

    std::cout << ">> Music : DESTROY COMPLETE" << std::endl;
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* manage music ************************************************************************/
/***********************************************************************************************************************************************************************/
void Music::playMusic() const
{
    /************************************************* launch playlist ********************************************************/
    if (Mix_PlayMusic(m_music, 0) == -1)
    {
        std::string err_msg = "Playing music : ";
        err_msg.append(Mix_GetError());
        //showError(nullptr, ErrorHandler(err_msg.c_str()), __FILENAME__, __FUNCTION__, __LINE__);
        std::cout << err_msg << std::endl;
    }
    //===================================================================================================================
}

void Music::pause(bool pause)
{
    if (pause)
    {
        if (Mix_PausedMusic() == 0)
        {
            Mix_PauseMusic();
        }
    }
    else
    {
        if (Mix_PausedMusic() == 1)
        {
            Mix_ResumeMusic();
        }
    }
}

void Music::changeVolume(int volume)
{
    Mix_VolumeMusic(volume);
    m_ancient_volume = volume;
}

int Music::getVolume() const
{
    return m_ancient_volume;
}

bool Music::isMusicPlaying() const
{
    return Mix_PlayingMusic() == 1;
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* updateTrack *************************************************************************/
/***********************************************************************************************************************************************************************/
void Music::updateTrack(Mix_Music* music)
{
    if (m_music != NULL)
    {
        this->clean();
    }

    m_music = music;
    this->playMusic();
}