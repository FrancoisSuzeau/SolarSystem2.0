#include "EnginesManager.hpp"

using namespace Engine;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
EnginesManager::EnginesManager() : m_GUI_manager(), m_state(nullptr), m_framebuffer(), m_planete_renderer(nullptr), m_ring_renderer(nullptr), m_sphere_renderer(nullptr),
m_square_renderer(nullptr)
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
    if (m_planete_renderer == nullptr)
    {
        m_planete_renderer = new RenderingEngine::PlaneteRenderer(1.f, 70.f, 70.f);
        assert(m_planete_renderer);
    }
    if (m_ring_renderer == nullptr)
    {
        m_ring_renderer = new RenderingEngine::RingRenderer();
        assert(m_ring_renderer);
    }
    if (m_sphere_renderer == nullptr)
    {
        m_sphere_renderer = new RenderingEngine::SphereRenderer(1.f, 70.f, 70.f);
        assert(m_sphere_renderer);
    }
    if (m_square_renderer == nullptr)
    {
        m_square_renderer = new RenderingEngine::SquareRenderer(1.f);
        assert(m_square_renderer);
    }
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************** cleanAllEngines **********************************************************************/
/***********************************************************************************************************************************************************************/
void EnginesManager::cleanAllEngines()
{
	m_GUI_manager.clean();
    m_framebuffer.clean();
    if (m_planete_renderer != nullptr)
    {
        m_planete_renderer->clean();
        delete m_planete_renderer;
        m_planete_renderer = nullptr;
    }
    if (m_ring_renderer != nullptr)
    {
        m_ring_renderer->clean();
        delete m_ring_renderer;
        m_ring_renderer = nullptr;
    }
    if (m_sphere_renderer != nullptr)
    {
        m_sphere_renderer->clean();
        delete m_sphere_renderer;
        m_sphere_renderer = nullptr;
    }
    if (m_square_renderer != nullptr)
    {
        m_square_renderer->clean();
        delete m_square_renderer;
        m_square_renderer = nullptr;
    }
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