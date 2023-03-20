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

//std::vector<body_data> State::m_bodys_data;
int State::m_width;
int State::m_height;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
State::State(int width, int height, double angle) : m_terminate(false), m_event(nullptr), m_key_input(nullptr), m_mouse_input(nullptr), m_fps(60), m_render_menu(false),
key_pressed(false), m_render_overlay(true)
//bloom(true), bloom_strenght(10), render_normal(true), asteroid_count(100), ,
//render_overlay(true), render_name(true), render_info(false), distance_from_ship(3.f), index_ship(0), change_skin(true), //for loading the skin at program launch
//far_plane(1000.f), near_plane(0.1f), hilight_sun(true), render_shadow(true)
{
    /*proj_mat = glm::perspective(glm::radians(angle), (double)width / height, (double)near_plane, (double)far_plane);
    view_mat = glm::mat4(1.0f);*/

    m_width = width;
    m_height = height;

    if (m_event == nullptr)
    {
        m_event = new SDL_Event();
        assert(m_event);
    }

    if (m_key_input == nullptr)
    {
        m_key_input = new Engine::InputDevices::KeyInput(m_event);
        assert(m_key_input);
    }

    if (m_mouse_input == nullptr)
    {
        m_mouse_input = new Engine::InputDevices::MouseInput(m_event);
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

    if (m_event != nullptr)
    {
        delete m_event;
        m_event = nullptr;
    }
}

/***********************************************************************************************************************************************************************/
/**************************************************************************** listenEvents *****************************************************************************/
/***********************************************************************************************************************************************************************/
void State::listenEvents()
{
    bool tmp = this->getRenderMenu();
    if (m_key_input != nullptr)
    {
        m_key_input->updateEvents();
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
        m_mouse_input->updateEvents();
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

//
//void State::setShader()
//{
//    std::string shader_path = "Shaders/";
//
//    std::vector<shader_datas> shader_init;
//    shader_init.push_back({shader_path + "screenShader.vert", shader_path + "screenShader.frag", "NONE", "screen"});
//    shader_init.push_back({shader_path + "blur.vert", shader_path + "blur.frag", "NONE", "blur"});
//    shader_init.push_back({shader_path + "depthShader.vert", shader_path + "depthShader.frag", shader_path + "depthShader.geom", "depth_map"});
//    shader_init.push_back({shader_path + "squareShader.vert", shader_path + "squareShader.frag", "NONE", "square"});
//    shader_init.push_back({shader_path + "skybox.vert", shader_path + "skybox.frag", "NONE", "skybox"});
//    shader_init.push_back({shader_path + "model.vert", shader_path + "model.frag", "NONE", "model"});
//    shader_init.push_back({shader_path + "sunShader.vert", shader_path + "sunShader.frag", "NONE", "sun"});
//    shader_init.push_back({shader_path + "planeteShader.vert", shader_path + "uniqueTexturePlaneteShader.frag", "NONE", "simple_textured_planete"});
//    shader_init.push_back({shader_path + "planeteShader.vert", shader_path + "doubleTexturePlaneteShader.frag", "NONE", "double_textured_planete"});
//    shader_init.push_back({shader_path + "planeteShader.vert", shader_path + "earthShader.frag", "NONE", "earth"});
//    shader_init.push_back({shader_path + "ringShader.vert", shader_path + "ringShader.frag", "NONE", "ring"});
//    shader_init.push_back({shader_path + "modelInstanced.vert", shader_path + "modelInstanced.frag", "NONE", "INSTmodel"});
//    shader_init.push_back({shader_path + "sphereShader.vert", shader_path + "sphereShader.frag", "NONE", "atmosphere"});            
//    shader_init.push_back({shader_path + "flareShader.vert", shader_path + "flareShader.frag", "NONE", "flare_texture"});            
//
//    for(std::vector<shader_datas>::iterator it = shader_init.begin(); it != shader_init.end(); ++it)
//    {
//        map_shader[it[0].key] = new Shader(it[0].v_shader_path, it[0].f_shader_path, it[0].g_shader_path);
//        assert(map_shader[it[0].key]);
//        bool success = map_shader[it[0].key]->loadShader();
//        assert(success);
//    }              
//}
//
//Shader* State::getShader(std::string key)
//{
//    return map_shader[key];
//}
//
//void State::setViewMat(glm::mat4 const new_val)
//{
//    view_mat = new_val;
//}
//glm::mat4 State::getViewMat()
//{
//    return view_mat;
//}
//
//glm::mat4 State::getProjMat() const
//{
//    return proj_mat;
//}
//
//void State::lockView(glm::vec3 position, glm::vec3 target, glm::vec3 up)
//{
//    view_mat = glm::lookAt(position, target, up);
//}
//
//void State::resetViewMat(glm::mat4 const new_val)
//{
//    view_mat = new_val;
//}
//
//void State::setBloom(bool const new_val)
//{
//    bloom = new_val;
//}
//
//bool State::getBloom() const
//{
//    return bloom;
//}
//
//void State::setBloomStrength(int const new_val)
//{
//    bloom_strenght = new_val;
//}
//
//int State::getBloomStrength() const
//{
//    return bloom_strenght;
//}
//
//void State::setRenderNormal(bool const new_val)
//{
//    render_normal = new_val;
//}
//
//bool State::getRenderNormal() const
//{
//    return render_normal;
//}
//
//void State::setAsteroidCount(int const new_val)
//{
//    asteroid_count = new_val;
//}
//
//int State::getAsteroidCount() const
//{
//    return asteroid_count;
//}
//

//
//void State::setRenderName(bool const new_val)
//{
//    render_name = new_val;
//}
//
//bool State::getRenderName() const
//{
//    return render_name;
//}
//
//void State::setRenderInfo(bool const new_val)
//{
//    render_info = new_val;
//}
//
//bool State::getRenderInfo() const
//{
//    return render_info;
//}
//
//void State::setDistanceFromShip(float const new_val)
//{
//    distance_from_ship = new_val;
//}
//
//float State::getDistancteFromShip() const
//{
//    return distance_from_ship;
//}
//
//void State::setIndexShip(int const new_val)
//{
//    index_ship = new_val;
//}
//
//int State::getIndexShip() const
//{
//    return index_ship;
//}
//
//void State::setChangeSkin(bool const new_val)
//{
//    change_skin = new_val;
//}
//
//bool State::getChangeSkin() const
//{
//    return change_skin;
//}
//
//void State::setShipPos(glm::vec3 const new_val)
//{
//    ship_position = new_val;
//}
//
//glm::vec3 State::getShipPos() const
//{
//    return ship_position;
//}
//
//void State::setCamPos(glm::vec3 const new_val)
//{
//    cam_pos = new_val;
//}
//
//glm::vec3 State::getCamPos() const
//{
//    return cam_pos;
//}
//
//glm::vec3 State::getSunPos() const
//{
//    return glm::vec3(0.f) - ship_position;
//}
//
//float State::getFar() const
//{
//    return far_plane;
//}
//
//float State::getNear() const
//{
//    return near_plane;
//}
//
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
//
//void State::setDepthMapTexture(unsigned int const new_val)
//{
//    depth_map = new_val;
//}
//
//unsigned int State::getDepthMapTexture() const
//{
//    return depth_map;
//}
//
//void State::setPass(int const new_val)
//{
//    pass = new_val;
//}
//
//int State::getPass() const
//{
//    return pass;
//}
//
//void State::setHilightSun(bool const new_val)
//{
//    hilight_sun = new_val;
//}
//
//bool State::getHilightSun() const
//{
//    return hilight_sun;
//}
//
//void State::setRenderShadow(bool const new_val)
//{
//    render_shadow = new_val;
//}
//
//bool State::getRenderShadow() const
//{
//    return render_shadow;
//}
//
//void State::initDatas()
//{
//    Loader::initializeMap();
//   
//    m_bodys_data.push_back({3.f, "simple_textured_planete", 32, 0.f, glm::vec3(30.f, -30.f, 0.f), "Mercury", 0.035f, 0.9f});
//
//    m_bodys_data.push_back({3.f, "double_textured_planete", 32, 0.15f, glm::vec3(70.f, 0.f, 0.f), "Venus", 177.36f, 0.4f});
//
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(-90.f, 0.f, 0.f), "Moon", 6.687f, 0.7f});
//    m_bodys_data.push_back({3.f, "earth", 128, 0.5f, glm::vec3(-100.f, 0.f, 0.f), "Earth", 23.436f, 1.f});
//
//    m_bodys_data.push_back({3.f, "double_textured_planete", 128, 0.3f, glm::vec3(0.f, 130.f, 0.f), "Mars", 25.19f, 1.f});
//
//    m_bodys_data.push_back({5.f, "simple_textured_planete", 16, 0.f, glm::vec3(230.f, 100.f, 0.f), "Jupiter", 3.12f, 0.4f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(230.f, 110.f, 0.f), "Io", 0.f, 0.7f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(220.f, 100.f, 0.f), "Europa", 0.f, 0.7f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(230.f, 90.f, 0.f), "Callisto", 0.f, 0.9f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(230.f, 80.f, 0.f), "Ganymede", 0.f, 1.f});
//
//    m_bodys_data.push_back({5.f, "simple_textured_planete", 16, 0.f, glm::vec3(-250.f, -120.f, 0.f), "Saturn", 26.73f, 0.4f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(-230.f, -110.f, 0.f), "Mimas", 0.f, 0.8f});
//    m_bodys_data.push_back({1.f, "simple_textured_planete", 32, 0.f, glm::vec3(-250.f, -105.f, 0.f), "Enceladus", 0.f, 0.7f});
//    m_bodys_data.push_back({1.f, "double_textured_planete", 32, 1.2f, glm::vec3(-250.f, -140.f, 0.f), "Titan", 0.f, 0.6f});
//    
//    m_bodys_data.push_back({5.f, "simple_textured_planete", 16, 0.f, glm::vec3(-300.f, 200.f, 0.f), "Uranus", 97.8f, 0.4f});
//
//    m_bodys_data.push_back({5.f, "simple_textured_planete", 16, 0.f, glm::vec3(0.f, -350.f, 0.f), "Neptune", 28.32f, 0.8f});
//}
//
//body_data State::getBodyData(int index)
//{
//    return m_bodys_data[index];
//}
//
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