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
//int DataManager::m_width;
//int DataManager::m_height;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
DataManager::DataManager(int width, int height, double angle) //:
//bloom(true), bloom_strenght(10), render_normal(true), asteroid_count(100), m_fps(60),
//render_overlay(true), render_name(true), render_info(false), distance_from_ship(3.f), index_ship(0), change_skin(true), //for loading the skin at program launch
//far_plane(1000.f), near_plane(0.1f), hilight_sun(true), render_shadow(true)
{
    /*proj_mat = glm::perspective(glm::radians(angle), (double)width / height, (double)near_plane, (double)far_plane);
    view_mat = glm::mat4(1.0f);

    m_width = width;
    m_height = height; */
}

DataManager::~DataManager()
{
    
}

/***********************************************************************************************************************************************************************/
/********************************************************************************* clean *******************************************************************************/
/***********************************************************************************************************************************************************************/
//void DataManager::clean()
//{
//    for(std::map<std::string, Shader*>::iterator it = map_shader.begin(); it != map_shader.end(); ++it)
//    {
//        if(it->second != nullptr)
//        {
//            it->second->clean();
//            delete it->second;
//            it->second = nullptr;
//        }
//    }
//}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************* getters/setters *********************************************************************/
///***********************************************************************************************************************************************************************/
//void DataManager::setTerminate(bool const terminate)
//{
//    m_terminate = terminate;
//}
//
//bool DataManager::getTerminate() const
//{
//    return m_terminate;
//}
//
//int DataManager::getWidth()
//{
//    return m_width;
//}
//
//int DataManager::getHeight()
//{
//    return m_height;
//}
//
//void DataManager::setFps(unsigned int const fps)
//{
//    m_fps = fps;
//}
//
//unsigned int DataManager::getFps() const
//{
//    return m_fps;
//}
//
//void DataManager::setVolume(int const volume)
//{
//    m_volume = volume;
//}
//
//int DataManager::getVolume() const
//{
//    return m_volume;
//}
//
//void DataManager::setPause(bool const pause)
//{
//    m_pause_music = pause;
//} 
//
//bool DataManager::getPause() const
//{
//    return m_pause_music;
//}
//
//void DataManager::setTrack(int const track)
//{
//    m_track = track;
//}
//
//int DataManager::getTrack() const
//{
//    return m_track;
//}
//
//void DataManager::setShader()
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
//Shader* DataManager::getShader(std::string key)
//{
//    return map_shader[key];
//}
//
//void DataManager::setViewMat(glm::mat4 const new_val)
//{
//    view_mat = new_val;
//}
//glm::mat4 DataManager::getViewMat()
//{
//    return view_mat;
//}
//
//glm::mat4 DataManager::getProjMat() const
//{
//    return proj_mat;
//}
//
//void DataManager::lockView(glm::vec3 position, glm::vec3 target, glm::vec3 up)
//{
//    view_mat = glm::lookAt(position, target, up);
//}
//
//void DataManager::resetViewMat(glm::mat4 const new_val)
//{
//    view_mat = new_val;
//}
//
//void DataManager::setBloom(bool const new_val)
//{
//    bloom = new_val;
//}
//
//bool DataManager::getBloom() const
//{
//    return bloom;
//}
//
//void DataManager::setBloomStrength(int const new_val)
//{
//    bloom_strenght = new_val;
//}
//
//int DataManager::getBloomStrength() const
//{
//    return bloom_strenght;
//}
//
//void DataManager::setRenderNormal(bool const new_val)
//{
//    render_normal = new_val;
//}
//
//bool DataManager::getRenderNormal() const
//{
//    return render_normal;
//}
//
//void DataManager::setAsteroidCount(int const new_val)
//{
//    asteroid_count = new_val;
//}
//
//int DataManager::getAsteroidCount() const
//{
//    return asteroid_count;
//}
//
//void DataManager::setRenderOverlay(bool const new_val)
//{
//    render_overlay = new_val;
//}
//
//bool DataManager::getRenderOverlay() const
//{
//    return render_overlay;
//}
//
//void DataManager::setRenderName(bool const new_val)
//{
//    render_name = new_val;
//}
//
//bool DataManager::getRenderName() const
//{
//    return render_name;
//}
//
//void DataManager::setRenderInfo(bool const new_val)
//{
//    render_info = new_val;
//}
//
//bool DataManager::getRenderInfo() const
//{
//    return render_info;
//}
//
//void DataManager::setDistanceFromShip(float const new_val)
//{
//    distance_from_ship = new_val;
//}
//
//float DataManager::getDistancteFromShip() const
//{
//    return distance_from_ship;
//}
//
//void DataManager::setIndexShip(int const new_val)
//{
//    index_ship = new_val;
//}
//
//int DataManager::getIndexShip() const
//{
//    return index_ship;
//}
//
//void DataManager::setChangeSkin(bool const new_val)
//{
//    change_skin = new_val;
//}
//
//bool DataManager::getChangeSkin() const
//{
//    return change_skin;
//}
//
//void DataManager::setShipPos(glm::vec3 const new_val)
//{
//    ship_position = new_val;
//}
//
//glm::vec3 DataManager::getShipPos() const
//{
//    return ship_position;
//}
//
//void DataManager::setCamPos(glm::vec3 const new_val)
//{
//    cam_pos = new_val;
//}
//
//glm::vec3 DataManager::getCamPos() const
//{
//    return cam_pos;
//}
//
//glm::vec3 DataManager::getSunPos() const
//{
//    return glm::vec3(0.f) - ship_position;
//}
//
//float DataManager::getFar() const
//{
//    return far_plane;
//}
//
//float DataManager::getNear() const
//{
//    return near_plane;
//}
//
//std::vector<glm::mat4> DataManager::getLightSpaceMatrix()
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
//void DataManager::setDepthMapTexture(unsigned int const new_val)
//{
//    depth_map = new_val;
//}
//
//unsigned int DataManager::getDepthMapTexture() const
//{
//    return depth_map;
//}
//
//void DataManager::setPass(int const new_val)
//{
//    pass = new_val;
//}
//
//int DataManager::getPass() const
//{
//    return pass;
//}
//
//void DataManager::setHilightSun(bool const new_val)
//{
//    hilight_sun = new_val;
//}
//
//bool DataManager::getHilightSun() const
//{
//    return hilight_sun;
//}
//
//void DataManager::setRenderShadow(bool const new_val)
//{
//    render_shadow = new_val;
//}
//
//bool DataManager::getRenderShadow() const
//{
//    return render_shadow;
//}
//
//void DataManager::initDatas()
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
//body_data DataManager::getBodyData(int index)
//{
//    return m_bodys_data[index];
//}
//
//glm::vec2 DataManager::convertToScreenSpace(glm::vec3 const body_pos)
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
//glm::vec3 DataManager::getShipOrientation() const
//{
//    return ship_orientation;
//}
//
//void DataManager::setShipOrientation(glm::vec3 const new_val)
//{
//    ship_orientation = new_val;
//}