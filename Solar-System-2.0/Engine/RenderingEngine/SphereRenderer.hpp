/*
AUTHOR : SUZEAU François

DATE : 06/06/2021

MODULE : Renderers::BasicRenderers

NAMEFILE : SphereRenderer.hpp

PURPOSE : header of the SphereRenderer class
*/

#ifndef SPHERE_RENDERER_H
#define SPHERE_RENDERER_H


/********************************************************************* includes *********************************************************************/

        #include "Renderer.hpp"
#include "../DiscreteSimulationEngine/Objects/OpenGL/Sphere.hpp"
        

/********************************************************************* class definition *********************************************************************/

namespace Engine {

    namespace RenderingEngine {

        class SphereRenderer : public Renderer
        {
            private:

                typedef Renderer super;

            protected:

                GLuint                          m_ibo;
                GLsizei                         m_element_count;
                unsigned int                    m_vertCount;
                std::vector<GLushort>           m_tris;
                float                           m_radius;
                std::vector<GLfloat> vertices;
                std::vector<GLfloat> normals;
                std::vector<GLfloat> textures_coord;

                unsigned int                    longVerts;
                unsigned int                    latVerts;

                int                             m_bytes_vertices_size;
                int                             m_bytes_normals_size;
                int                             m_bytes_texture_size;

                void                            load() override;
                void sendToShader(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* shpere) override;

            public:

                SphereRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs, State* state);
                ~SphereRenderer();


                void render(std::map<std::string, RenderingEngine::Shader*> shader_map, DiscreteSimulationEngine::Objects::OpenGL::Object* sphere) override;
                
                void clean() override;
        };

    }
}

        


#endif