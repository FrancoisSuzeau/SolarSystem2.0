/*
AUTHOR : SUZEAU François

DATE : 06/03/2022

MODULE : Renderer::BasicRenderers

NAMEFILE : SquareRenderer.hpp

PURPOSE : header of the SquareRenderer class
*/

#ifndef SQUARE_RENDERER_H
#define SQUARE_RENDERER_H


/********************************************************************* includes *********************************************************************/

        #include "Renderer.hpp"
        //#include "../../Objects/BasicObjects/Square.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace RenderingEngine {

        class SquareRenderer : public Renderer
        {

            private:

                typedef Renderer super;

            protected:

                float   m_vertices[18];
                float   m_colors[18];
                float   m_coord_texture[12];

                int     m_bytes_vertices_size;
                int     m_bytes_colors_size;
                int     m_bytes_texture_size;

                void    load() override;

            public:

                SquareRenderer(float const color);
                ~SquareRenderer();


                //void render(Applications::DataManager &data_manager, Object *square) override;
                void clean() override;
        };

    }
}

        


#endif