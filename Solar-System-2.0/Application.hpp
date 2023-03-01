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

        #include <iostream>
        #include <cassert>
        
        
       /* #include "DataManager.hpp"
        #include "../InOut/Input/Input.hpp"
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

            //DataManager             m_data_manager;

            // Framebuffer     *m_framebuffer;

            // bool speed_key_pressed;
            // bool info_key_pressed;

            // //ParticuleManager *m_particule_manager;
            // bool is_moving;



            //SystemCreator* m_solar_system = nullptr;

            
            //Input* m_input;
            //Settings                m_setting;
            //SDL_Window* m_window;
            //Audio* m_audio;
            //Overlay                 m_overlay;
            //Skybox* m_skybox;
            //Camera* camera;
            //Spaceship* ship;

            //bool                    menu_app_key_pressed;
            //bool                    render_menu;
            //unsigned int            frame_rate;
            //Uint32                  start_loop, end_loop, time_past;

            //void    inputProcess();
            //void    fpsCalculation(int moment);
            //void    renderAudio();
            //void    renderSettings();
            //void    renderOverlay();
            //void    renderScene();
            //void    renderNameAndInfo();
            //void    makeAllChanges();
            //void    renderIntoFramebuffer(int type);
            //void    renderFlare();

        public:

            Application(int width, int height, SDL_Window* window);
            ~Application();

            /*void            loadFrameBuffer();
            void            loadConfig();
            void            loadAssets();
            void            mainLoop();
            void            cleanAll();*/




            // void    renderInfo(RenderData &render_data);
            // void    renderParticles(RenderData &render_data);



        };


#endif