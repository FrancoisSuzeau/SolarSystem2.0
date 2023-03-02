/*
AUTHOR : SUZEAU François

DATE : 26/05/2021

MODULE : MouseInput

NAMEFILE : MouseInput.h

PURPOSE :   - allow the program wich key is used
            - 
*/

#include "InputDevices.hpp"
using namespace Engine::InputDevices;


/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
MouseInput::MouseInput(SDL_Event* event): m_x(0), m_y(0), m_rel_x(0), m_rel_y(0), m_scroll(0), m_event(event)
{  
    //initialize mouse array
    for (int i(0); i < 8; i++)
    {
        m_mouse_button[i] = false;
    }
}

MouseInput::~MouseInput()
{
    
}

/***********************************************************************************************************************************************************************/
/************************************************************************************ UpdateEvents *********************************************************************/
/***********************************************************************************************************************************************************************/
void MouseInput::updateEvents()
{
    m_rel_x = 0;
    m_rel_y = 0;
    while(SDL_PollEvent(m_event))
    {
        
        switch (m_event->type)
        {
            
            ////click on the mouse
            case SDL_MOUSEBUTTONDOWN:
                m_mouse_button[m_event->button.button] = true;
                
                break;
            
            case SDL_MOUSEBUTTONUP:
                m_mouse_button[m_event->button.button] = false;
                break;

            //mouse is moving
            case SDL_MOUSEMOTION:
                m_x = m_event->motion.x;
                m_y = m_event->motion.y;

                m_rel_x = m_event->motion.xrel;
                m_rel_y = m_event->motion.yrel;
                break;

            //clicking on the cross
           /* case SDL_WINDOWEVENT:
                switch (m_event->window.event)
                {
                    case SDL_WINDOWEVENT_HIDDEN:
                        std::cout << "Window %d hidden" << m_event->window.windowID << std::endl;
                        break;
                    case SDL_WINDOWEVENT_SHOWN:
                        std::cout << "Window %d shown" << m_event->window.windowID << std::endl;
                        break;
                    case SDL_WINDOWEVENT_CLOSE:
                        std::cout << "Window %d closed" << m_event->window.windowID << std::endl;
                        break;
                }
                break;*/

            //scrolling
            case SDL_MOUSEWHEEL:

                if(m_event->wheel.y > 0) //goes up
                {
                    m_scroll = 1;
                }

                if(m_event->wheel.y < 0) //goes down
                {
                    m_scroll = -1;
                }

                break;

            default:
                break;
        }
    }

}


/***********************************************************************************************************************************************************************/
/*********************************************************************************** getMouseButton ********************************************************************/
/***********************************************************************************************************************************************************************/
bool MouseInput::getMouseButton(const Uint8 button) const
{
    return m_mouse_button[button];
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** getMouseMotion ********************************************************************/
/***********************************************************************************************************************************************************************/
bool MouseInput::getMouseMotion() const
{
    if( ( m_rel_x == 0 ) && ( m_rel_y == 0 ) )
    {
        return false;
    }
    else
    {
        return true;
    }
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** getterPosition ********************************************************************/
/***********************************************************************************************************************************************************************/
int MouseInput::getX() const
{
    return m_x;
}

int MouseInput::getY() const
{
    return m_y;
}

int MouseInput::getXRel() const
{
    return m_rel_x;
}

int MouseInput::getYRel() const
{
    return m_rel_y;
}

int MouseInput::getScroll()
{
    if(m_scroll != 0)
    {
        float tmp = m_scroll;
        m_scroll = 0;
        return tmp;
    }

    return 0;
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** displayPointer ********************************************************************/
/***********************************************************************************************************************************************************************/
void MouseInput::displayPointer(bool response) const
{
    if(response)
    {
        if(SDL_ShowCursor(SDL_ENABLE) < 0)
        {
            std::cout << ">> Showing cursor : ERROR !" << SDL_GetError() << std::endl;
        }
    }
    else
    {
        if(SDL_ShowCursor(SDL_DISABLE) < 0)
        {
            std::cout << ">> Not Showing cursor : ERROR !" << SDL_GetError() << std::endl;
        }
    }
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** CpaturePointer ********************************************************************/
/***********************************************************************************************************************************************************************/
void MouseInput::capturePointer(bool response) const
{
    if(response)
    {
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }
    else
    {
        SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}
