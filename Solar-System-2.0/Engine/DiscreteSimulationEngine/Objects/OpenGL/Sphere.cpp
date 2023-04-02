/*
AUTHOR : SUZEAU François

DATE : 06/06/2021

MODULE : Objects::BasicObjects

NAMEFILE : Sphere.cpp

PURPOSE : class Sphere
*/

//usefull macro for VBO
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((char*)0 + (offset))
#endif
#define VERT_NUM_FLOATS 8


#include "Sphere.hpp"

using namespace glm;
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/

Sphere::Sphere(float size, std::string const type) : super(type)
{
    super::m_size = glm::vec3(size);
    super::m_model_mat = glm::mat4(1.0);
}


Sphere::~Sphere()
{
   
}


/***********************************************************************************************************************************************************************/
/****************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Sphere::clean()
{
    super::clean();
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** transform ******************************************************************************/
/***********************************************************************************************************************************************************************/
void Sphere::transform(InputDevices::KeyInput key_input, InputDevices::MouseInput mouse_input, glm::vec3 ship_pos)
{
    super::m_model_mat = glm::mat4(1.0);

    super::translateObject(super::m_model_mat, (m_position + ship_pos));
    super::scaleObject(super::m_model_mat, super::m_size);
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** sendToShader ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Sphere::sendToShader()
{
    //switch (data_manager.getPass())
    //{
    //    // case DEPTH_FBO:
    //    //     if(data_manager.getShader("depth_map") != nullptr)
    //    //     {
    //    //         glUseProgram(data_manager.getShader("depth_map")->getProgramID());
    //    //             data_manager.getShader("depth_map")->setMat4("model", super::getModelMat());
    //    //         glUseProgram(0);
    //    //     }
    //    //     break;
    //    case COLOR_FBO:
    //        if(data_manager.getShader(super::m_type) != nullptr)
    //        {
    //            glUseProgram(data_manager.getShader(super::m_type)->getProgramID());
    //                data_manager.getShader(super::m_type)->setMat4("view", data_manager.getViewMat());
    //                data_manager.getShader(super::m_type)->setMat4("projection", data_manager.getProjMat());
    //                data_manager.getShader(super::m_type)->setMat4("model", super::getModelMat());
    //                data_manager.getShader(super::m_type)->setVec3("atmoColor", super::m_color_vector);
    //                data_manager.getShader(super::m_type)->setVec3("viewPos", data_manager.getCamPos());
    //                data_manager.getShader(super::m_type)->setVec3("sunPos", data_manager.getSunPos());
    //                // data_manager.getShader(super::super::m_type)->setInt("hdr", data_manager.getHDR());
    //            glUseProgram(0);
    //        }
    //        break;
    //    default:
    //        break;
    //}
}