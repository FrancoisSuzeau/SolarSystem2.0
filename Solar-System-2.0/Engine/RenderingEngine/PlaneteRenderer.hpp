/*
AUTHOR : SUZEAU François

DATE : 15/06/2021

MODULE : Renderer::TexturedRenderer::PlaneteRenderer

NAMEFILE : PlaneteRenderer.hpp

PURPOSE : header of the PlaneteRenderer class
*/

#ifndef PLANETE_RENDERER_H
#define PLANETE_RENDERER_H


/********************************************************************* includes *********************************************************************/

        #include "SphereRenderer.hpp"
        //#include "Planete.hpp"
        

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

        class PlaneteRenderer : public SphereRenderer
        {
            private:
                typedef SphereRenderer super;

            protected:

                // std::string     m_name;

            public:

                PlaneteRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs);
                ~PlaneteRenderer();

                //void render(Applications::DataManager &data_manager, Object *planete) override;
                void clean() override;
        };
    }
}

        


#endif