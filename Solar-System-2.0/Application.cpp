/*
AUTHOR : SUZEAU François

DATE : 26/05/2021

MODULE : Application

NAMEFILE : Application.hpp

PURPOSE :   - creating OpenGL Context
            - Intialise all object of the scene
            - manage event and interaction
*/

#include "Application.hpp"

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Application::Application(int width, int height, SDL_Window *window): m_state(nullptr), m_window(window), m_data_manager(), m_engines_manager(), progress(0.f)
//m_setting(), m_overlay(), camera(nullptr)
{
    if (m_state == nullptr)
    {
        m_state = new Engine::State(width, height, 45.0);
        assert(m_state);

    }

    m_data_manager.setConfigs(m_state);
}

Application::~Application()
{

}

/***********************************************************************************************************************************************************************/
/*************************************************************************************** cleanAll **********************************************************************/
/***********************************************************************************************************************************************************************/
void Application::cleanAll()
{
    if (m_state != nullptr)
    {
        m_state->clean();
        delete m_state;
        m_state = nullptr;
    }

    m_data_manager.clean(PREFERENCE);
    m_data_manager.clean(BODIESDATA);
    m_data_manager.clean(SHADERSDATA);
    m_data_manager.clean(SPACESHIPSDATA);
    m_data_manager.clean(SKYBOXPATHS);

    m_engines_manager.cleanAllEngines();
    /*
    if(camera != nullptr)
    {
        delete camera;
        camera = nullptr;
    }

    m_setting.clean();
    m_overlay.clean();

    */
}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** initEngines ***********************************************************************/
///***********************************************************************************************************************************************************************/
void Application::initEngines()
{
    for (std::string function : {"createBuffers", "manageFramebuffers", "renderers"})
    {
        this->initFrame();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (m_state != nullptr)
        {
            m_engines_manager.initRenderEngine(m_state, function, progress / 87.f);
        }

        this->endFrame();
        //SDL_Delay(1500);
        progress++;
    }
    m_engines_manager.initDiscreteSimEngine();
    //SDL_Delay(1500);
}

///***********************************************************************************************************************************************************************/
///*************************************************************************************** startLoop *********************************************************************/
///***********************************************************************************************************************************************************************/
void Application::loadAssets()
{   
    int nb_bodies = m_data_manager.getNbBodies();
    int nb_shaders = m_data_manager.getNbShaders();
    int nb_musics = m_data_manager.getNbMusics();

    std::vector<std::string> skybox_paths = m_data_manager.getSkyboxPath();
    for (std::vector<std::string>::iterator it = skybox_paths.begin(); it != skybox_paths.end(); it++)
    {
        this->sendToEngine(progress, it[0], "skybox");
        progress++;
    }
    for (int current_load = 0; current_load < nb_bodies; current_load++)
    {
        for (std::string texture_type : {"surface", "cloud", "night", "normal"})
        {
            std::string path = m_data_manager.getTexturePath(current_load, texture_type);

            if (path.size() != 0)
            {
                this->sendToEngine(progress, path, "body_texture");
            }
            progress++;
        }
    }
    for (int current_load = 0; current_load < nb_shaders; current_load++)
    {
        m_data_manager.setShaderPaths(current_load);
        std::string text = "Currently loading " + m_data_manager.getShaderPaths()["name"] + " shader ...";
        this->sendToEngine(progress, text, "shader");
        progress++;
    }

    std::string spaceship_path = m_data_manager.setAndGetSpaceshipPath(m_state->getSpaceshipName());
    this->sendToEngine(progress, spaceship_path, "spaceship");
    progress++;

    std::string music_path = "NONE";
    int i = 0;
    while (music_path == "NONE")
    {
        music_path = m_data_manager.setAndGetMusicPath(i, "Epic Orchestra");
        if (music_path != "NONE")
        {
            break;
        }
        if (i == m_data_manager.getNbMusics() - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
    this->sendToEngine(progress, music_path, "music");
}


void Application::sendToEngine(float& progress, std::string text, std::string type)
{
    this->initFrame();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_engines_manager.addToEngine(progress / 88.f, text, type, m_data_manager);

    this->endFrame();
}

///***********************************************************************************************************************************************************************/
///*************************************************************************************** mainLoop **********************************************************************/
///***********************************************************************************************************************************************************************/
void Application::mainLoop()
{
    while(!m_state->getTerminate())
    {
            this->fpsCalculation(BEGIN);

                    /******************************************************************* MANAGING EVENTS ******************************************************************/
                        m_engines_manager.changeView();
                    //=====================================================================================================================================================
            
                    /******************************************************************* MANAGING CHANGES *****************************************************************/
                        m_engines_manager.makeAllChanges();
                    //=====================================================================================================================================================
            
                    /******************************************************************* RENDER AUDIO **********************************************************************/
                        m_engines_manager.manageAudioEngine(m_data_manager);
                    //======================================================================================================================================================
            
                    /******************************************************************* IMGUI PIPELINE ********************************************************************/
                        this->initFrame();
                    //======================================================================================================================================================

                        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                        glEnable(GL_BLEND);
                        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                    /******************************************************************* DEPTH MAP CALCULATION *************************************************************/
                        m_state->setPass(DEPTH_FBO);
                        m_engines_manager.pushIntoFramebuffer(DEPTH_FBO);
                    //======================================================================================================================================================
            
                    /******************************************************************* RENDER SYSTEM *********************************************************************/
                        m_state->setPass(COLOR_FBO);
                        m_engines_manager.pushIntoFramebuffer(COLOR_FBO);
                    //======================================================================================================================================================
            
                    /******************************************************************* RENDER SETTINGS *******************************************************************/
            //            this->renderSettings();
                    //======================================================================================================================================================
            
                    /******************************************************************* RENDER OVERLAY ********************************************************************/
            //            this->renderOverlay();
                        m_engines_manager.manageGUI(m_data_manager);
                    //======================================================================================================================================================
            
                    /******************************************************************* RENDER OVERLAY ********************************************************************/
            //            this->renderNameAndInfo();
                    //======================================================================================================================================================
            
                    /******************************************************************* RENDER FLARE ********************************************************************/
            //            this->renderFlare();
                    //======================================================================================================================================================
     
                        m_engines_manager.renderFrameBuffer();
            
                    /******************************************************************* SWAPPING WINDOWS *******************************************************************/
                        this->endFrame();
                    //=======================================================================================================================================================

            this->fpsCalculation(END);
    }
}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** fpsCalculation ********************************************************************/
///***********************************************************************************************************************************************************************/
void Application::fpsCalculation(int moment)
{
    switch (moment)
    {
        case BEGIN:
            start_loop = SDL_GetTicks();
            break;

        case END:
            end_loop = SDL_GetTicks();
            time_past = end_loop - start_loop;
            if (time_past < frame_rate)
            {
                SDL_Delay(frame_rate - time_past);
            }
            frame_rate = 1000 / m_state->getFps();
            break;

        default:
            break;
    }
}



/***********************************************************************************************************************************************************************/
/********************************************************************************** initFrame **************************************************************************/
/***********************************************************************************************************************************************************************/
void Application::initFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** endFrame **************************************************************************/
/***********************************************************************************************************************************************************************/
void Application::endFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(m_window);
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** renderScene ***********************************************************************/
/***********************************************************************************************************************************************************************/
//void Application::renderOverlay()
//{
//    if(m_data_manager.getRenderOverlay())
//    {
//        glm::mat4 save = m_data_manager.getViewMat();
//        m_data_manager.lockView(glm::vec3(0.0f, 0.0f, -1.1f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//        m_overlay.renderEdges(m_data_manager);
//        m_data_manager.resetViewMat(save);
//
//        m_overlay.renderAppInfo();
//
//        m_overlay.renderMusicInfo(m_data_manager);
//
//        //m_overlay->displayNavigation(render_data);
//    }
//}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** renderNameAndInfo *********************************************************************/
///***********************************************************************************************************************************************************************/
//void Application::renderNameAndInfo()
//{
//    m_solar_system->renderNameAndInfo(m_data_manager);
//}
//
///***********************************************************************************************************************************************************************/
///*********************************************************************************** renderFlare *********************************************************************/
///***********************************************************************************************************************************************************************/
//void Application::renderFlare()
//{
//    m_solar_system->renderFlareSun(m_data_manager);
//}

/***********************************************************************************************************************************************************************/
/********************************************************************************* renderParticles *********************************************************************/
/***********************************************************************************************************************************************************************/
// void Application::renderParticles(RenderData &render_data)
// {
//    if(m_particule_manager != nullptr)
//    {
//        m_particule_manager->renderParticules(render_data, ship, m_input);
//    }
// }