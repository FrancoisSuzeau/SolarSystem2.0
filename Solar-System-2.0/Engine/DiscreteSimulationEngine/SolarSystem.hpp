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

       /* #include "../../Objects/TexturedObjects/Star/Star.hpp"
        #include "../../Renderers/TexturedRenderers/StarRenderer/StarRenderer.hpp"

        #include "../../Objects/AsteroidField/AsteroidField.hpp"*/

        #include <cassert>
        
        
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        class SolarSystem : public System
        {

            private:

                /*Star* m_sun = nullptr;
                Renderer* m_star_renderer = nullptr;

                std::vector<Planete*>           m_planetes;
                AsteroidField* m_asteroid_field = nullptr;*/


                std::vector<SystemCreator*>     m_planetary_systems;


            public:

                SolarSystem(/*Renderer* planete_renderer, Renderer* ring_renderer, Renderer* sphere_renderer, std::string const system_name*/);
                ~SolarSystem();


                /*void loadSystem(int count = 0) override;
                void render(Applications::DataManager& data_manager) override;
                void makeChanges(Applications::DataManager& data_manager) override;
                void renderRing(Applications::DataManager& data_manager) override;
                void renderAtmosphere(Applications::DataManager& data_manager) override;
                void clean() override;
                void renderNameAndInfo(Applications::DataManager& data_manager) override;
                void renderFlareSun(Applications::DataManager& data_manager) override;*/

        };

    }
}


#endif