/*
AUTHOR : SUZEAU François

DATE : 24/03/2022

MODULE : Renderer::TexturedRenderer::RingRenderer

NAMEFILE : RingRenderer.cpp

PURPOSE : class RingRenderer
*/


#include "RingRenderer.hpp"
using namespace Engine::RenderingEngine;

void RingRenderer::sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* ring)
{
}

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
RingRenderer::RingRenderer() : super(0.0)
{
    super::name = "RING RENDERER";
}

RingRenderer::~RingRenderer()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void RingRenderer::clean()
{
    super::clean();
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render ******************************************************************************/
/***********************************************************************************************************************************************************************/
void RingRenderer::render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* sphere)
{
    /*GLuint t_id = ring->getTextureID(0);
    if(glIsTexture(t_id) == GL_TRUE)
    {
        ring->sendToShader(data_manager);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, t_id);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_CUBE_MAP, data_manager.getDepthMapTexture());

        super::render(data_manager, ring);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }*/

}
