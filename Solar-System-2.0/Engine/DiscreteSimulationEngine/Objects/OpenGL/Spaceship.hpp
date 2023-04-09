/*
AUTHOR : SUZEAU François

DATE : 17/10/2021

MODULE : Object::Spaceship

NAMEFILE : Spaceship.hpp

PURPOSE : header of the Spaceship class
*/

#ifndef SPACESHIP_H
#define SPACESHIP_H


/********************************************************************* includes *********************************************************************/

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>
        #include <glm/gtc/matrix_inverse.hpp>
        #include <glm/gtx/string_cast.hpp>

        #include <iostream>
        #include <string>
        #include <math.h>
        #include <vector>
        
        #include "../Blender/Model.hpp"
        #include "Object.hpp"
#include "../../../State.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class Spaceship : public Object
                {

                    private:

                        typedef Object super;

                        const State* m_state = nullptr;

                        Blender::Model* m_model;

                        std::vector<std::string> file_paths;

                        float           m_pitch;
                        float           m_yaw;
                        float           m_sensibility[2];
                        float           m_speed;
                        float           speed_limit;
                        bool            directions[6];
                        float           y_dir;
                        float           x_dir;
                        int             m_index_skin;

                        std::vector<float> m_scales;

                        glm::vec3 m_ship_orientation;
                        glm::vec3 m_lateral_move;

                        glm::mat4 yaw_mat;
                        glm::mat4 pitch_mat;

                        void orientateShip(InputDevices::MouseInput mouse_input);
                        void changePitch(InputDevices::MouseInput mouse_input);
                        void changeYaw(InputDevices::MouseInput mouse_input);
                        void move(InputDevices::KeyInput key_input);


                    public:

                        Spaceship(std::string const type, State *state);
                        ~Spaceship();

                        void    clean();
                        void transform(glm::vec3 ship_pos = glm::vec3(0.f)) override;
                        void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map) ;

                        void render(RenderingEngine::Shader *shader);
                        float getRotX() const;
                        float getRotY() const;
                        glm::vec3       getOrientation() const;
                        glm::vec3       getLateralMove() const;
                        float getSpeed() const;
                        void setSpeed(float speed);
                        void setMinimumSpeed();
                        void setMaximumSpeed();
                        void buildModel(std::string const& path, int index);

                        void updateSpeed(float const new_val);
                };

            }

        }

    }

}
        


#endif