/*
AUTHOR : SUZEAU François

DATE : 18/03/2023

MODULE : Renderer::TexturedRenderers::StarRenderer

NAMEFILE : StarRenderer.cpp

PURPOSE : class StarRenderer

*/


#include "StarRenderer.hpp"
using namespace Engine::RenderingEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
StarRenderer::StarRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs, State* state) : super(radius, longSegs, latSegs, state)
{
    super::name = "STAR RENDERER";
}


StarRenderer::~StarRenderer()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** clean ********************************************************************************/
/***********************************************************************************************************************************************************************/
void StarRenderer::clean()
{
    super::clean();
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** render *******************************************************************************/
/***********************************************************************************************************************************************************************/
void StarRenderer::render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* star)
{
    GLuint t_id = star->getTextureID(0);
    if(glIsTexture(t_id) == GL_TRUE)
    {
        this->sendToShader(shader_map, star);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, t_id);

        super::render(shader_map, star);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
}

/***********************************************************************************************************************************************************************/
/************************************************************************** sendToShader *******************************************************************************/
/***********************************************************************************************************************************************************************/
void StarRenderer::sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* star)
{
    RenderingEngine::Shader* shader = shader_map.at(star->getType());
    if (shader != nullptr && m_state->getPass() == COLOR_FBO)
    {
        glUseProgram(shader->getProgramID());
        shader->setTexture("texture0", 0);
        shader->setInt("highlight", m_state->getHilightSun());
        glUseProgram(0);
    }

    super::sendToShader(shader_map, star);
}
