/*
AUTHOR : SUZEAU François

DATE : 23/11/2021

MODULE : DataManager

NAMEFILE : DataManager.hpp

PURPOSE :   - Manage data transfert between all module of the application program
            - Store datas references (for texture, render, settings)
*/

#include "DataManager.hpp"
using namespace DataManagementLayer;

//std::vector<body_data> DataManager::m_bodys_data;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
DataManager::DataManager(): preference_data(nullptr), bodies_data(nullptr)
{
    
}

DataManager::~DataManager()
{
    
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** clean *****************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::clean(int const which_one)
{
    switch (which_one)
    {
        case PREFERENCE:
            if (preference_data != nullptr)
            {
                delete preference_data;
                preference_data = nullptr;
            }
            break;
        case BODIESDATA:
            if (bodies_data != nullptr)
            {
                delete bodies_data;
                bodies_data = nullptr;
                body_data_mapping.clear();
            }
            break;
        default:
            break;
    }
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* setConfigs ****************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::setConfigs(Engine::State* state)
{
    if (preference_data == nullptr)
    {
        preference_data = Loader::loadJsonObject("preference_data");
        assert(preference_data);
    }
    state->setFps(preference_data->IntOf("fps"));
    state->setRenderOverlay(preference_data->BoolOf("render_overlay"));
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* setTextures ****************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::setTextures()
{
    if (bodies_data == nullptr)
    {
        bodies_data = Loader::loadJsonObject("bodies_data");
        assert(bodies_data);
    }

    int nb_bodies = bodies_data->SizeOfArray("bodies_textures");
    for (size_t i = 0; i < nb_bodies; i++)
    {
        bodies_data->put_I(i);
        body_data tmp = {
            bodies_data->stringOf("bodies_textures[i].texture_surface_path"),
            bodies_data->stringOf("bodies_textures[i].texture_cloud_path"),
            bodies_data->stringOf("bodies_textures[i].texture_night_path")
        };
        body_data_mapping.insert({bodies_data->stringOf("bodies_textures[i].name") , tmp});
    }
}