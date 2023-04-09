/*
AUTHOR : SUZEAU François

DATE : 18/03/2022

MODULE : Renderers::TexturedRenderers::StarRenderer

NAMEFILE : StarRenderer.hpp

PURPOSE : header of the StarRenderer class
*/

#ifndef STAR_RENDERER_H
#define STAR_RENDERER_H


/********************************************************************* includes *********************************************************************/

#include "SphereRenderer.hpp"
#include "../DiscreteSimulationEngine/Objects/OpenGL/Star.hpp"




/********************************************************************* class definition *********************************************************************/
namespace Engine {

	namespace RenderingEngine {

		class StarRenderer : public SphereRenderer
		{
		private:

			typedef SphereRenderer super;

		protected:
			void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* star) override;

		public:

			StarRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs, State* state);
			~StarRenderer();

			void render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* star) override;
			;
			void clean() override;
		};

	}

}



#endif