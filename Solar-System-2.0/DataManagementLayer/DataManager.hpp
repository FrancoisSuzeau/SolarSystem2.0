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
        

        /*#include "../Shader/Shader.hpp"*/

        #define PREFERENCE 0
        #define BODIESDATA 1
        

/********************************************************************* class definition *********************************************************************/

namespace DataManagementLayer {

    /*typedef struct shader_datas {

        std::string v_shader_path;
        std::string f_shader_path;
        std::string g_shader_path;
        std::string key;

    }shader_datas;*/

    //typedef struct body_data {

    //    float                           size;
    //    std::string                     type;
    //    int                             shininess;
    //    float                           oppacity;
    //    glm::vec3                       initial_pos;
    //    std::string                     name;
    //    float                           inclinaison_angle;
    //    float                           light_strength;
    //    // std::vector<std::string> nom_disp_path;
    //    // std::string name;
    //    // float   speed_rotation;

    //} body_data;

    typedef struct body_data {

        std::string surface_texture_path;
        std::string cloud_texture_path;
        std::string night_texture_path;

    } body_data;

    class DataManager
    {

        private:

            CkJsonObject* preference_data;
            CkJsonObject* bodies_data;

            std::map<std::string, body_data> body_data_mapping;


        public:

            DataManager();
            ~DataManager();

            void clean(int const which_one);

            void setConfigs(Engine::State* state);
            void setTextures();

    };
}

#endif