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
void Sphere::transform(glm::vec3 ship_pos)
{
    super::m_model_mat = glm::mat4(1.0);

    super::translateObject(super::m_model_mat, (m_position + ship_pos));
    super::scaleObject(super::m_model_mat, super::m_size);
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** sendToShader ***************************************************************************/
/***********************************************************************************************************************************************************************/
//void Sphere::sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map)
//{
//    RenderingEngine::Shader* shader = shader_map.at(super::m_type);
//    switch (m_state->getPass())
//    {
//        case COLOR_FBO:
//            if(shader != nullptr)
//            {
//                glUseProgram(shader->getProgramID());
//                    shader->setMat4("view", m_state->getViewMat());
//                    shader->setMat4("projection", m_state->getProjMat());
//                    shader->setMat4("model", super::getModelMat());
//                    shader->setVec3("atmoColor", super::m_color_vector);
//                    shader->setVec3("viewPos", m_state->getCamPos());
//                    shader->setVec3("sunPos", m_state->getSunPos());
//                glUseProgram(0);
//            }
//            break;
//        default:
//            break;
//    }
//}