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
PlaneteRenderer::PlaneteRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs, State* state) : super(radius, longSegs, latSegs, state)
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

/***********************************************************************************************************************************************************************/
/******************************************************************************** render ******************************************************************************/
/***********************************************************************************************************************************************************************/
void PlaneteRenderer::render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* planete)
{
	GLuint t_id = planete->getTextureID(0);
	if(glIsTexture(t_id) == GL_TRUE)
	{

		this->sendToShader(shader_map, planete);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, t_id);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_state->getDepthMapTexture());

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, planete->getNormalTextureID());

		if((planete->getType() == "double_textured_planete") || (planete->getType() == "earth"))
		{
			glActiveTexture(GL_TEXTURE3);
			glBindTexture(GL_TEXTURE_2D, planete->getTextureID(1));
		}

		if(planete->getType() == "earth")
		{
			glActiveTexture(GL_TEXTURE4);
			glBindTexture(GL_TEXTURE_2D, planete->getTextureID(2));
		}

		super::render(shader_map, planete);

		if(planete->getType() == "earth")
		{
			glActiveTexture(GL_TEXTURE4);
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		if((planete->getType() == "double_textured_planete") || (planete->getType() == "earth"))
		{
			glActiveTexture(GL_TEXTURE3);
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}

void PlaneteRenderer::sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* planete)
{
	Shader* shader = shader_map.at(planete->getType());
	if ((shader_map.at("depth_map") != nullptr) && (m_state->getPass() == DEPTH_FBO))
	{
		glUseProgram(shader_map.at("depth_map")->getProgramID());
		shader_map.at("depth_map")->setMat4("model", planete->getModelMat());
		glUseProgram(0);
	}
	if ((shader != nullptr) && (m_state->getPass() == COLOR_FBO))
	{
		glUseProgram(shader->getProgramID());
		shader->setVec3("viewPos", m_state->getCamPos());
		shader->setVec3("sunPos", m_state->getSunPos());
		shader->setTexture("material.surface", 0);
		shader->setTexture("material.depthMap", 1);
		shader->setTexture("material.normalMap", 2);
		shader->setInt("material.shininess", planete->getShininess());
		shader->setInt("render_normal", m_state->getRenderNormal());
		shader->setInt("shadows", m_state->getRenderShadow());
		shader->setFloat("far_plane", m_state->getFar());
		shader->setFloat("material.light_strength", planete->getLightStrength());

		if ((planete->getType() == "double_textured_planete") || (planete->getType() == "earth"))
		{
			shader->setTexture("material.cloud", 3);
			shader->setFloat("oppacity", planete->getOppacity());
		}

		if (planete->getType() == "earth")
		{
			shader->setTexture("material.night", 4);
		}

		glUseProgram(0);
	}
	super::sendToShader(shader_map, planete);
}