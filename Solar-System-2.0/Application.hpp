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

        #if defined(IMGUI_IMPL_OPENGL_ES2)
        #include <SDL_opengles2.h>
        #else
        #include <SDL2/SDL_opengl.h>
        #endif


        #include "imgui.h"
        #include "imgui_impl_sdl.h"
        #include "imgui_impl_opengl3.h"

        #include "Engine/State.hpp"
        #include "DataManagementLayer/DataManager.hpp"
        #include "Engine/GUI/GUIManager.hpp"
        
        
       /* 
        #include "../InOut/Audio/Audio.hpp"
        #include "Settings/Settings.hpp"
        #include "Overlay/Overlay.hpp"

        #include "../Objects/BasicObjects/Square.hpp"
        #include "../Renderers/BasicRenderers/SquareRenderer.hpp"

        #include "../Skybox/Skybox.hpp"
        #include "../Objects/Spaceship/Spaceship.hpp"

        #include "../InOut/Framebuffer/Framebuffer.hpp"

        #include "System/SolarSystemCreator.hpp"
        

        #include "Camera/Camera.hpp"*/

        #define BEGIN   0
        #define END     1
        

/********************************************************************* class definition *********************************************************************/

    class Application
    {

        private:

            Engine::State m_state;
            SDL_Window* m_window;
            DataManagementLayer::DataManager             m_data_manager;
            Engine::GUI::GUIManager                     m_GUI_manager;
            Uint32                  start_loop = 0, end_loop, time_past = 0;
            unsigned int            frame_rate = 0;

            void    manage_state();
            void    fpsCalculation(int moment);
            void    manage_GUI();

            

            // Framebuffer     *m_framebuffer;

            // bool speed_key_pressed;
            // bool info_key_pressed;

            // //ParticuleManager *m_particule_manager;
            // bool is_moving;



            //SystemCreator* m_solar_system = nullptr;


            //Settings                m_setting;
            
            //Audio* m_audio;
            //Overlay                 m_overlay;
            //Skybox* m_skybox;
            //Camera* camera;
            //Spaceship* ship;

            //bool                    menu_app_key_pressed;
            //bool                    render_menu;


            //void    renderAudio();
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

            void            loadConfig();
            void            mainLoop();
            void            cleanAll();

            /*void          loadFrameBuffer();
            
            void            loadAssets();
            
           */

            // void    renderInfo(RenderData &render_data);
            // void    renderParticles(RenderData &render_data);



        };


#endif