/*
AUTHOR : SUZEAU François

DATE : 29/05/2021

MODULE : Application::Camera

NAMEFILE : Camera.hpp

PURPOSE : header of the Camera class

*/

#ifndef CAMERA_H
#define CAMERA_H


/********************************************************************* includes *********************************************************************/

#include <string>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "InputDevices/InputDevices.hpp"
#include "DiscreteSimulationEngine/Objects/OpenGL/Spaceship.hpp"

/********************************************************************* class definition *********************************************************************/
namespace Engine {

	class Camera
	{

	private:

		DiscreteSimulationEngine::Objects::OpenGL::Spaceship *m_ship;

		glm::vec3   m_vertical_axe;
		glm::vec3   m_position;
		glm::vec3   m_target_point;

		float           distance_from_ship;
		float           angle_around_player;
		float           pitch;

		void    calculatePitch(InputDevices::MouseInput mouse_input);
		void    calculateAngleAroundShip(InputDevices::MouseInput mouse_input);
		float   calculateHorizontalDistance();
		float   calculateVerticalDistance();
		void    calculateCameraPostion(float horizontal_distance, float vertical_distance);
		//void    correctTarget(InputDevices::MouseInput mouse_input);


	public:

		Camera(glm::vec3 position, glm::vec3 target_point, glm::vec3 vertical_axe /*Spaceship* ship = nullptr*/);
		~Camera();

		void    move(InputDevices::MouseInput mouse_input, bool move);
		glm::mat4       getViewMatrix();
		void    setDistFromShip(float const new_val);		
		glm::vec3 getPosition() const;
		void		setShip(DiscreteSimulationEngine::Objects::OpenGL::Spaceship* ship);


	};

}
#endif