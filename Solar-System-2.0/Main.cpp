/*
AUTHOR : SUZEAU François

DATE : 26/02/2023

NAMEFILE : Main.cpp

PURPOSE :
*/

#include <iostream>
#include <cassert>
#include "InitializeManagement/ContextManager.hpp"

int main(int argc, char** argv)
{
    InitializeManagement::Sdl_manage sdl_manager;
    SDL_GLContext opengl_context = 0;
    GLenum init_glew = 0;
    ImGuiIO io;
    bool status;

    status = InitializeManagement::ContextManager::Init(sdl_manager);
    assert(status);
    status = InitializeManagement::ContextManager::Init(opengl_context, sdl_manager.window);
    assert(status);
    status = InitializeManagement::ContextManager::Init(init_glew, opengl_context, sdl_manager.window);
    assert(status);
    InitializeManagement::ContextManager::Init(opengl_context, sdl_manager.window, io);



    InitializeManagement::ContextManager::DeInit();
    InitializeManagement::ContextManager::DeInit(opengl_context);
    InitializeManagement::ContextManager::DeInit(sdl_manager);

    return EXIT_SUCCESS;

}