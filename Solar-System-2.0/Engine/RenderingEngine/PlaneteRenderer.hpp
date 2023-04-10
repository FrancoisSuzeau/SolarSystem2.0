/*
AUTHOR : SUZEAU François

DATE : 15/06/2021

MODULE : Renderer::TexturedRenderer::PlaneteRenderer

NAMEFILE : PlaneteRenderer.hpp

PURPOSE : header of the PlaneteRenderer class
*/

#ifndef PLANETE_RENDERER_H
#define PLANETE_RENDERER_H


/********************************************************************* includes *********************************************************************/

#include "SphereRenderer.hpp"
#include "../DiscreteSimulationEngine/Objects/OpenGL/Planete.hpp"


#include <string>
#include <vector>
#include <iostream>
#include <cassert>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/********************************************************************* class definition *********************************************************************/

namespace Engine {

	namespace RenderingEngine {

		class PlaneteRenderer : public SphereRenderer
		{
		private:
			typedef SphereRenderer super;

		protected:

			void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* planete) override;

		public:

			PlaneteRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs, State* state);
			~PlaneteRenderer();

			void render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* planete) override;
			void clean() override;
		};
	}
}




#endif