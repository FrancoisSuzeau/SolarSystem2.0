/*
AUTHOR : SUZEAU François

DATE : 27/11/2021

MODULE : CelestialBody.Planete

NAMEFILE : Planete.cpp

PURPOSE : class Planete
*/


#include "Planete.hpp"
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Planete::Planete(DataManagementLayer::body_data data) : super(data.size, "Planete"), m_oppacity(data.oppacity), light_strength(data.light_strength), m_name(data.name)
{
    super::m_shininess = data.shininess;
    super::m_rotation_angle = 0.f;
    super::m_speed_rotation = 0.1f;
    super::m_position = data.current_position;
    super::m_inclinaison_angle = data.inclinaison_angle;
    super::normal_texture_id = data.texture_normal_id;
    super::surface_tex_ids.push_back(data.texture_surface_id);
    super::surface_tex_ids.push_back(data.texture_cloud_id);
    super::surface_tex_ids.push_back(data.texture_night_id);

    /*

    

    if(m_name == "Venus")
    {
        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(1.f, 1.f, 224.f/255.f));
    }
    if(m_name == "Earth")
    {
        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(147.f/255.f, 188.f/255.f, 251.f/255.f));
    }
    if(m_name == "Mars")
    {
        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(255.f/255.f, 228.f/255.f, 225.f/255.f));
    }
    if(m_name == "Jupiter")
    {
        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(255.f/255.f, 228.f/255.f, 196.f/255.f));
    }
    if(m_name == "Saturn")
    {
        std::vector<std::string> texture_path;
        texture_path.push_back("assets/textures/CelestialBody/SaturnRing.png");
        m_ring = new Ring(25.f,  texture_path, "ring", 32, super::m_inclinaison_angle);
        assert(m_ring);

        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(255.f/255.f, 235.0/255.f, 205.f/255.f));
    }
    if(m_name == "Titan")
    {
        m_atmosphere = new Sphere(datas.size + 0.04f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(253.f/255.f, 241.0/255.f, 184.f/255.f));
    }

    if(m_name == "Uranus")
    {
        std::vector<std::string> texture_path;
        texture_path.push_back("assets/textures/CelestialBody/UranusRing.png");
        m_ring = new Ring(25.f,  texture_path, "ring", 32, super::m_inclinaison_angle);
        assert(m_ring);

        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(173.f/255.f, 216.f/255.f, 230.f/255.f));
    }

    if(m_name == "Neptune")
    {
        std::vector<std::string> texture_path;
        texture_path.push_back("assets/textures/CelestialBody/UranusRing.png");
        m_ring = new Ring(25.f,  texture_path, "ring", 32, super::m_inclinaison_angle);
        assert(m_ring);

        m_atmosphere = new Sphere(datas.size + 0.2f, "atmosphere");
        assert(m_atmosphere);
        m_atmosphere->updateColor(glm::vec3(65.f/255.f, 105.f/255.f, 255.f/255.f));
    }*/
}

Planete::~Planete()
{

}

float Planete::getLightStrength() 
{
    return light_strength;
}

float Planete::getOppacity() 
{
    return m_oppacity;
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Planete::clean()
{
    /*if(m_ring != nullptr)
    {
        m_ring->clean();
        delete m_ring;
        m_ring = nullptr;
    }
    if(m_atmosphere != nullptr)
    {
        m_atmosphere->clean();
        delete m_atmosphere;
        m_atmosphere = nullptr;
    }*/

    super::clean();
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** transform ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Planete::transform(glm::vec3 ship_pos)
{
    super::transform(ship_pos);

    super::inclineObject(super::m_model_mat, super::m_inclinaison_angle);

    super::m_rotation_angle += super::m_speed_rotation;
    if(super::m_rotation_angle >= 360)
    {
        super::m_rotation_angle -= 360;
    }
    super::rotateObject(super::m_model_mat, super::m_rotation_angle);
}

///***********************************************************************************************************************************************************************/
///****************************************************************************** makeOtherChanges *************************************************************************/
///***********************************************************************************************************************************************************************/
//void Planete::makeOtherChanges(Applications::DataManager& data_manager)
//{
//    if (m_ring != nullptr)
//    {
//        m_ring->updatePosition(super::getPosition());
//        m_ring->transform(-data_manager.getShipPos());
//    }
//
//    if (m_atmosphere != nullptr)
//    {
//        m_atmosphere->updatePosition(super::getPosition());
//        m_atmosphere->transform(-data_manager.getShipPos());
//    }
//}
//
///***********************************************************************************************************************************************************************/
///****************************************************************************** renderName *************************************************************************/
///***********************************************************************************************************************************************************************/
//void Planete::renderName(Applications::DataManager &data_manager)
//{
//    if(data_manager.getRenderName())
//    {
//        glm::vec2 planete_screen_position = data_manager.convertToScreenSpace(this->m_position - data_manager.getShipPos());
//
//        ImGuiWindowFlags window_flags = 0;
//            
//        window_flags |= ImGuiWindowFlags_NoTitleBar;
//        window_flags |= ImGuiWindowFlags_NoResize;
//        window_flags |= ImGuiWindowFlags_NoBackground;
//        window_flags |= ImGuiWindowFlags_NoScrollbar;
//
//        ImGui::SetNextWindowPos(ImVec2((data_manager.getWidth() * planete_screen_position.x) - 30, 
//                                            (data_manager.getHeight() * planete_screen_position.y) - 70));
//        ImGui::SetNextWindowSize(ImVec2(100.f, 80.f));
//
//        ImGui::Begin(this->m_name.c_str(), NULL, window_flags);
//        ImGui::Text(this->m_name.c_str());
//        ImGui::End();
//    }
//    
//    
//}
//
//// /***********************************************************************************************************************************************************************/
//// /********************************************************************************** getters ****************************************************************************/
//// /***********************************************************************************************************************************************************************/
//Ring* Planete::getRing() const
//{
//    return m_ring;
//}
//
//Sphere* Planete::getAmosphere() const
//{
//    return m_atmosphere;
//}