/*
AUTHOR : SUZEAU François

DATE : 30/10/2021

MODULE : Object::AsteroidField

NAMEFILE : AsteroidField.hpp

PURPOSE : header of the AsteroidField class
*/

#ifndef ASTEROIDFIELD_H
#define ASTEROIDFIELD_H


/********************************************************************* includes *********************************************************************/

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>
        #include <glm/gtc/matrix_inverse.hpp>
        #include <glm/gtx/string_cast.hpp>

        #include <GL/glew.h>

        #include <iostream>
        #include <cassert>

        #include "Object.hpp"
        #include "../Blender/Model.hpp"       

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class AsteroidField : public Object
                {

                    private:

                        typedef Object super;

                        /*Blender::Model* asteroid;
                        unsigned int                    m_amount;
                        glm::mat4* model_matrices;
                        glm::vec3* m_positions;
                        float* rotAngle;
                        float* scaleM;
                        glm::vec3* m_rot_vector;

                        unsigned int                    vbo;

                        void                            initTransformations();
                        void                            initInstances();*/

                    public:

                        AsteroidField(std::string const type);
                        ~AsteroidField();

                        float getLightStrength() override;
                        float getOppacity() override;

                        /*void transform(glm::vec3 ship_pos = glm::vec3(0.f), Input* input = nullptr) override;
                        void clean();

                        void render(Applications::DataManager& data_manager);*/

                        // void updateCount(RenderData &render_data)

                };

            }

        }

    }

}


#endif