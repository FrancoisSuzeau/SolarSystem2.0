/*
AUTHOR : SUZEAU François

DATE : 23/11/2021

MODULE : DataManager

NAMEFILE : DataManager.hpp

PURPOSE : header of the DataManager class
*/

#ifndef DATA_H
#define DATA_H


/********************************************************************* includes *********************************************************************/
#include <iostream>
#include <map>
#include <string>

#include "Loader.hpp"
#include "../Engine/State.hpp"

#define PREFERENCE 0
#define BODIESDATA 1
#define SHADERSDATA 2
#define SPACESHIPSDATA 3
#define SKYBOXPATHS 4
#define MUSICSDATA 5
#define SUNDATA 6


/********************************************************************* class definition *********************************************************************/

namespace DataManagementLayer {

	typedef struct body_data {

		std::string                     name;
		GLuint							texture_surface_id;
		GLuint							texture_cloud_id;
		GLuint							texture_night_id;
		GLuint							texture_normal_id;
		float                           size;
		/*std::string						host_name;
		
		int                             shininess;
		float                           oppacity;
		glm::vec3                       current_position;

		float                           inclinaison_angle;
		float                           light_strength;
		float   						   speed_rotation;*/

	} body_data;

	typedef struct imgui_datas {

		int img_width;
		int img_height;
		GLuint text_id;
		std::string name;

	} imgui_datas;

	class DataManager
	{

	private:

		CkJsonObject* preference_data;
		CkJsonObject* bodies_data;
		CkJsonObject* musics_data;
		CkJsonObject* shaders_data;
		CkJsonObject* spaceships_data;
		CkJsonObject* skybox_paths;
		CkJsonObject* sun_data;
		int nb_bodies;
		int nb_shaders;
		int nb_spaceships;
		int nb_musics;


	public:

		DataManager();
		~DataManager();

		void clean(int const which_one);

		void setConfigs(Engine::State* state);

		std::string getTexturePath(int i, std::string texture_type);
		GLuint getTextureId(std::string const path) const;

		void setShaderPaths(int i);
		std::map<std::string, std::string> getShaderPaths();

		std::string setAndGetMusicPath(int i, std::string const radio);
		Mix_Music* getMusic();
		std::map<std::string, std::string> getMusicInfo();

		std::string setAndGetSpaceshipPath(std::string const prefered_ship);
		std::string setAndGetSpaceshipPath(int i);

		std::vector <std::string> getSkyboxPath();
		unsigned int getSkyboxTexture(std::vector<std::string> skybox_paths) const;

		int getNbBodies() const;
		int getNbShaders() const;
		int getNbSpaceships() const;
		int getNbMusics() const;
		int getIfrom(std::string jsonObject) const;


		std::vector<imgui_datas> getImGuiTexture() const;
		body_data getCurrentBodyData() const;
		body_data getSunData() const;
	};
}

#endif