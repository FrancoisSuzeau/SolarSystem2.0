/*
AUTHOR : SUZEAU François

DATE : 13/06/2021

MODULE : Skybox

NAMEFILE : Skybox.hpp

PURPOSE : header of the Skybox class
*/

#ifndef SKYBOX_H
#define SKYBOX_H


/********************************************************************* includes *********************************************************************/

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>

        #include <GL/glew.h>
        #include <SDL2/SDL.h>
        #include <SDL2/SDL_image.h>
        #include <iostream>
        #include <string>
        #include <cstring>
        #include <vector>
        #include <cassert>

#include "../State.hpp"


/********************************************************************* class definition *********************************************************************/

namespace Engine
{
    namespace DiscreteSimulationEngine
    {
        class Skybox
        {

            private:


                std::vector<std::string>     m_faces;
                unsigned int                 m_texture_id;
                GLuint                       m_vboID;
                GLuint                       m_vaoID;

            public:


                Skybox(unsigned int tex_id);
                ~Skybox();


                void                    render(GLuint pgr_id);
                void                    clean();

        };
    }
}


#endif