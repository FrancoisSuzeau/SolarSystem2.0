/*
AUTHOR : SUZEAU François

DATE : 14/05/2022

MODULE : Renderer::TexturedRenderer::SquareTexturedRenderer

NAMEFILE : SquareTexturedRenderer.cpp

PURPOSE : class SquareTexturedRenderer
*/


#include "SquareTexturedRenderer.hpp"
using namespace Engine::RenderingEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
SquareTexturedRenderer::SquareTexturedRenderer() : super(0.0)
{
    super::name = "SQUARE TEXTURED RENDERER";
}

SquareTexturedRenderer::~SquareTexturedRenderer()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void SquareTexturedRenderer::clean()
{
    super::clean();
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render ******************************************************************************/
/***********************************************************************************************************************************************************************/
void SquareTexturedRenderer::render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* sphere)
{
    /*GLuint t_id = FlareTexture->getTextureID(0);
    if(glIsTexture(t_id) == GL_TRUE)
    {
        FlareTexture->sendToShader(data_manager);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, t_id);

        super::render(data_manager, FlareTexture);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }*/

}
