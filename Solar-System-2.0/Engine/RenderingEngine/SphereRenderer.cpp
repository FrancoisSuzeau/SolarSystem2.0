/*
AUTHOR : SUZEAU François

DATE : 06/06/2021

MODULE : Renderer::BasicRenderers

NAMEFILE : SphereRenderer.cpp

PURPOSE : class SphereRenderer
*/


#include "SphereRenderer.hpp"
using namespace Engine::RenderingEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
SphereRenderer::SphereRenderer(const float radius, const unsigned int longSegs, const unsigned int latSegs) : 
m_ibo(0), m_element_count(0), m_radius(radius)
{
    super::m_vboID = 0;
    super::name = "SPHERE RENDERER";
    /************************************************* calculate vertex position ********************************************************/
    longVerts = longSegs + 1;
    latVerts = latSegs + 1;
    m_vertCount = longVerts * latVerts;

    vertices.reserve(longVerts * latVerts * 3);
    normals.reserve(longVerts * latVerts * 3);
    textures_coord.reserve(longVerts * latVerts * 2);

    m_bytes_vertices_size = (longVerts * latVerts * 3) * sizeof(GLfloat);
    m_bytes_normals_size = (longVerts * latVerts * 3) * sizeof(GLfloat);
    m_bytes_texture_size = (longVerts * latVerts * 2) * sizeof(GLfloat);

    for (unsigned int i(0); i < longVerts; i++)
    {
        const float iDivLong  = i / (float)longSegs;
        const float theta     = i == 0 || i == longSegs ? 0.0 : iDivLong * 2.0 * M_PI;

        for (unsigned int j = 0; j < latVerts; j++)
        {

            const float jDivLat = j / (float)latSegs;
            const float phi     = jDivLat * M_PI;

            // Normal
            GLfloat n1 = cos(theta) * sin(phi);
            GLfloat n2 = cos(phi);
            GLfloat n3 = sin(theta) * sin(phi);
            normals.push_back(n1);
            normals.push_back(n2);
            normals.push_back(n3);

            // Position
            vertices.push_back(n1 * radius);
            vertices.push_back(n2 * radius);
            vertices.push_back(n3 * radius);

            // Texture coordinates
            textures_coord.push_back(iDivLong);
            textures_coord.push_back(jDivLat);
        }
    }
    
    //===================================================================================================================================

    const unsigned int triCount = longSegs * latSegs * 2;
    m_element_count = triCount * 3;
    m_tris.reserve(m_element_count);
    unsigned int index = 0;
    for (unsigned int i = 0; i < longSegs; i++)
    {
        for (unsigned int j = 0; j < latSegs; j++)
        {
            // Vertex indices
            const unsigned int v0 = j + latVerts * i;
            const unsigned int v1 = j + latVerts * (i + 1);
            const unsigned int v2 = v1 + 1;
            const unsigned int v3 = v0 + 1;

            // First triangle
            m_tris.push_back(v0);
            m_tris.push_back(v1);
            m_tris.push_back(v2);
          

            // Second triangle
            m_tris.push_back(v0);
            m_tris.push_back(v2);
            m_tris.push_back(v3);
        }
    }

    this->load();    
    // ===================================================================================================================================

}


SphereRenderer::~SphereRenderer()
{

}

/***********************************************************************************************************************************************************************/
/******************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void SphereRenderer::clean()
{
    if(glIsBuffer(super::m_vboID) == GL_TRUE)
    {
        glDeleteBuffers(1, &m_vboID);
        super::m_vboID = 0;
    }
    if(glIsBuffer(m_ibo) == GL_TRUE)
    {
        glDeleteBuffers(1, &m_ibo);
        m_ibo = 0;
    }

    vertices.clear();
    normals.clear();
    textures_coord.clear();
    m_tris.clear();

    std::cout << ">> " << super::name << " : DESTROY COMPLETE" << std::endl;
}

/***********************************************************************************************************************************************************************/
/************************************************************************************** load ***************************************************************************/
/***********************************************************************************************************************************************************************/
void SphereRenderer::load()
{

    /************************************************* VBO management ********************************************************/
    //destroy a possible ancient VBO
    if(glIsBuffer(super::m_vboID) == GL_TRUE)
    {
        glDeleteBuffers(1, &m_vboID);
        super::m_vboID = 0;
    }

    //generate Vertex Buffer Object ID
    glGenBuffers(1, &m_vboID);
    assert(super::m_vboID != 0);

    //lock VBO
    glBindBuffer(GL_ARRAY_BUFFER, super::m_vboID);

        //memory allocation
        glBufferData(GL_ARRAY_BUFFER, m_bytes_vertices_size + m_bytes_normals_size + m_bytes_texture_size, 0, GL_STATIC_DRAW);

        /*
            - GL_STATIC_DRAW : data with few updating
            - GL_DYNAMIC_DRAW : data with frequently updating (many times per second but not each frame
            - GL_STREAM_DRAW : data with each frame updating
        there is 6 other possible values
        */

       //transfer vertices in video memory
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_bytes_vertices_size, vertices.data());
        
        //transfer the normals in video memory
        glBufferSubData(GL_ARRAY_BUFFER, m_bytes_vertices_size, m_bytes_normals_size, normals.data());
        
        //transfer the textures coordinates in video memory
        glBufferSubData(GL_ARRAY_BUFFER, m_bytes_vertices_size + m_bytes_normals_size, m_bytes_texture_size, textures_coord.data());
        
   
            //acces to the vertices in video memory
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
            glEnableVertexAttribArray(0);

            //acces to the normals in video memory
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_bytes_vertices_size));
            glEnableVertexAttribArray(1);

            //acces to coordonates texture in video memory
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_bytes_vertices_size + m_bytes_normals_size));
            glEnableVertexAttribArray(2);


    //unlock VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //===================================================================================================================

    /************************************************* IBO management ********************************************************/
    //destroy a possible ancient IBO
    if(glIsBuffer(m_ibo) == GL_TRUE)
    {
        glDeleteBuffers(1, &m_ibo);
        m_ibo = 0;
    }

    //generate Index Buffer Object ID
    glGenBuffers(1, &m_ibo);
    assert(m_ibo != 0);

    //lock IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    

        //memory allocation
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * m_element_count, 0, GL_DYNAMIC_DRAW);
        /*
            - GL_STATIC_DRAW : data with few updating
            - GL_DYNAMIC_DRAW : data with frequently updating (many times per second but not each frame
            - GL_STREAM_DRAW : data with each frame updating
        there is 6 other possible values
        */

       //Indices transfert
       glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLushort) * m_element_count, m_tris.data());

    //unlock IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //===================================================================================================================
}


/***********************************************************************************************************************************************************************/
/******************************************************************************** render ******************************************************************************/
/***********************************************************************************************************************************************************************/
//void SphereRenderer::render(Applications::DataManager &data_manager, Object *sphere)
//{
//    if(data_manager.getShader(sphere->getType()) != nullptr)
//    {
//        if(data_manager.getPass() == DEPTH_FBO)
//        {
//            glUseProgram(data_manager.getShader("depth_map")->getProgramID());
//        }
//        else
//        {
//            glUseProgram(data_manager.getShader(sphere->getType())->getProgramID());
//        }
//        /************************************************* bind VBO and IBO ********************************************************/
//        glBindBuffer(GL_ARRAY_BUFFER,         super::m_vboID);
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
//        //===================================================================================================================================
//        glDrawElements(GL_TRIANGLES, m_element_count, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));
//        /************************************************* unbind VBO and IBO ********************************************************/
//        glBindBuffer(GL_ARRAY_BUFFER,         0);
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//        //===================================================================================================================================
//
//        glUseProgram(0);
//    }
//    
//}