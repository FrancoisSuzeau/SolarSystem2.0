/*
AUTHOR : SUZEAU François

DATE : 14/11/2021

MODULE : Framebuffer

NAMEFILE : Framebuffer.h

PURPOSE : header of the Framebuffer class
*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H


/********************************************************************* includes *********************************************************************/

        #include <GL/glew.h>

        #include <iostream>
        #include <cassert>

        //#include "../../Application/DataManager.hpp"

        

/********************************************************************* class definition *********************************************************************/

namespace Engine {

    

        class Framebuffer
        {

            private:

                /*unsigned int quadVAO = 0;
                unsigned int quadVBO = 0;

                unsigned int color_fb_id = 0;
                unsigned int depth_fb_id = 0;
                unsigned int render_buffer_id = 0;
                unsigned int depth_map = 0;

                unsigned int colorBuffers[2] = {0, 0};
                unsigned int ping_pongFBO[2] = {0, 0};
                unsigned int ping_pong_text[2] = {0, 0};

                float quadVertices[18];
                float tex_coord[12];

                int m_bytes_vertices_size;
                int m_bytes_coord_size;

                void initVertices();
                void manageFramebuffers(int width, int height);
                void manageColorBuffer(int width, int height);
                void manageDepthMap(int width, int height);
                void manageRenderBuffer(int width, int height);
                void managePinPongFBO(int width, int height);

                void drawBlur(Applications::DataManager &data_manager, bool &horizontal);
                void drawScreenTexture(Applications::DataManager &data_manager, bool &horizontal);

                bool checkFramebufferStatus(std::string const framebuffer_type);*/

            public:

                Framebuffer();
                ~Framebuffer();

                void initFramebuffers(int width, int height);
                void clean();
                /*void renderFrame(Applications::DataManager& data_manager);
                void bindFramebuffer(int type);
                void unbindFramebuffer();

                unsigned int getFB(int type) const;*/

            };


    

}

#endif