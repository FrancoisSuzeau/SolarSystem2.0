/*
AUTHOR : SUZEAU François

DATE : 06/02/2021

MODULE : FlareManager

NAMEFILE : FlareManager.cpp

PURPOSE : class FlareManager
*/

#include "FlareManager.hpp"
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
FlareManager::FlareManager(/*SquareTexturedRenderer* square_textured_renderer, std::string const type*/) //: m_flares_type(type)
{
   // m_square_textured_renderer = square_textured_renderer;
   // spacing = 0.f;

   // if(m_flares_type == "cam_dirt")
   // {
   //     m_flares.push_back({new FlareTexture(0.8f, "flare_texture", "assets/textures/lensFlareTextures/tex8.png"), -0.53, 0.03f });
   //     m_flares.push_back({ new FlareTexture(0.3f, "flare_texture", "assets/textures/lensFlareTextures/Ghost2.png"), -0.51, 0.1 });
   //     m_flares.push_back({ new FlareTexture(0.3f, "flare_texture", "assets/textures/lensFlareTextures/Ghost2.png"), -0.49, 0.1 });
   //     m_flares.push_back({ new FlareTexture(0.3f, "flare_texture", "assets/textures/lensFlareTextures/Ghost2.png"), -0.47, 0.1 });
   //     m_flares.push_back({ new FlareTexture(0.3f, "flare_texture", "assets/textures/lensFlareTextures/Ghost2.png"), -0.45, 0.1 });
   //     m_flares.push_back({ new FlareTexture(0.5f, "flare_texture", "assets/textures/lensFlareTextures/Ghost1.png"), -0.43, 0.15 });
   //     m_flares.push_back({ new FlareTexture(0.5f, "flare_texture", "assets/textures/lensFlareTextures/tex4.png"), -0.4, 0.05});
   //     spacing = 0.4f;
   // }

   // if(m_flares_type == "sun_rays")
   // {
   //     m_flares.push_back({new FlareTexture(0.8f, "flare_texture", "assets/textures/lensFlareTextures/sunSpikes.png"), -1.f, 0.5 });
   //     // m_flares.push_back({new FlareTexture(0.33f, "flare_texture", "assets/textures/lensFlareTextures/Ghost2.png"), -0.2, 0.008});
   // }
   // 
   // 
   //
   //for(std::vector<flare_datas>::iterator it = m_flares.begin(); it != m_flares.end(); it++)
   //{
   //    assert(it[0].flare);
   //}
}

FlareManager::~FlareManager()
{

}

/***********************************************************************************************************************************************************************/
/**************************************************************************** renderLensFlare **************************************************************************/
/***********************************************************************************************************************************************************************/
//void FlareManager::clean()
//{
//    if((m_square_textured_renderer != nullptr) && (m_flares_type == "cam_dirt"))
//    {
//        m_square_textured_renderer->clean();
//        delete m_square_textured_renderer;
//        m_square_textured_renderer = nullptr;
//    }
//    for(std::vector<flare_datas>::iterator it = m_flares.begin(); it != m_flares.end(); it++)
//    {
//        if(it[0].flare != nullptr)
//        {
//            it[0].flare->clean();
//            delete it[0].flare;
//            it[0].flare = nullptr;
//        }
//    }
//}
//
///***********************************************************************************************************************************************************************/
///**************************************************************************** makeChanges **************************************************************************/
///***********************************************************************************************************************************************************************/
//void FlareManager::makeChanges(Applications::DataManager &data_manager)
//{
//    glm::vec2 sunScreenCoords = data_manager.convertToScreenSpace(data_manager.getSunPos());
//
//    glm::vec2 sunToCenter = glm::vec2(0.5f) - sunScreenCoords;
//    glm::vec2 flarePos = glm::vec2(0.0);
//
//    if(sunScreenCoords == glm::vec2(-100.f))
//    {
//        return;
//    }
//
//    if (m_flares_type == "cam_dirt")
//    {
//        float brightness = 1 - (glm::length(sunToCenter) / 0.6f);
//
//        if (brightness > 0)
//        {
//            int i = 0;
//            for (std::vector<flare_datas>::iterator it = m_flares.begin(); it != m_flares.end(); it++)
//            {
//                /*
//                    Just a reminder : we calculate the sun coord on the screen with origin at the left hight corner of the screen (with 0.5, 0.5 as the center)
//                    but the position of the m_flares are calculate with the OpenGL screen coord with origin in the center of the screen because of the lock on the view matrice
//                    so we had to substract 0.5 at each calculation of the flare position
//                */
//                glm::vec2 direction = glm::vec2(sunToCenter);
//                direction = direction * (i * spacing);
//                flarePos = glm::vec2(sunScreenCoords + direction - glm::vec2(0.5));
//                flarePos.x *= -1;
//
//                it[0].flare->updatePosition(glm::vec3(flarePos, it[0].depth_size));
//                it[0].flare->updateBrightness(brightness * it[0].strength);
//                it[0].flare->transform();
//                i++;
//            }
//        }
//    }
//    else if (m_flares_type == "sun_rays")
//    {
//
//        //std::cout << "pos.x : " << sunScreenCoords.x << std::endl;
//        std::cout << "pos.y : " << sunScreenCoords.y << std::endl;
//
//        for (std::vector<flare_datas>::iterator it = m_flares.begin(); it != m_flares.end(); it++)
//        {
//            it[0].flare->updatePosition(glm::vec3(sunScreenCoords.x - 0.9f, sunScreenCoords.y - 1.f, 0.f));
//            it[0].flare->updateBrightness(1.f * it[0].strength);
//            it[0].flare->transform();
//        }
//    }
//}
//
///***********************************************************************************************************************************************************************/
///**************************************************************************** renderLensFlare **************************************************************************/
///***********************************************************************************************************************************************************************/
//void FlareManager::renderLensFlare(Applications::DataManager &data_manager)
//{
//    glm::mat4 save_view_matrix = data_manager.getViewMat();
//
//        data_manager.lockView(glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f), glm::vec3(0.f, 1.f, 0.f));
//        
//        for(std::vector<flare_datas>::iterator it = m_flares.begin(); it != m_flares.end(); ++it)
//        {
//            if((it[0].flare != nullptr) && (m_square_textured_renderer != nullptr))
//            {
//                it[0].flare->sendToShader(data_manager);
//                m_square_textured_renderer->render(data_manager, it[0].flare);
//            }
//        }
//
//    data_manager.resetViewMat(save_view_matrix);
//}
