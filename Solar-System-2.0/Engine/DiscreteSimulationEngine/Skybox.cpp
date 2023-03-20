/*
AUTHOR : SUZEAU François

DATE : 13/06/2021

MODULE : Skybox

NAMEFILE : Skybox.cpp

PURPOSE :   - load texture for cube maps
            - load vertex position
            - transfer vertex to GPU buffer
            - display texured cubemaps

*/

#include "Skybox.hpp"
using namespace Engine::DiscreteSimulationEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Skybox::Skybox(unsigned int tex_id) : m_vboID(0), m_vaoID(0), m_texture_id(tex_id)
{   
    GLfloat skyboxVertices[108] = 
    {
        // positions          
        -2.0f,  2.0f, -2.0f,
        -2.0f, -2.0f, -2.0f,
        2.0f, -2.0f, -2.0f,
        2.0f, -2.0f, -2.0f,
        2.0f,  2.0f, -2.0f,
        -2.0f,  2.0f, -2.0f,

        -2.0f, -2.0f,  2.0f,
        -2.0f, -2.0f, -2.0f,
        -2.0f,  2.0f, -2.0f,
        -2.0f,  2.0f, -2.0f,
        -2.0f,  2.0f,  2.0f,
        -2.0f, -2.0f,  2.0f,

        2.0f, -2.0f, -2.0f,
        2.0f, -2.0f,  2.0f,
        2.0f,  2.0f,  2.0f,
        2.0f,  2.0f,  2.0f,
        2.0f,  2.0f, -2.0f,
        2.0f, -2.0f, -2.0f,

        -2.0f, -2.0f,  2.0f,
        -2.0f,  2.0f,  2.0f,
        2.0f,  2.0f,  2.0f,
        2.0f,  2.0f,  2.0f,
        2.0f, -2.0f,  2.0f,
        -2.0f, -2.0f,  2.0f,

        -2.0f,  2.0f, -2.0f,
        2.0f,  2.0f, -2.0f,
        2.0f,  2.0f,  2.0f,
        2.0f,  2.0f,  2.0f,
        -2.0f,  2.0f,  2.0f,
        -2.0f,  2.0f, -2.0f,

        -2.0f, -2.0f, -2.0f,
        -2.0f, -2.0f,  2.0f,
        2.0f, -2.0f, -2.0f,
        2.0f, -2.0f, -2.0f,
        -2.0f, -2.0f,  2.0f,
        2.0f, -2.0f,  2.0f
    };

    if(glIsVertexArray(m_vaoID) != GL_TRUE)
    {
        glGenVertexArrays(1, &m_vaoID);
        assert(m_vaoID != 0);
    }
    
    if(glIsBuffer(m_vboID) != GL_TRUE)
    {
        glGenBuffers(1, &m_vboID);
        assert(m_vboID != 0);
    }
    
    glBindVertexArray(m_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

Skybox::~Skybox()
{

}

/***********************************************************************************************************************************************************************/
/**************************************************************************** sendToShader *****************************************************************************/
/***********************************************************************************************************************************************************************/
//void Skybox::sendToShader(Applications::DataManager &data_manager)
//{
//    if(data_manager.getShader("skybox") != nullptr)
//    {
//        glUseProgram(data_manager.getShader("skybox")->getProgramID());
//
//            glm::mat4 view = glm::mat4(glm::mat3(data_manager.getViewMat()));
//
//            data_manager.getShader("skybox")->setMat4("view", view);
//            data_manager.getShader("skybox")->setMat4("projection", data_manager.getProjMat());
//
//            data_manager.getShader("skybox")->setTexture("skybox", 0);
//            // data_manager.getShader("skybox")->setInt("hdr", data_manager.getHDR());
//
//        glUseProgram(0);
//    }
//}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************* render *****************************************************************************/
///***********************************************************************************************************************************************************************/
//void Skybox::render(Applications::DataManager &data_manager)
//{   
//    
//    glDepthFunc(GL_LEQUAL);
//
//    if(data_manager.getShader("skybox") != nullptr)
//    {
//        glUseProgram(data_manager.getShader("skybox")->getProgramID());
//
//            //lock vao
//            glBindVertexArray(m_vaoID);
//
//                //lock texture
//                glActiveTexture(GL_TEXTURE0);
//                glBindTexture(GL_TEXTURE_CUBE_MAP, m_texture_id);
//
//                //display the form
//                glDrawArrays(GL_TRIANGLES, 0, 36);
//
//                //unlock texture
//                glActiveTexture(GL_TEXTURE0);
//                glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
//
//            //unlock VAO
//            glBindVertexArray(0);
//
//        glUseProgram(0);
//    }   
//
//    glDepthFunc(GL_LESS);
//    
//}

/***********************************************************************************************************************************************************************/
/********************************************************************************* clean *****************************************************************************/
/***********************************************************************************************************************************************************************/
void Skybox::clean()
{
    if(glIsTexture(m_texture_id) == GL_TRUE)
    {
        glDeleteTextures(1, &m_texture_id);
        m_texture_id = 0;
    }

    if(glIsVertexArray(m_vaoID) == GL_TRUE)
    {
        glDeleteVertexArrays(1, &m_vaoID);
        m_vaoID = 0;
    }

    if(glIsBuffer(m_vboID) == GL_TRUE)
    {
        glDeleteBuffers(1, &m_vboID);
        m_vboID = 0;
    }

    std::cout << ">> SKYBOX : DESTROY COMPLETE" << std::endl;
}