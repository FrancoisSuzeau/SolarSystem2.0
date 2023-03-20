/*
AUTHOR : SUZEAU François

DATE : 17/06/2021

MODULE : System

NAMEFILE : PlanetarySystem.cpp

PURPOSE : class PlanetarySystem
*/



#include "PlanetarySystem.hpp"
using namespace Engine::DiscreteSimulationEngine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
PlanetarySystem::PlanetarySystem(std::string const system_name)
{
    /*m_planete_renderer = planete_renderer;
    m_ring_renderer = ring_renderer;
    m_sphere_renderer = sphere_renderer;
    m_system_name = system_name;*/

}

PlanetarySystem::~PlanetarySystem()
{
    

}

/***********************************************************************************************************************************************************************/
/****************************************************************************** clean ******************************************************************************/
/***********************************************************************************************************************************************************************/
void PlanetarySystem::clean()
{
    /*for(std::vector<Planete*>::iterator it = m_moons.begin(); it != m_moons.end(); ++it)
    {
        if(it[0] != nullptr)
        {
            it[0]->clean();
            delete it[0];
            it[0] = nullptr;
        }
    }

    if(m_host != nullptr)
    {
        m_host->clean();
        delete m_host;
        m_host = nullptr;
    }*/
}

// /***********************************************************************************************************************************************************************/
// /******************************************************************************** loadSystem ***************************************************************************/
// /***********************************************************************************************************************************************************************/
void PlanetarySystem::loadSystem(int count)
{
    
    /************************************************* loading companion ********************************************************/
    //if(m_system_name == "Earth System")
    //{
    //    m_moons.push_back(new Planete(Applications::DataManager::getBodyData(2)));
    //    assert(m_moons[0]);

    //    m_host = new Planete(Applications::DataManager::getBodyData(3));
    //    assert(m_host);
    //}
    //else if (m_system_name == "Jovian System")
    //{
    //    for (int i(6); i < 10; i++)
    //    {
    //        m_moons.push_back(new Planete(Applications::DataManager::getBodyData(i)));
    //        assert(m_moons[i - 6]);
    //    }

    //    m_host = new Planete(Applications::DataManager::getBodyData(5));
    //    assert(m_host);

    //}
    //else if (m_system_name == "Saturnian System")
    //{
    //    for (int i(11); i < 14; i++)
    //    {
    //        m_moons.push_back(new Planete(Applications::DataManager::getBodyData(i)));
    //        assert(m_moons[i - 11]);
    //    }

    //    m_host = new Planete(Applications::DataManager::getBodyData(10));
    //    assert(m_host);
    //}
    //else if (m_system_name == "Uranian System")
    //{
    //    // for (int i(11); i < 14; i++)
    //    // {
    //    //     m_moons.push_back(new Planete(Applications::DataManager::getBodyData(i)));
    //    //     assert(m_moons[i - 11]);
    //    // }

    //    m_host = new Planete(Applications::DataManager::getBodyData(14));
    //    assert(m_host);
    //}
    //else if (m_system_name == "Neptunian System")
    //{
    //    // for (int i(11); i < 14; i++)
    //    // {
    //    //     m_moons.push_back(new Planete(Applications::DataManager::getBodyData(i)));
    //    //     assert(m_moons[i - 11]);
    //    // }

    //    m_host = new Planete(Applications::DataManager::getBodyData(15));
    //    assert(m_host);
    //}
}

//// /***********************************************************************************************************************************************************************/
//// /****************************************************************************** makeChanges ****************************************************************************/
//// /***********************************************************************************************************************************************************************/
//void PlanetarySystem::makeChanges(Applications::DataManager& data_manager)
//{
//    if (m_host != nullptr)
//    {
//        m_host->updatePosition(m_host->getPosition());
//        m_host->transform(-data_manager.getShipPos());
//        m_host->makeOtherChanges(data_manager);
//    }
//
//    for (std::vector<Planete*>::iterator it = m_moons.begin(); it != m_moons.end(); ++it)
//    {
//        if (it[0] != nullptr)
//        {
//            it[0]->updatePosition(it[0]->getPosition());
//            it[0]->transform(-data_manager.getShipPos());
//            it[0]->makeOtherChanges(data_manager);
//        }
//    }
//}
//
//// /***********************************************************************************************************************************************************************/
//// /*********************************************************************************** renderNameAndInfo ***************************************************************************/
//// /***********************************************************************************************************************************************************************/
//void PlanetarySystem::renderNameAndInfo(Applications::DataManager& data_manager)
//{
//    if (m_host != nullptr)
//    {
//        m_host->renderName(data_manager);
//    }
//
//    for (std::vector<Planete*>::iterator it = m_moons.begin(); it != m_moons.end(); ++it)
//    {
//        if (it[0] != nullptr)
//        {
//            it[0]->renderName(data_manager);
//        }
//    }
//}
//
//// /***********************************************************************************************************************************************************************/
//// /*********************************************************************************** render ***************************************************************************/
//// /***********************************************************************************************************************************************************************/
//void PlanetarySystem::render(Applications::DataManager& data_manager)
//{
//    for (std::vector<Planete*>::iterator it = m_moons.begin(); it != m_moons.end(); ++it)
//    {
//        if ((m_planete_renderer != nullptr) && (it[0] != nullptr))
//        {
//            m_planete_renderer->render(data_manager, it[0]);
//        }
//    }
//
//    if ((m_planete_renderer != nullptr) && (m_host != nullptr))
//    {
//        m_planete_renderer->render(data_manager, m_host);
//    }
//}
//
//// /************************************************************************************************************************************************************************/
//// /******************************************************************************* renderRing *****************************************************************************/
//// /************************************************************************************************************************************************************************/
//void PlanetarySystem::renderRing(Applications::DataManager& data_manager)
//{
//    if (m_host != nullptr)
//    {
//        if ((m_ring_renderer != nullptr) && (m_host->getRing() != nullptr))
//        {
//            m_ring_renderer->render(data_manager, m_host->getRing());
//        }
//    }
//}
//
//// /************************************************************************************************************************************************************************/
//// /******************************************************************************* renderAtmosphere *****************************************************************************/
//// /************************************************************************************************************************************************************************/
//void PlanetarySystem::renderAtmosphere(Applications::DataManager& data_manager)
//{
//    Sphere* atmo = nullptr;
//    if (m_host != nullptr)
//    {
//        atmo = m_host->getAmosphere();
//        if ((m_sphere_renderer != nullptr) && (atmo != nullptr) && (data_manager.getPass() == COLOR_FBO))
//        {
//            atmo->sendToShader(data_manager);
//            m_sphere_renderer->render(data_manager, atmo);
//        }
//    }
//
//    for (std::vector<Planete*>::iterator it = m_moons.begin(); it != m_moons.end(); ++it)
//    {
//        if (it[0] != nullptr)
//        {
//            atmo = it[0]->getAmosphere();
//            if ((m_sphere_renderer != nullptr) && (atmo != nullptr) && (data_manager.getPass() == COLOR_FBO))
//            {
//                atmo->sendToShader(data_manager);
//                m_sphere_renderer->render(data_manager, atmo);
//            }
//        }
//    }
//    atmo = nullptr;
//}

// /***********************************************************************************************************************************************************************/
// /******************************************************************************** NOT CONCERN **************************************************************************/
// /***********************************************************************************************************************************************************************/
//void PlanetarySystem::renderFlareSun(Applications::DataManager &data_manager)
//{
//    //do nothing and doesn't have
//}