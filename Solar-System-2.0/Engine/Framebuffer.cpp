/*
AUTHOR : SUZEAU François

DATE : 14/11/2021

MODULE : Framebuffer

NAMEFILE : Framebuffer.h

PURPOSE :   
*/

//usefull macro for VBO
#ifndef BUFFER_OFFSET
#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
#endif

#include "Framebuffer.hpp"
using namespace Engine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Framebuffer::Framebuffer()
{

}

Framebuffer::~Framebuffer()
{
    
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** clean **********************************************************************************/
/***********************************************************************************************************************************************************************/
void Framebuffer::clean()
{
    glDeleteVertexArrays(1, &quadVAO);
    quadVAO = 0;
    glDeleteBuffers(1, &quadVBO);
    quadVBO = 0;
    glDeleteFramebuffers(1, &color_fb_id);
    color_fb_id = 0;
    glDeleteFramebuffers(1, &depth_fb_id);
    depth_fb_id = 0;
    glDeleteFramebuffers(2, ping_pongFBO);
    glDeleteRenderbuffers(1, &render_buffer_id);
    render_buffer_id = 0;
    glDeleteTextures(1, &depth_map);
    depth_map = 0;
    glDeleteTextures(2, colorBuffers);
    glDeleteTextures(2, ping_pong_text);

    std::cout << ">> FRAMEBUFFER : DESTROY COMPLETE" << std::endl;
}

/***********************************************************************************************************************************************************************/
/*********************************************************************** initVertices **********************************************************************************/
/***********************************************************************************************************************************************************************/
void Framebuffer::initVertices()
{
    float vertices[] = {-1.0f, -1.0f, -1.0f,   1.0f, -1.0f, -1.0f,   1.0f, 1.0f, -1.0f,   
                        -1.0f, -1.0f, -1.0f,   -1.0f, 1.0f, -1.0f,   1.0f, 1.0f, -1.0f   
    };

    float coord[] = {0.0f, 0.0f,   1.0f, 0.0f,   1.0f, 1.0f,
                          0.0f, 0.0f,   0.0f, 1.0f,   1.0f, 1.0f
                          };

    m_bytes_vertices_size = 18 * sizeof(float);
    m_bytes_coord_size = 12 * sizeof(float);

    for (int i = 0; i < 18; i++)
    {
        quadVertices[i] = vertices[i];
    }

    for (int i = 0; i < 12; i++)
    {
        tex_coord[i] = coord[i];
    }
    
}

///***********************************************************************************************************************************************************************/
///*********************************************************************** initFramebuffers ******************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::createBuffers(int width, int height)
{
    this->initVertices();

    /************************************************* VBO management ********************************************************/

    //generate Vertex Buffer Object ID
    glGenBuffers(1, &quadVBO);
    assert(quadVBO != 0);

    //lock VBO
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

        //memory allocation
        glBufferData(GL_ARRAY_BUFFER, m_bytes_vertices_size + m_bytes_coord_size, 0, GL_STATIC_DRAW);
        /*
            - GL_STATIC_DRAW : data with few updating
            - GL_DYNAMIC_DRAW : data with frequently updating (many times per second but not each frame
            - GL_STREAM_DRAW : data with each frame updating
        there is 6 other possible values
        */

       //vertices transfert$
       glBufferSubData(GL_ARRAY_BUFFER, 0, m_bytes_vertices_size, quadVertices);
       glBufferSubData(GL_ARRAY_BUFFER, m_bytes_vertices_size, m_bytes_coord_size, tex_coord);

       //unlock VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //===================================================================================================================

    /************************************************* VAO management ********************************************************/
    //generate Vertex Array Object ID
    glGenVertexArrays(1, &quadVAO);
    assert(quadVAO != 0);

    //lock VAO
    glBindVertexArray(quadVAO);

        //lock VBO
        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);

        //acces to the vertices in video memory
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);

        //acces to the colors in video memory
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_bytes_vertices_size));
        glEnableVertexAttribArray(2);

        //unlock VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    //unlock VAO
    glBindVertexArray(0);
    //===================================================================================================================
}

//// /***********************************************************************************************************************************************************************/
//// /****************************************************************** manageColorBuffer **********************************************************************************/
//// /***********************************************************************************************************************************************************************/
void Framebuffer::manageColorBuffer(int width, int height)
{   
    glGenTextures(2, colorBuffers);
    assert(colorBuffers[0] != 0);
    assert(colorBuffers[1] != 0);
    for(unsigned int i = 0; i < 2; i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, colorBuffers[i]);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, colorBuffers[i], 0);

        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

///***********************************************************************************************************************************************************************/
//// /****************************************************************** manageDepthMap **********************************************************************************/
//// /***********************************************************************************************************************************************************************/
void Framebuffer::manageDepthMap(int width, int height)
{   
    glGenTextures(1, &depth_map);
    assert(depth_map != 0);

    glBindTexture(GL_TEXTURE_CUBE_MAP, depth_map);

        for (unsigned int i = 0; i < 6; ++i)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, width, width, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
       
        glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depth_map, 0);

        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

///***********************************************************************************************************************************************************************/
///****************************************************************** manageDepthBuffer **********************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::manageRenderBuffer(int width, int height)
{
    glGenRenderbuffers(1, &render_buffer_id);
    assert(render_buffer_id != 0);

    glBindRenderbuffer(GL_RENDERBUFFER, render_buffer_id);

        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_buffer_id);

    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    // Tell OpenGL we need to draw to both attachments
	unsigned int attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, attachments);
}

///***********************************************************************************************************************************************************************/
///****************************************************************** managePingPongFBO **********************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::managePinPongFBO(int width, int height)
{
    glGenFramebuffers(2, ping_pongFBO);
    assert(ping_pongFBO[0] != 0);
    assert(ping_pongFBO[1] != 0);

	glGenTextures(2, ping_pong_text);
    assert(ping_pong_text[0] != 0);
    assert(ping_pong_text[1] != 0);

    for (unsigned int i = 0; i < 2; i++)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, ping_pongFBO[i]);

            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, ping_pong_text[i]);

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ping_pong_text[i], 0);

        this->checkFramebufferStatus("Ping pong framebuffer");

        glActiveTexture(GL_TEXTURE0 + i);
	    glBindTexture(GL_TEXTURE_2D, 0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}

///***********************************************************************************************************************************************************************/
///****************************************************************** checkFramebufferStatus **********************************************************************************/
///***********************************************************************************************************************************************************************/
bool Framebuffer::checkFramebufferStatus(std::string const framebuffer_type)
{
    auto status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    std::string status_msg = ">> FRAMEBUFFER : " + framebuffer_type + " framebuffer is ";
    if (status != GL_FRAMEBUFFER_COMPLETE)
    {
        status_msg += "NOT complete ! ";
        std::cout << status_msg  << status << std::endl;
        return false;
    }
    status_msg += "complete !";
    std::cout << status_msg << std::endl;
    return true;
}

///***********************************************************************************************************************************************************************/
///****************************************************************** manageFramebuffers **********************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::manageFramebuffers(int width, int height)
{
    glGenFramebuffers(1, &depth_fb_id);
    assert(depth_fb_id != 0);

    glBindFramebuffer(GL_FRAMEBUFFER, depth_fb_id);

        this->manageDepthMap(width, height);
        bool success = this->checkFramebufferStatus("Depth");
        assert(success);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glGenFramebuffers(1, &color_fb_id);
    assert(color_fb_id != 0);

    glBindFramebuffer(GL_FRAMEBUFFER, color_fb_id);

        this->manageColorBuffer(width, height);
        
        this->manageRenderBuffer(width, height);

        success = this->checkFramebufferStatus("Color");
        assert(success);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    this->managePinPongFBO(width, height);

    //===================================================================================================================
}

///***********************************************************************************************************************************************************************/
///*********************************************************************** renderFrame ***********************************************************************************/
///***********************************************************************************************************************************************************************/
//void Framebuffer::renderFrame(Applications::DataManager &data_manager)
//{
//    bool horizontal = true;
//    this->drawBlur(data_manager, horizontal);
//    this->drawScreenTexture(data_manager, horizontal);
//}
//
///***********************************************************************************************************************************************************************/
///************************************************************************* drawBlur ************************************************************************************/
///***********************************************************************************************************************************************************************/
//void Framebuffer::drawBlur(Applications::DataManager &data_manager, bool &horizontal)
//{
//    bool first_it = true;
//    
//    unsigned int amount = data_manager.getBloomStrength();
//
//        glUseProgram(data_manager.getShader("blur")->getProgramID());
//
//        if(data_manager.getBloom())
//        {
//            for (unsigned int i = 0; i < amount; i++)
//            {
//                glBindFramebuffer(GL_FRAMEBUFFER, ping_pongFBO[horizontal]);
//                
//                data_manager.getShader("blur")->setInt("horizontal", horizontal);
//                data_manager.getShader("blur")->setTexture("screenTexture", 0);
//
//                if(first_it)
//                {
//                    glActiveTexture(GL_TEXTURE0);
//                    glBindTexture(GL_TEXTURE_2D, colorBuffers[1]);
//                    first_it = false;
//                }
//                else
//                {
//                    glActiveTexture(GL_TEXTURE0);
//                    glBindTexture(GL_TEXTURE_2D, ping_pong_text[!horizontal]);
//                }
//
//                glBindVertexArray(quadVAO);
//
//                    glDrawArrays(GL_TRIANGLES, 0, 6);
//
//                    glActiveTexture(GL_TEXTURE0);
//                    glBindTexture(GL_TEXTURE_2D, 0);        
//
//                glBindVertexArray(0);
//                horizontal = !horizontal;
//            }
//        }
//
//    glUseProgram(0);
//
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//}
//
///***********************************************************************************************************************************************************************/
///**************************************************************** drawScreenTexture ************************************************************************************/
///***********************************************************************************************************************************************************************/
//void Framebuffer::drawScreenTexture(Applications::DataManager &data_manager, bool &horizontal)
//{   
//    if(data_manager.getShader("screen") != nullptr)
//    {
//        glUseProgram(data_manager.getShader("screen")->getProgramID());
//
//            data_manager.getShader("screen")->setInt("bloom", data_manager.getBloom());
//
//            data_manager.getShader("screen")->setTexture("screen_texture", 0);
//            data_manager.getShader("screen")->setTexture("bloom_texture", 1);
//
//            glBindVertexArray(quadVAO);
//
//                glActiveTexture(GL_TEXTURE0);
//                glBindTexture(GL_TEXTURE_2D, colorBuffers[0]);
//
//                if(data_manager.getBloom())
//                {
//                    glActiveTexture(GL_TEXTURE1);
//                    glBindTexture(GL_TEXTURE_2D, ping_pong_text[!horizontal]);
//                }  
//                
//                glDrawArrays(GL_TRIANGLES, 0, 6);
//
//                glActiveTexture(GL_TEXTURE0);
//                glBindTexture(GL_TEXTURE_2D, 0);
//
//                if(data_manager.getBloom())
//                {
//                    glActiveTexture(GL_TEXTURE1);
//                    glBindTexture(GL_TEXTURE_2D, 0);
//                }
//
//            glBindVertexArray(0);
//
//            
//        glUseProgram(0);
//    }
//
//    data_manager.setDepthMapTexture(depth_map);
//    
//}
//
///***********************************************************************************************************************************************************************/
///****************************************************************** bindFramebuffer ************************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::bindFramebuffer(int type)
{
    glBindFramebuffer(GL_FRAMEBUFFER, this->getFB(type));

    // glEnable(GL_DEPTH_TEST);
}

///***********************************************************************************************************************************************************************/
///**************************************************************** unbindFramebuffer ************************************************************************************/
///***********************************************************************************************************************************************************************/
void Framebuffer::unbindFramebuffer()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // glDisable(GL_DEPTH_TEST);
}

///***********************************************************************************************************************************************************************/
///*********************************************************************** getter ****************************************************************************************/
///***********************************************************************************************************************************************************************/
unsigned int Framebuffer::getFB(int type) const
{
    unsigned int fb = 0;
    switch (type)
    {
        case COLOR_FBO:
            fb = color_fb_id;
            break;
        case DEPTH_FBO:
            fb = depth_fb_id;
            break;
        default:
            break;
    }
    return fb;
}