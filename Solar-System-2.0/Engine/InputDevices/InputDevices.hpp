/*
AUTHOR : SUZEAU François

DATE : 26/05/2021

MODULE : MouseInput

NAMEFILE : MouseInput.h

PURPOSE : header of the MouseInput class
*/

#ifndef KEYINPUT_H
#define KEYINPUT_H


/********************************************************************* includes *********************************************************************/
        
        #include <SDL2/SDL.h>
        #include <iostream>
        #include <string>
        

/********************************************************************* class definition *********************************************************************/

    namespace Engine {

        namespace InputDevices {


            class KeyInput
            {

                private:

                    SDL_Event* m_event;
                    bool        m_keys[SDL_NUM_SCANCODES];

                public:

                    KeyInput(SDL_Event* m_event);
                    ~KeyInput();

                    void updateEvents();
                    bool getKey(const SDL_Scancode key) const;

                };


            class MouseInput
            {

                private:

                    SDL_Event   *m_event;
                    bool        m_mouse_button[8];
                    int         m_x;
                    int         m_y;
                    int         m_rel_x;
                    int         m_rel_y;
                    int         m_scroll;




                public:

                    MouseInput(SDL_Event* m_event);
                    ~MouseInput();

                    void updateEvents();

                    bool getMouseButton(const Uint8 button) const; //application crash with Uint32
                    bool getMouseMotion() const;

                    int getX() const;
                    int getY() const;

                    int getXRel() const;
                    int getYRel() const;

                    int   getScroll();

                    void displayPointer(bool response) const;

                    void capturePointer(bool response) const;

            };


        }


    }
        
#endif