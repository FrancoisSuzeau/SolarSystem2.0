#include "EnginesManager.hpp"

using namespace Engine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
EnginesManager::EnginesManager() : m_GUI_manager(), m_state(nullptr), m_framebuffer()
{
    
}

EnginesManager::~EnginesManager()
{

}

/***********************************************************************************************************************************************************************/
/****************************************************************************** initGUIEngine ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::initGUIEngine()
{
    m_GUI_manager.initGUIs();
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** initRenderEngine ***********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::initRenderEngine(State *state)
{
    m_state = state;
    m_framebuffer.initFramebuffers(State::m_width, State::m_height);
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** cleanAllEngines **********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::cleanAllEngines()
{
	m_GUI_manager.clean();
    m_framebuffer.clean();
}

///***********************************************************************************************************************************************************************/
///*********************************************************************************** manage_GUI *********************************************************************/
///***********************************************************************************************************************************************************************/
void EnginesManager::manageGUI()
{
    if (m_state != nullptr)
    {
        m_GUI_manager.renderMenu(m_state->getRenderMenu());
        m_GUI_manager.renderHUD(m_state->getRenderOverlay());
        m_GUI_manager.applyUserChoice(m_state);
    }
    
}