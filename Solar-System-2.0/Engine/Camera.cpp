/*
AUTHOR : SUZEAU François

DATE : 30/05/2021

MODULE : Application::Camera

NAMEFILE : Camera.cpp

PURPOSE : class Camera

*/

#include "Camera.hpp"
using namespace Engine;


/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Camera::Camera(glm::vec3 position, glm::vec3 target_point, glm::vec3 vertical_axe /*Spaceship* ship*/) :
m_vertical_axe(vertical_axe),
m_position(position), m_target_point(target_point), distance_from_ship(3.0f), angle_around_player(180.0f),
pitch(0.0f)
{
   /*if(ship != nullptr)
   {
       m_ship = ship;
   }*/
}

Camera::~Camera()
{
    
}
/***********************************************************************************************************************************************************************/
/********************************************************************************** calculatePitch *********************************************************************/
/***********************************************************************************************************************************************************************/
void Camera::calculatePitch(InputDevices::MouseInput mouse_input)
{
    if(mouse_input.getMouseButton(SDL_BUTTON_RIGHT))
    {
        float pitch_change = mouse_input.getYRel() * 0.5f;
        pitch += pitch_change;

        //limitate phi angle
        if(pitch > 89.0f)
        {
            pitch = 89.0f;
        }
        else if (pitch < -89.0f)
        {
            pitch = -89.0f;
        }
            
    }
}

/***********************************************************************************************************************************************************************/
/************************************************************************** calculateAngleAroundShip *******************************************************************/
/***********************************************************************************************************************************************************************/
void Camera::calculateAngleAroundShip(InputDevices::MouseInput mouse_input)
{
    if(mouse_input.getMouseButton(SDL_BUTTON_RIGHT))
    {
        float angle_change = mouse_input.getXRel() * 0.5f;
        angle_around_player -= angle_change;
    }
}

/***********************************************************************************************************************************************************************/
/************************************************************************** calculateHorizontalDistance*****************************************************************/
/***********************************************************************************************************************************************************************/
float Camera::calculateHorizontalDistance()
{
    //return (float) distance_from_ship * cos(glm::radians((m_ship->getRotY() - 90.0f + pitch)));
    return 0;
}

/***********************************************************************************************************************************************************************/
/*************************************************************************** calculateHorizontalDistance ***************************************************************/
/***********************************************************************************************************************************************************************/
float Camera::calculateVerticalDistance()
{
    //return (float) distance_from_ship * sin(glm::radians((m_ship->getRotY() - 90.0f + pitch)));
    return 0;
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** calculateCameraPosition ******************************************************************/
/***********************************************************************************************************************************************************************/
void Camera::calculateCameraPostion(float horizontal_distance, float vertical_distance)
{
    /*if(m_ship != nullptr)
    {
        float theta =  angle_around_player + m_ship->getRotX();
        float offset_x = (float) horizontal_distance * sin(glm::radians(theta));
        float offset_y = (float) horizontal_distance * -cos(glm::radians(theta));

        m_position.x = 0.0f + offset_x;
        m_position.y = 0.0f + offset_y;
        m_position.z = 0.0f + vertical_distance;

    }*/
    
}

/***********************************************************************************************************************************************************************/
/*************************************************************************************** move **************************************************************************/
/***********************************************************************************************************************************************************************/
void Camera::move(InputDevices::MouseInput mouse_input, bool move)
{   
    if(!move)
    {
        this->calculatePitch(mouse_input);
        this->calculateAngleAroundShip(mouse_input);
        float horizontal_distance = this->calculateHorizontalDistance();
        float vertical_distance = this->calculateVerticalDistance();
        this->calculateCameraPostion(horizontal_distance, vertical_distance);
    
        m_target_point = glm::vec3(0.0);
    }
}

/***********************************************************************************************************************************************************************/
/*************************************************************************************** correctTarget **************************************************************************/
/***********************************************************************************************************************************************************************/
//void Camera::correctTarget(InputDevices::MouseInput mouse_input)
//{
//    float correct_value_y = -cos(glm::radians(m_ship->getRotX()));
//    float correct_value_x = sin(glm::radians(m_ship->getRotX()));
//    float correct_value_z = cos(glm::radians(m_ship->getRotY()));
//    float speed = m_ship->getSpeed();
//
//    if(input->getKey(SDL_SCANCODE_W))
//    {
//        glm::vec3 to_add = glm::normalize(glm::vec3(correct_value_x, correct_value_y, correct_value_z));
//        m_target_point += to_add * speed;
//        m_position += to_add * speed;
//    }
//
//    if(input->getKey(SDL_SCANCODE_S))
//    {
//        glm::vec3 to_add = glm::normalize(glm::vec3(correct_value_x, correct_value_y, correct_value_z));
//        m_target_point -= to_add * speed;
//        m_position -= to_add * speed;
//    }
//
//    if(input->getKey(SDL_SCANCODE_A))
//    {
//        glm::vec3 to_cross = glm::cross(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(correct_value_x, correct_value_y, correct_value_z));
//        glm::vec3 to_add = glm::normalize(to_cross);
//        m_target_point += to_add * speed;
//        m_position += to_add * speed;
//    }
//
//    if(input->getKey(SDL_SCANCODE_D))
//    {
//        glm::vec3 to_cross = glm::cross(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(correct_value_x, correct_value_y, correct_value_z));
//        glm::vec3 to_add = glm::normalize(to_cross);
//        m_target_point -= to_add * speed;
//        m_position -= to_add * speed;
//    }
//
//    if(input->getKey(SDL_SCANCODE_LSHIFT))
//    {
//        glm::vec3 to_add = glm::normalize(glm::vec3(0.0f, 0.0f, m_ship->getSpeed()));
//        m_target_point += to_add * speed;
//        m_position += to_add * speed;
//    }
//    if(input->getKey(SDL_SCANCODE_LCTRL))
//    {
//        glm::vec3 to_add = glm::normalize(glm::vec3(0.0f, 0.0f, -m_ship->getSpeed()));
//        m_target_point += to_add * speed;
//        m_position += to_add * speed;
//    }
//}

/***********************************************************************************************************************************************************************/
/************************************************************************************* getViewMatrix **************************************************************************/
/***********************************************************************************************************************************************************************/
glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(m_position, m_target_point, m_vertical_axe);
}


/***********************************************************************************************************************************************************************/
/*********************************************************************************** getters/setters *******************************************************************/
/***********************************************************************************************************************************************************************/
void Camera::setDistFromShip(float const new_val)
{
    distance_from_ship = new_val;
}

glm::vec3 Camera::getPosition() const
{
    return m_position;
}

//void Camera::setShip(DiscreteSimulationEngine::Objects::OpenGL::Spaceship* ship)
//{
//    m_ship = ship;
//}
