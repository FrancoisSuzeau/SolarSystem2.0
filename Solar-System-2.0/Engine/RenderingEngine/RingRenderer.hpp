/*
AUTHOR : SUZEAU François

DATE : 24/03/2022

MODULE : Renderer::TexturedRenderer::RingRenderer

NAMEFILE : RingRenderer.hpp

PURPOSE : header of the RingRenderer class

*/

#ifndef RING_RENDERER_H
#define RING_RENDERER_H


/********************************************************************* includes *********************************************************************/

        #include "SquareRenderer.hpp"
        //#include "../../../Objects/TexturedObjects/SquareTextured/Ring/Ring.hpp"
        

        #include <string>
        #include <vector>
        #include <iostream>
        #include <cassert>

        #include <GL/glew.h>
        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>
        
/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace RenderingEngine {

        class RingRenderer : public SquareRenderer
        {
            private:
                typedef SquareRenderer super;


            protected:

                // std::string     m_name;

            public:

                RingRenderer();
                ~RingRenderer();

                //void render(DataManagementLayer::DataManager &data_manager, Object *ring) override;
                void clean() override;
            };
    }
}

       


#endif