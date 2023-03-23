/*
AUTHOR : SUZEAU François

DATE : 23/11/2021

MODULE : State

NAMEFILE : State.hpp

PURPOSE : header of the State class
*/

#ifndef STATE_H
#define STATE_H


/********************************************************************* includes *********************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <glm/glm.hpp>
#include <SDL2/SDL_mixer.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "InputDevices/InputDevices.hpp"

#define COLOR_FBO 0
#define DEPTH_FBO 1

/********************************************************************* class definition *********************************************************************/

namespace Engine {

	class State
	{

	private:

		bool                   m_terminate;
		unsigned int           m_fps;
		bool                   m_render_menu;
		bool                   key_pressed;
		bool                   m_render_overlay;
		std::string            m_spaceship_name;
		bool					m_change_track;

		InputDevices::KeyInput* m_key_input;
		InputDevices::MouseInput* m_mouse_input;
		SDL_Event* m_event;

		glm::mat4       proj_mat;
		glm::mat4       view_mat;
		float           near_plane;
		float           far_plane;
		int             pass;
		bool            bloom;
		int             bloom_strenght;
		float           distance_from_ship;
		glm::vec3       cam_pos;

		/*
		
		bool            render_normal;
		int             asteroid_count;
		bool            render_overlay;
		bool            render_name;
		bool            render_info;
		
		int             index_ship;
		bool            change_skin;
		
		unsigned int    depth_map;
		
		bool            render_shadow;

		
		glm::vec3       ship_position;
		
		glm::vec3       ship_orientation;

		bool            hilight_sun;*/



	public:

		State(int width, int height, double angle);
		~State();

		static int             m_width;
		static int             m_height;

		bool            getTerminate() const;
		void            setTerminate(bool const terminate);
		void            listenEvents();
		void            setFps(unsigned int const fps);
		unsigned int    getFps() const;
		void            setRenderMenu(bool const value);
		bool            getRenderMenu() const;
		void            setRenderOverlay(bool const new_val);
		bool            getRenderOverlay() const;
		void            setSpaceshipName(std::string const name);
		std::string     getSpaceshipName() const;
		void			setChangeTrack(bool const new_val);
		bool			getChangeTrack() const;

		glm::mat4       getViewMat();
		void            setViewMat(glm::mat4 const new_val);
		void            resetViewMat(glm::mat4 const new_mat);
		glm::mat4       getProjMat() const;
		void            lockView(glm::vec3 position, glm::vec3 target, glm::vec3 up);
		float           getFar() const;
		float           getNear() const;
		void            setPass(int const new_val);
		int             getPass() const;

		void            setBloom(bool const new_val);
		bool            getBloom() const;
		void            setBloomStrength(int const new_val);
		int             getBloomStrength() const;

		InputDevices::KeyInput getKeyInput() const;
		InputDevices::MouseInput getMouseInput() const;

		void            setDistanceFromShip(float const new_val);
		float           getDistancteFromShip() const;
		void            setCamPos(glm::vec3 const new_val);
		glm::vec3       getCamPos() const;

		void            clean();

		/*static std::vector<body_data>          m_bodys_data;
		
		
		
		void            setRenderNormal(bool const new_val);
		bool            getRenderNormal() const;
		void            setAsteroidCount(int const new_val);
		int             getAsteroidCount() const;

		void            setRenderName(bool const new_val);
		bool            getRenderName() const;
		void            setRenderInfo(bool const new_val);
		bool            getRenderInfo() const;
		
		void            setIndexShip(int const new_val);
		int             getIndexShip() const;
		void            setChangeSkin(bool const new_val);
		bool            getChangeSkin() const;
		void            setShipPos(glm::vec3 const new_val);
		glm::vec3       getShipPos() const;
		
		glm::vec3       getSunPos() const;
		
		std::vector<glm::mat4>       getLightSpaceMatrix();
		void            setDepthMapTexture(unsigned int const new_val);
		unsigned int    getDepthMapTexture() const;
		
		void            setHilightSun(bool const new_val);
		bool            getHilightSun() const;
		void            setRenderShadow(bool const new_val);
		bool            getRenderShadow() const;
		static void            initDatas();
		static body_data       getBodyData(int index);


		glm::vec2 convertToScreenSpace(glm::vec3 const body_pos);

		glm::vec3 getShipOrientation() const;
		void        setShipOrientation(glm::vec3 const new_val);*/


	};


}

#endif