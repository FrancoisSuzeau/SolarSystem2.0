/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : SolarSystem.hpp

PURPOSE : header of the virtual SolarSystem class
*/

#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H


/********************************************************************* includes *********************************************************************/

#include "System.hpp"
#include "PlanetarySystemCreator.hpp"

/*#include "../../Objects/AsteroidField/AsteroidField.hpp"*/

#include "Objects/OpenGL/Star.hpp"

#include <cassert>



/********************************************************************* class definition *********************************************************************/
namespace Engine {

	namespace DiscreteSimulationEngine {

		class SolarSystem : public System
		{

		private:

			Objects::OpenGL::Star* m_sun;
			/*

			std::vector<Planete*>           m_planetes;
			AsteroidField* m_asteroid_field = nullptr;*/


			//std::vector<SystemCreator*>     m_planetary_systems;


		public:

			SolarSystem(std::string const system_name, DataManagementLayer::body_data sun_data, State *state);
			~SolarSystem();


			void loadSystem(DataManagementLayer::body_data body_datas) override;
			Objects::OpenGL::Object* getCelestialBody(std::string const body) override;
			//void render() override;
			void makeChanges() override;
			void clean() override;

			/*;
			;
			void renderRing(Applications::DataManager& data_manager) override;
			void renderAtmosphere(Applications::DataManager& data_manager) override;
			void renderNameAndInfo(Applications::DataManager& data_manager) override;
			void renderFlareSun(Applications::DataManager& data_manager) override;*/

		};

	}
}


#endif