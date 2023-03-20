/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : SolarSystemCreator.hpp

PURPOSE : header of the virtual SolarSystemCreator class
*/

#ifndef SSSYSTEMCREATOR_H
#define SSSYSTEMCREATOR_H


/********************************************************************* includes *********************************************************************/

        #include <string>
        #include <vector>
        #include <iostream>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include "SystemCreator.hpp"
        #include "SolarSystem.hpp"
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        class SolarSystemCreator : public SystemCreator
        {

            private:



            public:

                ~SolarSystemCreator() override {
                    if (m_system != nullptr)
                    {
                        delete m_system;
                        m_system = nullptr;
                        std::cout << ">> SOLAR SYSTEM : DESTROY COMPLETE" << std::endl;
                    }
                }


                System* FactoryMethod(std::string const system_name) override
                {
                    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Solar System Creator :  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
                    return new SolarSystem(system_name);
                }

                bool MakingSystem(std::string const system_name)
                {
                    m_system = this->FactoryMethod(system_name);
                    assert(m_system);
                    return true;
                }


            };
    }
}


#endif