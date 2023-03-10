/*
AUTHOR : SUZEAU François

DATE : 10/06/2021

MODULE : Objects::TexturedObjects::SquareTextured::Ring

NAMEFILE : Ring.hpp

PURPOSE : header of the Ring class
*/

#ifndef RING_H
#define RING_H


/********************************************************************* includes *********************************************************************/

        #include <string>
        #include <cassert>
        #include <vector>
        #include <iostream>

        #include <GL/glew.h>

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include "Square.hpp"
        

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class Ring : public Square
                {

                    private:

                        typedef Square super;

                    public:
                        Ring(float size, std::vector<std::string> textures_path, std::string const type, int shininess, float inclinaison_angle);
                        ~Ring();

                        /*void transform(glm::vec3 ship_pos = glm::vec3(0.f), Input* input = nullptr) override;
                        void sendToShader(Applications::DataManager& data_manager) override;
                        void    clean();*/

                };


            }

        }

    }

}
        

#endif