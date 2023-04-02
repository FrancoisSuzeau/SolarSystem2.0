/*
AUTHOR : SUZEAU François

DATE : 16/06/2021

MODULE : Objects::TexturedObjects::Star

NAMEFILE : Star.cpp

PURPOSE : class Star

*/



#include "Star.hpp"
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Star::Star(DataManagementLayer::body_data data) : super(data.size, "sun")
{
    super::surface_tex_ids.push_back(data.texture_surface_id);
    assert(super::surface_tex_ids[0] != 0);

    /*SquareTexturedRenderer  *square_textured_renderer = new SquareTexturedRenderer();
    assert(square_textured_renderer);*/

    /*m_flare_manager_cam_dirt = new FlareManager(square_textured_renderer, "cam_dirt");
    assert(m_flare_manager_cam_dirt);*/

   /* m_flare_manager_sun_ray = new FlareManager(square_textured_renderer, "sun_rays");
    assert(m_flare_manager_sun_ray);*/
}

Star::~Star()
{
    
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Star::clean()
{
    /*if(m_flare_manager_cam_dirt != nullptr)
    {
        m_flare_manager_cam_dirt->clean();
        delete m_flare_manager_cam_dirt;
        m_flare_manager_cam_dirt = nullptr;
    }*/

    /*if(m_flare_manager_sun_ray != nullptr)
    {
        m_flare_manager_sun_ray->clean();
        delete m_flare_manager_sun_ray;
        m_flare_manager_sun_ray = nullptr;
    }*/

    super::clean();
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** transform ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Star::transform(InputDevices::KeyInput key_input, InputDevices::MouseInput mouse_input, glm::vec3 ship_pos)
{
    super::transform(key_input, mouse_input, ship_pos);
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** sendToShader ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Star::sendToShader()
{
    /*if ((data_manager.getShader(super::m_type) != nullptr) && (data_manager.getPass() == COLOR_FBO))
    {
        glUseProgram(data_manager.getShader(super::m_type)->getProgramID());
        data_manager.getShader(super::m_type)->setTexture("texture0", 0);
        data_manager.getShader(super::m_type)->setInt("highlight", data_manager.getHilightSun());
        glUseProgram(0);
    }

    super::sendToShader(data_manager);*/
}

///***********************************************************************************************************************************************************************/
///************************************************************************** makeOtherChanges ***************************************************************************/
///***********************************************************************************************************************************************************************/
//void Star::makeOtherChanges(Applications::DataManager& data_manager)
//{
//    if (m_flare_manager_cam_dirt != nullptr)
//    {
//        m_flare_manager_cam_dirt->makeChanges(data_manager);
//    }
//
//    /*if (m_flare_manager_sun_ray != nullptr)
//    {
//        m_flare_manager_sun_ray->makeChanges(data_manager);
//    }*/
//}
//
///***********************************************************************************************************************************************************************/
///************************************************************************ renderFlare *******************************************************************************/
///***********************************************************************************************************************************************************************/
//void Star::renderFlares(Applications::DataManager &data_manager)
//{
//
//    if(m_flare_manager_cam_dirt != nullptr)
//    {
//        m_flare_manager_cam_dirt->renderLensFlare(data_manager);
//    }
//
//    /*if(m_flare_manager_sun_ray != nullptr)
//    {
//        m_flare_manager_sun_ray->renderLensFlare(data_manager);
//    }*/
//}