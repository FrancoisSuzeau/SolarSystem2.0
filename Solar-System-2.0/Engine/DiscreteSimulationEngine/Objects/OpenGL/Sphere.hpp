/*
AUTHOR : SUZEAU François

DATE : 06/06/2021

MODULE : Objects::BasicObjects

NAMEFILE : Sphere.hpp

PURPOSE : header of the Sphere class
*/

#ifndef SPHERE_H
#define SPHERE_H


/********************************************************************* includes *********************************************************************/

        #include "Object.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class Sphere : public Object
                {
                    private:

                        typedef Object super;


                    public:

                        Sphere(float size, std::string const type);
                        ~Sphere();

                       void transform(InputDevices::KeyInput key_input, InputDevices::MouseInput mouse_input, glm::vec3 ship_pos = glm::vec3(0.f)) override;
                        void sendToShader() override;
                        void clean();
                };

            }

        }

    }

}
        
#endif