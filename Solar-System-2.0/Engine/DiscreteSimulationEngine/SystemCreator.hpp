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

                virtual System* FactoryMethod(std::string const system_name, State* state, DataManagementLayer::body_data sun_data = DataManagementLayer::body_data()) = 0;

                bool MakingSystem(std::string const system_name, DataManagementLayer::body_data sun_data, State* state)
                {
                    m_system = this->FactoryMethod(system_name, state, sun_data);
                    assert(m_system);
                    return true;
                }

                int loadSystem(DataManagementLayer::body_data body_datas)
                {
                    m_system->loadSystem(body_datas);
                    return 1;
                }

                void cleanSystem()
                {
                    m_system->clean();
                }

                Objects::OpenGL::Object* getCelestialBody(std::string const body)
                {
                    return m_system->getCelestialBody(body);
                }

                /*void render()
                {
                    m_system->render();
                }*/

                void makeChanges()
                {
                    m_system->makeChanges();
                }

                /*void renderNameAndInfo(Applications::DataManager& data_manager)
                {
                    m_system->renderNameAndInfo(data_manager);
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