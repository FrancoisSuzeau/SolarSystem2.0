/*
AUTHOR : SUZEAU François

DATE : 06/03/2022

MODULE : Renderers

NAMEFILE : Renderer.hpp

PURPOSE : header of the Renderer class
*/

#ifndef RENDERER_H
#define RENDERER_H


/********************************************************************* includes *********************************************************************/

        #include <gl/glew.h>
        #include "../DataManagementLayer/DataManager.hpp"
        //#include "../Objects/Object.hpp"

        //usefull macro for VBO
        #ifndef BUFFER_OFFSET
        #define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
        #endif

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace RenderingEngine {

        class Renderer
        {

            protected:

                GLuint  m_vaoID;
                GLuint  m_vboID;

                std::string name = "";

                virtual void load() = 0;

            public:

                // Renderer();
                virtual ~Renderer() {};


                //virtual void render(DataManagementLayer::DataManager &data_manager, Object *object) = 0;
                virtual void clean() = 0;

        };

    }

}
        

#endif