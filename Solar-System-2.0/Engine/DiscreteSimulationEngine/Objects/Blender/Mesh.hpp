/*
AUTHOR : SUZEAU François

DATE : 09/10/2021

MODULE : Renderers::ModelRenderer

NAMEFILE : Mesh.hpp

PURPOSE : header of the Mesh class
*/

#ifndef MESH_H
#define MESH_H


/********************************************************************* includes *********************************************************************/

        #include <glm/glm.hpp>
        #include <glm/gtx/transform.hpp>
        #include <glm/gtc/type_ptr.hpp>
        #include <glm/gtc/matrix_inverse.hpp>
        #include <glm/gtx/string_cast.hpp>

        #include <GL/glew.h>

        #include <assimp/Importer.hpp>
        #include <assimp/scene.h>
        #include <assimp/postprocess.h>

        #include <iostream>
        #include <string>
        #include <math.h>
        #include <vector>

        #define MAX_BONE_INFLUENCE 4

        

/********************************************************************* class definition *********************************************************************/
        namespace Engine {

            namespace DiscreteSimulationEngine {

                namespace Objects {

                    namespace Blender {

                        typedef struct Vertex {

                            glm::vec3 Position;
                            glm::vec3 Normal;
                            glm::vec2 TexCoords;

                            // tangent
                            glm::vec3 Tangent;
                            // bitangent
                            glm::vec3 Bitangent;
                            //bone indexes which will influence this vertex
                            int m_BoneIDs[MAX_BONE_INFLUENCE];
                            //weights from each bone
                            float m_Weights[MAX_BONE_INFLUENCE];

                        } Vertex;

                        typedef struct Texturate {

                            unsigned int id = 0;
                            std::string type;

                            std::string path;

                        } Texturate;

                        class Mesh
                        {

                            private:

                                /*std::vector<Vertex>         m_vertices;
                                std::vector<GLuint>         m_indices;
                                std::vector<Texturate>      m_textures;

                                unsigned int m_vao;
                                unsigned int m_vbo;
                                unsigned int m_ebo;

                                void setupMesh();*/

                            public:

                                Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texturate> textures);
                                Mesh();
                                ~Mesh();

                                /*void draw(Applications::DataManager& data_manager);

                                std::vector<Vertex> getVertices() const;
                                std::vector<unsigned int> getIndices() const;
                                std::vector<Texturate> getTextures() const;

                                unsigned int getVAO() const;

                                void        clean();*/

                        };

                    }

                }

            }

}
        


#endif