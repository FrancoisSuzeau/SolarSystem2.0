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
#include "RenderingEngine/Shader.hpp"

#define COLOR_FBO 0
#define DEPTH_FBO 1

/********************************************************************* class definition *********************************************************************/

namespace Engine {



	class Framebuffer
	{

	private:

		unsigned int quadVAO = 0;
		unsigned int quadVBO = 0;

		unsigned int color_fb_id = 0;
		unsigned int depth_fb_id = 0;
		unsigned int render_buffer_id = 0;
		unsigned int depth_map = 0;

		unsigned int colorBuffers[2] = { 0, 0 };
		unsigned int ping_pongFBO[2] = { 0, 0 };
		unsigned int ping_pong_text[2] = { 0, 0 };

		float quadVertices[18];
		float tex_coord[12];

		int m_bytes_vertices_size;
		int m_bytes_coord_size;

		void initVertices();
		
		void manageColorBuffer(int width, int height);
		void manageDepthMap(int width, int height);
		void manageRenderBuffer(int width, int height);
		void managePinPongFBO(int width, int height);

		void drawBlur(RenderingEngine::Shader* blur_shader, bool& horizontal, int const bloomStrength, bool const bloom);
		void drawScreenTexture(RenderingEngine::Shader* screen_shader, bool &horizontal, bool const bloom);

		bool checkFramebufferStatus(std::string const framebuffer_type);

	public:

		Framebuffer();
		~Framebuffer();

		void createBuffers(int width, int height);
		void manageFramebuffers(int width, int height);
		void clean();
		void bindFramebuffer(int type);
		void unbindFramebuffer();

		void renderFrame(RenderingEngine::Shader* blur_shader, RenderingEngine::Shader* screen_shader, int const bloomStrength, bool const bloom);


		unsigned int getFB(int type) const;

	};




}

#endif