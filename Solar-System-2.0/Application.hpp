/*
AUTHOR : SUZEAU François

DATE : 26/05/2021

MODULE : Application

NAMEFILE : Application.hpp

PURPOSE : header of the Application class
*/

#ifndef APPLICATION_H
#define APPLICATION_H


/********************************************************************* preprocessing *********************************************************************/

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <cassert>
#include "Engine/State.hpp"
#include "DataManagementLayer/DataManager.hpp"
#include "Engine/EnginesManager.hpp"
#include "Engine/GUI/GUIManager.hpp"


/*
 
 #include "Settings/Settings.hpp"
 #include "Overlay/Overlay.hpp"


 #include "Camera/Camera.hpp"*/


 /********************************************************************* class definition *********************************************************************/

class Application
{

private:

	Engine::State* m_state;
	SDL_Window* m_window;
	DataManagementLayer::DataManager             m_data_manager;
	Uint32                  start_loop = 0, end_loop = 0, time_past = 0;
	unsigned int            frame_rate = 0;
	Engine::EnginesManager  m_engines_manager;
	float progress;

	void    manage_state();
	void    fpsCalculation(int moment);
	void loadModel(float& progress);
	void sendToEngine(float& progress, std::string text, std::string type);
	void initFrame();
	void endFrame();

	

	// //ParticuleManager *m_particule_manager;
	


	//Settings                m_setting;

	
	//Overlay                 m_overlay;
	//Camera* camera;


	//
	//void    renderOverlay();
	//
	//void    renderScene();
	//void    renderNameAndInfo();
	//void    makeAllChanges();
	//void    renderIntoFramebuffer(int type);
	//void    renderFlare();

public:

	Application(int width, int height, SDL_Window* window);
	~Application();

	void            loadAssets();
	void            initEngines();
	void            mainLoop();
	void            cleanAll();

	// void    renderInfo(RenderData &render_data);
	// void    renderParticles(RenderData &render_data);



};


#endif