/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : PlanetarySystemCreator.hpp

PURPOSE : header of the virtual PlanetarySystemCreator class
*/

#ifndef PLSYSTEMCREATOR_H
#define PLSYSTEMCREATOR_H


/********************************************************************* includes *********************************************************************/

        #include <string>
        #include <vector>
        #include <iostream>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include "SystemCreator.hpp"
        #include "PlanetarySystem.hpp"
       
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

    
    class PlanetarySystemCreator : public SystemCreator
    {

    private:



    public:


        System* FactoryMethod(std::string const system_name) override
        {
            // puts("");
            // puts("");
            // std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> System Creator : " << data.name_sys << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
            return new PlanetarySystem(system_name);
        }


    };

}
}
#endif