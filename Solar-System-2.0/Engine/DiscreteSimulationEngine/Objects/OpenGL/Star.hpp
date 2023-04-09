/*
AUTHOR : SUZEAU François

DATE : 16/06/2021

MODULE : Objects::TexturedObjects::Star

NAMEFILE : Star.hpp

PURPOSE : header of the Star class
*/

#ifndef STAR_H
#define STAR_H


/********************************************************************* includes *********************************************************************/

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include <GL/glew.h>
        #include <iostream>
        #include <string>
        #include <cstring>
        #include <vector>
        #include <cassert>

        #include "Sphere.hpp"
        #include "FlareManager.hpp"
#include "../../../../DataManagementLayer/DataManager.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class Star : public Sphere
                {

                    private:

                        typedef         Sphere super;
                        /*FlareManager* m_flare_manager_cam_dirt = nullptr;
                        FlareManager* m_flare_manager_sun_ray = nullptr;*/



                    public:

                        Star(DataManagementLayer::body_data data);
                        ~Star();

                        void transform(glm::vec3 ship_pos = glm::vec3(0.f)) override;
                        //void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map) override;
                        void    clean();
                        /*
                        void    makeOtherChanges(Applications::DataManager& data_manager);

                        void renderFlares(Applications::DataManager& data_manager);*/

                };

            }

        }

    }

}
        
#endif