/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : SystemCreator.hpp

PURPOSE : header of the virtual SystemCreator class
*/

#ifndef SYSTEMCREATOR_H
#define SYSTEMCREATOR_H


/********************************************************************* includes *********************************************************************/

        #include <string>
        #include <vector>
        #include <iostream>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include "System.hpp"
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        class SystemCreator
        {

            protected:

                System* m_system = nullptr;

            public:

                virtual ~SystemCreator() {};

                virtual System* FactoryMethod(std::string const system_name) = 0;

                bool MakingSystem(std::string const system_name)
                {
                    m_system = this->FactoryMethod(system_name);
                    assert(m_system);
                    return true;
                }

                int loadSystem(int count = 0)
                {
                    m_system->loadSystem(count);
                    return 1;
                }

                void cleanSystem()
                {
                    m_system->clean();
                }

                /*void renderNameAndInfo(Applications::DataManager& data_manager)
                {
                    m_system->renderNameAndInfo(data_manager);
                }



                void render(Applications::DataManager& data_manager)
                {
                    m_system->render(data_manager);
                }

                void makeChanges(Applications::DataManager& data_manager)
                {
                    m_system->makeChanges(data_manager);
                }



                void renderRing(Applications::DataManager& data_manager)
                {
                    m_system->renderRing(data_manager);
                }

                void renderAtmosphere(Applications::DataManager& data_manager)
                {
                    m_system->renderAtmosphere(data_manager);
                }

                void renderFlareSun(Applications::DataManager& data_manager)
                {
                    m_system->renderFlareSun(data_manager);
                }*/


            };

    }

}
        


#endif