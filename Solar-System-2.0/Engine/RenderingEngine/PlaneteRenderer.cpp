/*
AUTHOR : SUZEAU François

DATE : 15/06/2021

MODULE : Renderer::TexturedRenderer::PlaneteRenderer

NAMEFILE : PlaneteRenderer.cpp

PURPOSE : class PlaneteRenderer
*/


#include "PlaneteRenderer.hpp"
using namespace Engine::RenderingEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
PlaneteRenderer::PlaneteRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs) : super(radius, longSegs, latSegs)
{
    super::name = "PLANETE RENDERER";
}

PlaneteRenderer::~PlaneteRenderer()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void PlaneteRenderer::clean()
{
    super::clean();
}

///***********************************************************************************************************************************************************************/
///******************************************************************************** render ******************************************************************************/
///***********************************************************************************************************************************************************************/
//void PlaneteRenderer::render(Applications::DataManager &data_manager, Object *planete)
//{
//    GLuint t_id = planete->getTextureID(0);
//    if(glIsTexture(t_id) == GL_TRUE)
//    {
//        planete->sendToShader(data_manager);
//        
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, t_id);
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_CUBE_MAP, data_manager.getDepthMapTexture());
//
//        glActiveTexture(GL_TEXTURE2);
//        glBindTexture(GL_TEXTURE_2D, planete->getNormalTextureID());
//
//        if((planete->getType() == "double_textured_planete") || (planete->getType() == "earth"))
//        {
//            glActiveTexture(GL_TEXTURE3);
//            glBindTexture(GL_TEXTURE_2D, planete->getTextureID(1));
//        }
//
//        if(planete->getType() == "earth")
//        {
//            glActiveTexture(GL_TEXTURE4);
//            glBindTexture(GL_TEXTURE_2D, planete->getTextureID(2));
//        }
//
//        super::render(data_manager, planete);
//
//        if(planete->getType() == "earth")
//        {
//            glActiveTexture(GL_TEXTURE4);
//            glBindTexture(GL_TEXTURE_2D, 0);
//        }
//
//        if((planete->getType() == "double_textured_planete") || (planete->getType() == "earth"))
//        {
//            glActiveTexture(GL_TEXTURE3);
//            glBindTexture(GL_TEXTURE_2D, 0);
//        }
//
//        glActiveTexture(GL_TEXTURE2);
//        glBindTexture(GL_TEXTURE_2D, 0);
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, 0);
//    }
//    
//}