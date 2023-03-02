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
DataManager::DataManager()
{
    Loader::loadConfigs();
}

DataManager::~DataManager()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* setConfigs ****************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::setConfigs(Engine::State& state)
{
    state.setFps(std::stoi(Loader::configData.value("fps", "NO")));
}