/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : PlanetarySystem.hpp

PURPOSE : header of the virtual PlanetarySystem class
*/

#ifndef PLSYSTEM_H
#define PLSYSTEM_H


/********************************************************************* includes *********************************************************************/

        #include "System.hpp"

        #include <string>
        #include <vector>
        #include <iostream>
        #include <GL/glew.h>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include <cassert>
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        class PlanetarySystem : public System
        {

            private:

               /* std::vector<Planete*>                   m_moons;
                Planete* m_host;*/

            public:

                PlanetarySystem(/*Renderer* planete_renderer, Renderer* ring_renderer, Renderer* sphere_renderer, std::string const system_name*/);
                ~PlanetarySystem();


                /*void loadSystem(int count = 0) override;
                void render(Applications::DataManager& data_manager) override;
                void makeChanges(Applications::DataManager& data_manager) override;
                void clean() override;
                void renderNameAndInfo(Applications::DataManager& data_manager) override;
                void renderRing(Applications::DataManager& data_manager) override;
                void renderAtmosphere(Applications::DataManager& data_manager) override;
                void renderFlareSun(Applications::DataManager& data_manager) override;*/

        };

    }
}
#endif