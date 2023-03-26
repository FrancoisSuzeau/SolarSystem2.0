/*
AUTHOR : SUZEAU François

DATE : 17/10/2021

MODULE : Spaceship

NAMEFILE : Spaceship.cpp

PURPOSE : class Spaceship

*/

#include "Spaceship.hpp"
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Spaceship::Spaceship(std::string const type) : super(type), m_yaw(0.0f), m_pitch(90.0f), m_speed(0.0f), speed_limit(0.05f), m_index_skin(0), m_model(nullptr)
{   
    m_scales.push_back(0.1f);
    m_scales.push_back(3.0f);
    m_scales.push_back(0.1f);

    super::m_model_mat = glm::mat4(1.f);

    super::m_position = glm::vec3(0.f, 100.f, 0.f);
    directions[0] = false;
    directions[1] = false;
    directions[2] = false;
    directions[3] = false;
    directions[4] = false;
    directions[5] = false;

    m_sensibility[0] = 0.0f;
    m_sensibility[1] = 0.0f;

    y_dir = 0.0f;
    x_dir = 0.0f;
}

Spaceship::~Spaceship()
{
    
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* transform *************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::transform(InputDevices::KeyInput key_input, InputDevices::MouseInput mouse_input, glm::vec3 ship_pos)
{
    this->move(key_input);
    super::m_model_mat = glm::mat4(1.0f);
    this->orientateShip(mouse_input);
    super::m_model_mat *= (yaw_mat * pitch_mat);
    super::scaleObject(super::m_model_mat, glm::vec3(m_scales[m_index_skin]));
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* clean *************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::clean()
{
    if(m_model != nullptr)
    {
        m_model->clean();
        delete m_model;
        m_model = nullptr;

    }
}

/***********************************************************************************************************************************************************************/
/****************************************************************************** sendToShader ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::sendToShader()
{
    //DO NOTHING
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* drawSpaceship *************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::render(RenderingEngine::Shader *shader)
{
    if (m_model != nullptr)
    {
        m_model->render(shader);
    }
}

/***********************************************************************************************************************************************************************/
/*************************************************************************************** move **************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::move(InputDevices::KeyInput key_input)
{
    if (key_input.getKey(SDL_SCANCODE_W))
    {
        m_position += m_ship_orientation * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }
        directions[0] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_W) && directions[0])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position += m_ship_orientation * m_speed;
        }
        else
        {
            directions[0] = false;
        }

    }

    if (key_input.getKey(SDL_SCANCODE_S))
    {
        m_position -= m_ship_orientation * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }
        directions[1] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_S) && directions[1])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position -= m_ship_orientation * m_speed;
        }
        else
        {
            directions[1] = false;
        }
    }

    if (key_input.getKey(SDL_SCANCODE_A))
    {
        m_position += m_lateral_move * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }

        directions[2] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_A) && directions[2])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position += m_lateral_move * m_speed;
        }
        else
        {
            directions[2] = false;
        }
    }

    if (key_input.getKey(SDL_SCANCODE_D))
    {
        m_position -= m_lateral_move * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }
        directions[3] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_D) && directions[3])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position -= m_lateral_move * m_speed;
        }
        else
        {
            directions[3] = false;
        }
    }

    if (key_input.getKey(SDL_SCANCODE_LSHIFT))
    {
        m_position += glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)) * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }
        directions[4] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_LSHIFT) && directions[4])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position += glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)) * m_speed;
        }
        else
        {
            directions[4] = false;
        }
    }

    if (key_input.getKey(SDL_SCANCODE_LCTRL))
    {
        m_position -= glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)) * m_speed;
        if (m_speed < speed_limit)
        {
            m_speed += 1.0f;
        }
        directions[5] = true;
    }
    else if (!key_input.getKey(SDL_SCANCODE_LCTRL) && directions[5])
    {
        if (m_speed >= 1.0f)
        {
            m_speed -= 1.0f;
            m_position -= glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f)) * m_speed;
        }
        else
        {
            directions[5] = false;
        }
    }
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* orientateShip *************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::orientateShip(InputDevices::MouseInput mouse_input)
{
    this->changePitch(mouse_input);
    m_rotation_vector = glm::vec3(1.0f, 0.0f, 0.0f);
    super::rotateObject(pitch_mat, m_pitch);

    this->changeYaw(mouse_input);
    m_rotation_vector = glm::vec3(0.0f, 0.0f, 1.0f);
    super::rotateObject(yaw_mat, m_yaw);

    glm::vec3 dir;
    dir.x = sin(glm::radians(m_yaw));
    dir.y = -cos(glm::radians(m_yaw));
    dir.z = cos(glm::radians(m_pitch));

    m_ship_orientation = glm::normalize(dir);

    m_lateral_move = cross(glm::vec3(0.0f, 0.0f, 1.0f), m_ship_orientation);
    m_lateral_move = normalize(m_lateral_move);

}

/***********************************************************************************************************************************************************************/
/*************************************************************************** changePitch ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::changePitch(InputDevices::MouseInput mouse_input)
{
   pitch_mat = glm::mat4(1.0f);

    if (mouse_input.getMouseButton(SDL_BUTTON_LEFT))
    {
        y_dir = mouse_input.getYRel();
        m_pitch += y_dir * m_sensibility[0];
        if (m_sensibility[0] < 0.3)
        {
            m_sensibility[0] += 0.01;
        }

        if (m_pitch > 179.0f)
        {
            m_pitch = 179.0f;
        }
        else if (m_pitch < -0.1f)
        {
            m_pitch = -0.1f;
        }
    }
    else if (!mouse_input.getMouseButton(SDL_BUTTON_LEFT))
    {
        if (m_sensibility[0] >= 0.01)
        {
            m_sensibility[0] -= 0.01;
        }

        m_pitch += y_dir * m_sensibility[0];

        if (m_pitch > 179.0f)
        {
            m_pitch = 179.0f;
        }
        else if (m_pitch < -0.1f)
        {
            m_pitch = -0.1f;
        }
    }
}

/***********************************************************************************************************************************************************************/
/***************************************************************************** changeYaw ***************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::changeYaw(InputDevices::MouseInput mouse_input)
{
    yaw_mat = glm::mat4(1.0f);

    if (mouse_input.getMouseButton(SDL_BUTTON_LEFT))
    {
        x_dir = mouse_input.getXRel();
        m_yaw -= x_dir * m_sensibility[1];

        if (m_sensibility[1] < 0.3)
        {
            m_sensibility[1] += 0.01;
        }
    }
    else if (!mouse_input.getMouseButton(SDL_BUTTON_LEFT))
    {
        if (m_sensibility[1] >= 0.01)
        {
            m_sensibility[1] -= 0.01;
        }

        m_yaw -= x_dir * m_sensibility[1];
    }
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* loadModelShip *************************************************************************/
/***********************************************************************************************************************************************************************/
void Spaceship::buildModel(std::string const& path, int index)
{
    m_index_skin = index;
    if (m_model == nullptr)
    {
        m_model = new Blender::Model(path);
    }
}

/***********************************************************************************************************************************************************************/
/******************************************************************************* getters ***************************************************************************/
/***********************************************************************************************************************************************************************/
glm::vec3 Spaceship::getOrientation() const
{
    return m_ship_orientation;
}

glm::vec3 Spaceship::getLateralMove() const
{
    return m_lateral_move;
}

float Spaceship::getSpeed() const
{
    return m_speed;
}

void Spaceship::setSpeed(float speed)
{
    speed_limit = speed_limit + speed;
    if(speed_limit < 0.0f)
    {
        speed_limit = 0.0f;
    }

    if(speed_limit > 200.0f)
    {
        speed_limit = 200.0f;
    }
}

void Spaceship::setMinimumSpeed()
{
    speed_limit = 5.0f;

    if(m_speed > speed_limit)
    {
        m_speed = speed_limit;
    }
}

void Spaceship::setMaximumSpeed()
{
    speed_limit = 200.0f;
}

float Spaceship::getRotY() const
{
    return m_pitch;
}

float Spaceship::getRotX() const
{
    return m_yaw;
}

void Spaceship::updateSpeed(float const new_val)
{
    if((new_val >= 0.0) && (new_val <= 200.0))
    {
        speed_limit = new_val;
    }
}