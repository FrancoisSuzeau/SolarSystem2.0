/*
AUTHOR : SUZEAU François

DATE : 14/05/2022

MODULE : Renderer::TexturedRenderer::SquareTexturedRenderer

NAMEFILE : SquareTexturedRenderer.hpp

PURPOSE : header of the SquareTexturedRenderer class

*/

#ifndef SQUARE_TEXTURED_REN_H
#define SQUARE_TEXTURED_REN_H


/********************************************************************* includes *********************************************************************/

        #include "SquareRenderer.hpp"
        //#include "../../../Objects/TexturedObjects/SquareTextured/LensFlare/FlareTexture.hpp"
        

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

        class SquareTexturedRenderer : public SquareRenderer
        {
            private:
                typedef SquareRenderer super;

            public:

                SquareTexturedRenderer();
                ~SquareTexturedRenderer();

                //void render(Applications::DataManager &data_manager, Object *FlareTexture) override;
                void clean() override;

            };

    }

}

       


#endif