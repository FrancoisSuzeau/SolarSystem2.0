/*
AUTHOR : SUZEAU François

DATE : 27/11/2021

MODULE : CelestialBody.Planete

NAMEFILE : Planete.h

PURPOSE : header of the Planete class
*/

#ifndef PLANETE_H
#define PLANETE_H


/********************************************************************* includes *********************************************************************/

        #include "Sphere.hpp"
        #include "Ring.hpp"

        #include <string>
        #include <vector>
        #include <iostream>
        #include <cassert>

        #include <GL/glew.h>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>
#include "../../../../DataManagementLayer/DataManager.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {
    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class Planete : public Sphere
                {
                private:

                    typedef Sphere super;
                    float   m_oppacity;
                    std::string     m_name;
                    /*Ring* m_ring = nullptr;
                    Sphere* m_atmosphere = nullptr;*/
                    float           light_strength;


                protected:


                public:

                    Planete(DataManagementLayer::body_data data);
                    ~Planete();

                    void transform(glm::vec3 ship_pos = glm::vec3(0.f)) override;
                    void    clean();
                    
                    /*Ring* getRing() const;
                    Sphere* getAmosphere() const;
                    void    makeOtherChanges(Applications::DataManager& data_manager);
                    
                    void renderName(Applications::DataManager& data_manager);
                    void loadDiffuseTexture();
                    void loadNormalTexture();*/

                    float getLightStrength()  override;
                    float getOppacity()  override;

                    

                };

            }
        }
    }
}
        
#endif