/*
AUTHOR : SUZEAU François

DATE : 06/03/2022

MODULE : Renderers

NAMEFILE : Renderer.hpp

PURPOSE : header of the Renderer class
*/

#ifndef RENDERER_H
#define RENDERER_H


/********************************************************************* includes *********************************************************************/

#include <gl/glew.h>
#include "../DataManagementLayer/DataManager.hpp"
#include "../DiscreteSimulationEngine/Objects/OpenGL/Object.hpp"
#include "Shader.hpp"
#include <map>
#include "../State.hpp"

//usefull macro for VBO
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif

/********************************************************************* class definition *********************************************************************/
namespace Engine {

	namespace RenderingEngine {

		class Renderer
		{

		protected:

			GLuint  m_vaoID;
			GLuint  m_vboID;
			const State* m_state = nullptr;

			std::string name = "";

			virtual void load() = 0;
			virtual void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* object) = 0;


		public:

			// Renderer();
			virtual ~Renderer() {};


			virtual void render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object *object) = 0;
			
			virtual void clean() = 0;

		};

	}

}


#endif