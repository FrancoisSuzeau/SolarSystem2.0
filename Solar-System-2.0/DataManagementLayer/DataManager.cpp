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

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
DataManager::DataManager(): preference_data(nullptr), bodies_data(nullptr), nb_bodies(0), nb_shaders(0), shaders_data(nullptr), spaceships_data(nullptr), nb_spaceships(0),
skybox_paths(nullptr), musics_data(nullptr), nb_musics(0), sun_data(nullptr)
{
    if (preference_data == nullptr)
    {
        preference_data = Loader::loadJsonObject("preference_data");
        assert(preference_data);
    }
    if (bodies_data == nullptr)
    {
        bodies_data = Loader::loadJsonObject("bodies_data");
        assert(bodies_data);
    }
    if (shaders_data == nullptr)
    {
        shaders_data = Loader::loadJsonObject("shaders_data");
        assert(shaders_data);
    }
    if (spaceships_data == nullptr)
    {
        spaceships_data = Loader::loadJsonObject("spaceships_data");
        assert(spaceships_data);
    }
    if (skybox_paths == nullptr)
    {
        skybox_paths = Loader::loadJsonObject("skybox_paths");
        assert(skybox_paths);
    }
    if (musics_data == nullptr)
    {
        musics_data = Loader::loadJsonObject("musics_data");
        assert(musics_data);
    }

    if (sun_data == nullptr)
    {
        sun_data = Loader::loadJsonObject("sun_data");
        assert(sun_data);
    }

    nb_spaceships = spaceships_data->SizeOfArray("spaceships");
    nb_bodies = bodies_data->SizeOfArray("bodies");
    nb_shaders = shaders_data->SizeOfArray("shaders");
    nb_musics = musics_data->SizeOfArray("tracks");
    
}

DataManager::~DataManager()
{
    
}

/***********************************************************************************************************************************************************************/
/*********************************************************************************** clean *****************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::clean(int const which_one)
{
    switch (which_one)
    {
        case PREFERENCE:
            if (preference_data != nullptr)
            {
                delete preference_data;
                preference_data = nullptr;
            }
            break;
        case BODIESDATA:
            if (bodies_data != nullptr)
            {
                delete bodies_data;
                bodies_data = nullptr;
            }
            break;
        case SHADERSDATA:
            if (shaders_data != nullptr)
            {
                delete shaders_data;
                shaders_data = nullptr;
            }
            break;
        case SPACESHIPSDATA:
            if (spaceships_data != nullptr)
            {
                delete spaceships_data;
                spaceships_data = nullptr;
            }
            break;
        case SKYBOXPATHS:
            if (skybox_paths != nullptr)
            {
                delete skybox_paths;
                skybox_paths = nullptr;
            }
            break;
        case MUSICSDATA:
            if (musics_data != nullptr)
            {
                delete musics_data;
                musics_data = nullptr;
            }
            break;
        case SUNDATA:
            if (sun_data != nullptr)
            {
                delete sun_data;
                sun_data = nullptr;
            }
            break;
        default:
            break;
    }
}

/***********************************************************************************************************************************************************************/
/********************************************************************** getters / setters ******************************************************************************/
/***********************************************************************************************************************************************************************/
void DataManager::setConfigs(Engine::State* state)
{
    state->setFps(preference_data->IntOf("fps"));
    state->setRenderOverlay(preference_data->BoolOf("render_overlay"));
    state->setSpaceshipName(preference_data->stringOf("spaceship_name"));
    state->setBloomStrength(preference_data->IntOf("bloom_strenght"));
    state->setBloom(preference_data->BoolOf("bloom"));
    state->setHilightSun(preference_data->BoolOf("highlight_sun"));
    state->setDistanceFromShip(std::stof(preference_data->stringOf("distance_from_ship")));
    state->setRenderNormal(preference_data->BoolOf("render_normal"));
    state->setRenderShadow(preference_data->BoolOf("render_shadow"));
    state->setAsteroidCount(preference_data->IntOf("asteroid_count"));
    state->setRenderName(preference_data->BoolOf("render_name"));
    state->setRenderInfo(preference_data->BoolOf("render_info"));

}

std::string DataManager::getTexturePath(int i, std::string texture_type)
{
    bodies_data->put_I(i);
    std::string jsonPath = "bodies[i].texture_" + texture_type + "_path";
    std::string path = bodies_data->stringOf(jsonPath.c_str());
    

    return path;
}

GLuint DataManager::getTextureId(std::string const path) const
{
    /*if (path != "")
    {
        id = Loader::loadTextureWithSDL(path);
    }*/
    return 0;
}

int DataManager::getNbBodies() const
{
    return nb_bodies;
}

int DataManager::getNbShaders() const
{
    return nb_shaders;
}

void DataManager::setShaderPaths(int i)
{
    shaders_data->put_I(i);
}

std::vector <std::string> DataManager::getSkyboxPath()
{
    std::vector<std::string> skybox_path;
    skybox_path.reserve(6);
    skybox_path.push_back(skybox_paths->stringOf("right"));
    skybox_path.push_back(skybox_paths->stringOf("left"));
    skybox_path.push_back(skybox_paths->stringOf("up"));
    skybox_path.push_back(skybox_paths->stringOf("bottom"));
    skybox_path.push_back(skybox_paths->stringOf("front"));
    skybox_path.push_back(skybox_paths->stringOf("back"));
    
    return skybox_path;
}

unsigned int DataManager::getSkyboxTexture(std::vector<std::string> skybox_paths) const
{
    unsigned int ret = Loader::loadSkyboxTextures(skybox_paths);
    assert(ret != 0);
    return ret;
}

int DataManager::getNbSpaceships() const
{
    return nb_spaceships;
}

int DataManager::getNbMusics() const
{
    return nb_musics;
}

int DataManager::getIfrom(std::string jsonObject) const
{
    if (jsonObject.compare("music") == 0)
    {
        return musics_data->get_I();
    }
    if (jsonObject.compare("shader") == 0)
    {
        return shaders_data->get_I();
    }
    if (jsonObject.compare("bodies") == 0)
    {
        return bodies_data->get_I();
    }
    if (jsonObject.compare("spaceship") == 0)
    {
        return spaceships_data->get_I();
    }
    
    return -1;
}

body_data DataManagementLayer::DataManager::getCurrentBodyData() const
{
    float x = std::stof(bodies_data->stringOf("bodies[i].x"));
    float y = std::stof(bodies_data->stringOf("bodies[i].y"));
    float z = std::stof(bodies_data->stringOf("bodies[i].z"));
    return body_data(
        {
            bodies_data->stringOf("bodies[i].name"),
            0,
            0,
            0,
            0,
            std::stof(bodies_data->stringOf("bodies[i].size")),
            bodies_data->stringOf("bodies[i].host_name"),
            bodies_data->IntOf("bodies[i].shininess"),
            std::stof(bodies_data->stringOf("bodies[i].oppacity")),
            glm::vec3(x, y, z),
            std::stof(bodies_data->stringOf("bodies[i].inclinaison_angle")),
            std::stof(bodies_data->stringOf("bodies[i].light_strength")),
            std::stof(bodies_data->stringOf("bodies[i].speed_rotation"))
        }
    );
}

std::vector<imgui_datas> DataManager::getImGuiTexture() const
{
    std::vector<imgui_datas> tmp;
    tmp.reserve(nb_spaceships);
    for (int i = 0; i < nb_spaceships; i++)
    {
        spaceships_data->put_I(i);
        std::string path = spaceships_data->stringOf("spaceships[i].imgui_image_path");
        int w = 0;
        int h = 0;
        GLuint tex_id = 0;
        std::string name = spaceships_data->stringOf("spaceships[i].name");
        bool success = Loader::loadWithStbi(path, tex_id, w, h);
        assert(success);
        tmp.push_back({ w, h, tex_id, name });
    }

    return tmp;
}

body_data DataManager::getSunData() const
{
    return body_data(
        {
            "sun",
            Loader::loadTextureWithSDL(sun_data->stringOf("texture")),
            0,
            0,
            0,
            std::stof(sun_data->stringOf("size"))
        }
    );
}

std::map<std::string, std::string> DataManager::getShaderPaths()
{
    return std::map<std::string, std::string>(
        {
            std::make_pair("name", shaders_data->stringOf("shaders[i].name")),
            std::make_pair("v_path", shaders_data->stringOf("shaders[i].v_shader_path")),
            std::make_pair("f_path", shaders_data->stringOf("shaders[i].f_shader_path")),
            std::make_pair("g_path", shaders_data->stringOf("shaders[i].g_shader_path"))
        }
    );
}

std::string DataManager::setAndGetMusicPath(int i, std::string const radio)
{
   
    musics_data->put_I(i);
    if (musics_data->stringOf("tracks[i].radio") == radio)
    {
        return musics_data->stringOf("tracks[i].path");
    }
    else
    {
        return "NONE";
    }
    
}

Mix_Music* DataManager::getMusic()
{
    return Loader::loadWithSDLMixer(musics_data->stringOf("tracks[i].path"));
}

std::map<std::string, std::string> DataManager::getMusicInfo()
{
    return std::map<std::string, std::string>(
        {
            std::make_pair("title", musics_data->stringOf("tracks[i].title")),
            std::make_pair("author", musics_data->stringOf("tracks[i].author")),
            std::make_pair("studio", musics_data->stringOf("tracks[i].studio"))
        }
    
    );
}

std::string DataManager::setAndGetSpaceshipPath(std::string const prefered_ship)
{
    for (int i = 0; i < nb_spaceships; i++)
    {
        spaceships_data->put_I(i);
        std::string name = spaceships_data->stringOf("spaceships[i].name");
        
        if (prefered_ship == name)
        {
            return spaceships_data->stringOf("spaceships[i].blender_path");
        }
    }

    return "NONE";
}

std::string DataManager::setAndGetSpaceshipPath(int i)
{
    if (i >= 0 && i < nb_spaceships)
    {
        spaceships_data->put_I(i);
        return spaceships_data->stringOf("spaceships[i].blender_path");
    }

    return "NONE";
}
