/*
AUTHOR : SUZEAU François

DATE : 23/11/2021

MODULE : State

NAMEFILE : State.hpp

PURPOSE :   - Manage data transfert between all module of the application program
            - Store datas references (for texture, render, settings)
*/

#include "State.hpp"
using namespace Engine;


int State::m_width;
int State::m_height;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
State::State(int width, int height, double angle) : m_terminate(false), m_key_input(nullptr), m_mouse_input(nullptr), m_fps(60), m_render_menu(false),
key_pressed(false), m_render_overlay(false), far_plane(1000.f), near_plane(0.1f), bloom(false), bloom_strenght(10), distance_from_ship(0.f), hilight_sun(false), render_shadow(true),
render_normal(true), depth_map(0), asteroid_count(2000), render_name(true), render_info(false), render_music_hud(true), render_nav(true)
{
    proj_mat = glm::perspective(glm::radians(angle), (double)width / height, (double)near_plane, (double)far_plane);
    view_mat = glm::mat4(1.0f);

    m_width = width;
    m_height = height;

    if (m_key_input == nullptr)
    {
        m_key_input = new Engine::InputDevices::KeyInput();
        assert(m_key_input);
    }

    if (m_mouse_input == nullptr)
    {
        m_mouse_input = new Engine::InputDevices::MouseInput();
        assert(m_mouse_input);
    }
}

State::~State()
{
    
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* clean *******************************************************************************/
/***********************************************************************************************************************************************************************/
void State::clean()
{
    if (m_key_input != nullptr)
    {
        delete m_key_input;
        m_key_input = nullptr;
    }

    if (m_mouse_input != nullptr)
    {
        delete m_mouse_input;
        m_mouse_input = nullptr;
    }
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** listenEvents *****************************************************************************/
/***********************************************************************************************************************************************************************/
void State::listenEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        m_key_input->updateEvents(event);
        m_mouse_input->updateEvents(event);
    }
    bool tmp = this->getRenderMenu();
    if (m_key_input != nullptr)
    {
        if ((m_key_input->getKey(SDL_SCANCODE_ESCAPE)) && (!key_pressed))
        {
            this->setRenderMenu(!tmp);
            key_pressed = true;
        }
        if ((m_key_input->getKey(SDL_SCANCODE_ESCAPE)) == false)
        {
            key_pressed = false;
        }
    }
    if (m_mouse_input != nullptr)
    {
        
        if (this->m_render_menu)
        {
            m_mouse_input->capturePointer(false);
            m_mouse_input->displayPointer(true);
        }
        else
        {
            m_mouse_input->capturePointer(true);
            m_mouse_input->displayPointer(false);
        }
    }
    
}

///***********************************************************************************************************************************************************************/
///********************************************************************************* getters/setters *********************************************************************/
///***********************************************************************************************************************************************************************/
void State::setTerminate(bool const terminate)
{
    m_terminate = terminate;
}

bool State::getTerminate() const
{
    return m_terminate;
}

void State::setRenderMenu(bool const value)
{
    m_render_menu = value;
}

bool State::getRenderMenu() const
{
    return m_render_menu;
}

void State::setFps(unsigned int const fps)
{
    m_fps = fps;
}

unsigned int State::getFps() const
{
    return m_fps;
}

void State::setRenderOverlay(bool const new_val)
{
    m_render_overlay = new_val;
}

bool State::getRenderOverlay() const
{
    return m_render_overlay;
}

void State::setSpaceshipName(std::string const name)
{
    m_spaceship_name = name;
}

std::string State::getSpaceshipName() const
{
    return m_spaceship_name;
}

void State::setChangeTrack(bool const new_val)
{
    m_change_track = new_val;
}

bool State::getChangeTrack() const
{
    return m_change_track;
}

void State::setViewMat(glm::mat4 const new_val)
{
    view_mat = new_val;
}
glm::mat4 State::getViewMat() const
{
    return view_mat;
}

glm::mat4 State::getProjMat() const
{
    return proj_mat;
}

void State::lockView(glm::vec3 position, glm::vec3 target, glm::vec3 up)
{
    view_mat = glm::lookAt(position, target, up);
}

void State::resetViewMat(glm::mat4 const new_val)
{
    view_mat = new_val;
}

float State::getFar() const
{
    return far_plane;
}

float State::getNear() const
{
    return near_plane;
}

void State::setPass(int const new_val)
{
    pass = new_val;
}

int State::getPass() const
{
    return pass;
}

void State::setBloom(bool const new_val)
{
    bloom = new_val;
}

bool State::getBloom() const
{
    return bloom;
}

void State::setBloomStrength(int const new_val)
{
    bloom_strenght = new_val;
}

int State::getBloomStrength() const
{
    return bloom_strenght;
}

InputDevices::KeyInput State::getKeyInput() const
{
    return *m_key_input;
}

InputDevices::MouseInput State::getMouseInput() const
{
    return *m_mouse_input;
}

void State::setDistanceFromShip(float const new_val)
{
    distance_from_ship = new_val;
}

float State::getDistancteFromShip() const
{
    return distance_from_ship;
}

void State::setCamPos(glm::vec3 const new_val)
{
    cam_pos = new_val;
}

glm::vec3 State::getCamPos() const
{
    return cam_pos;
}

void State::setShipPos(glm::vec3 const new_val)
{
    ship_position = new_val;
}

glm::vec3 State::getShipPos() const
{
    return ship_position;
}

glm::vec3 State::getSunPos() const
{
    return glm::vec3(0.f) - ship_position;
}

void State::setNewBody(bool const value)
{
    new_body_is_load = value;
}

bool State::getNewBody() const
{
    return new_body_is_load;
}

void State::setHilightSun(bool const new_val)
{
    hilight_sun = new_val;
}

bool State::getHilightSun() const
{
    return hilight_sun;
}

void State::setRenderNormal(bool const new_val)
{
    render_normal = new_val;
}

bool State::getRenderNormal() const
{
    return render_normal;
}

void State::setRenderShadow(bool const new_val)
{
    render_shadow = new_val;
}

bool State::getRenderShadow() const
{
    return render_shadow;
}

void State::setDepthMapTexture(unsigned int const new_val)
{
    depth_map = new_val;
}

unsigned int State::getDepthMapTexture() const
{
    return depth_map;
}

void State::setAsteroidCount(int const new_val)
{
    asteroid_count = new_val;
}

int State::getAsteroidCount() const
{
    return asteroid_count;
}

void State::setRenderName(bool const new_val)
{
    render_name = new_val;
}

bool State::getRenderName() const
{
    return render_name;
}

void State::setRenderInfo(bool const new_val)
{
    render_info = new_val;
}

bool State::getRenderInfo() const
{
    return render_info;
}

void State::setRenderNav(bool const new_val)
{
    render_nav = new_val;
}

bool State::getRenderNav() const
{
    return render_nav;
}

void State::setRenderMusic(bool const new_val)
{
    render_music_hud = new_val;
}

bool State::getRenderMusic() const
{
    return render_music_hud;
}



//std::vector<glm::mat4> State::getLightSpaceMatrix()
//{
//    glm::vec3 lightPos = this->getSunPos();
//    
//    glm::mat4 shadowProj = glm::perspective(glm::radians(90.f), (float) this->getWidth()/(float)this->getWidth(), (float)this->near_plane, (float)this->far_plane);
//    // glm::mat4 shadowProj = glm::ortho(-100.f, 100.f, -100.f, 100.f, (float)this->near_plane, (float)this->far_plane);
//    std::vector<glm::mat4> shadowTransforms;
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
//    shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
//
//    return shadowTransforms;
//
//}

//glm::vec2 State::convertToScreenSpace(glm::vec3 const body_pos)
//{
//    glm::mat4 model_matrix = glm::translate(glm::mat4(1.0f), body_pos);
//    glm::mat4 mvp_matrix = this->proj_mat * this->view_mat * model_matrix;
//
//    glm::vec4 clipSpacePos = mvp_matrix * glm::vec4(body_pos, 1.0f);
//
//    if(clipSpacePos.w <= 0)
//    {
//        return glm::vec2(-100.f); // NULL
//    }
//
//    float x = (clipSpacePos.x / clipSpacePos.w + 1) / 2.0f; 
//    float y = 1 - ((clipSpacePos.y / clipSpacePos.w + 1) / 2.0f);
//
//
//    return glm::vec2(x, y);
//}
//
//glm::vec3 State::getShipOrientation() const
//{
//    return ship_orientation;
//}
//
//void State::setShipOrientation(glm::vec3 const new_val)
//{
//    ship_orientation = new_val;
//}
