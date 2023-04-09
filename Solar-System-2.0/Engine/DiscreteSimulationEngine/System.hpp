/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : System.hpp

PURPOSE : header of the virtual System class
*/

#ifndef SYSTEM_H
#define SYSTEM_H


/********************************************************************* includes *********************************************************************/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../DataManagementLayer/DataManager.hpp"
#include "../State.hpp"
#include "Objects/OpenGL/Object.hpp"


/********************************************************************* class definition *********************************************************************/
namespace Engine {

	namespace DiscreteSimulationEngine {

		class System
		{

		protected:

			std::string                      m_system_name;
			State*						m_state;

		public:


			virtual ~System() {};
			virtual void loadSystem(DataManagementLayer::body_data body_datas) = 0;
			virtual void clean() = 0;

			virtual void makeChanges() = 0;
			//virtual void render() = 0;

			virtual Objects::OpenGL::Object* getCelestialBody(std::string const body) = 0;

			/*virtual void renderNameAndInfo(Applications::DataManager& data_manager) = 0;
			virtual void renderRing(Applications::DataManager& data_manager) = 0;
			virtual void renderAtmosphere(Applications::DataManager& data_manager) = 0;
			virtual void renderFlareSun(Applications::DataManager& data_manager) = 0;*/

		};

	}

}



#endif