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

        #include "../DataManager.hpp"
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        class System
        {

        protected:

            std::string                      m_system_name;

        public:


            virtual ~System() {};
            virtual void loadSystem(int count = 0) = 0;
            virtual void clean() = 0;

            /*virtual void makeChanges(Applications::DataManager& data_manager) = 0;
            virtual void render(Applications::DataManager& data_manager) = 0;
            
            virtual void renderNameAndInfo(Applications::DataManager& data_manager) = 0;
            virtual void renderRing(Applications::DataManager& data_manager) = 0;
            virtual void renderAtmosphere(Applications::DataManager& data_manager) = 0;
            virtual void renderFlareSun(Applications::DataManager& data_manager) = 0;*/

        };

    }

}
        


#endif