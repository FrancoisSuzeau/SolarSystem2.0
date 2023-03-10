/*
AUTHOR : SUZEAU François

DATE : 30/10/2021

MODULE : Object::AsteroidField

NAMEFILE : AsteroidField.cpp

PURPOSE : class AsteroidField
*/

#include "AsteroidField.hpp"
using namespace Engine::DiscreteSimulationEngine::Objects::OpenGL;

/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
AsteroidField::AsteroidField(std::string const type) : super(type)
{
   /* m_amount = 1000;
    vbo = 0;
    asteroid = new Model("assets/model/rock/rock.obj");
    assert(asteroid);
    this->initTransformations();
    this->initInstances();

    super::normal_texture_id = Loader::loadTextureWithSDL("assets/textures/normalMap/Rock_normalMap.png");
    assert(super::normal_texture_id != 0);*/
}

AsteroidField::~AsteroidField()
{

}

/***********************************************************************************************************************************************************************/
/********************************************************************************* clean *******************************************************************************/
/***********************************************************************************************************************************************************************/
//void AsteroidField::clean()
//{
//    if(asteroid != nullptr)
//    {
//        asteroid->clean();
//        delete asteroid;
//        asteroid = nullptr;
//    }
//    if(model_matrices != nullptr)
//    {
//        delete [] model_matrices;
//    }
//
//    if(m_positions != nullptr)
//    {
//        delete [] m_positions;
//    }
//
//    if(rotAngle != nullptr)
//    {
//        delete [] rotAngle;
//    }
//
//    if(scaleM != nullptr)
//    {
//        delete [] scaleM;
//    }
//
//    if(m_rot_vector != nullptr)
//    {
//        delete [] m_rot_vector;
//    }
//
//    if(glIsBuffer(vbo) == GL_TRUE)
//    {
//        glDeleteBuffers(1, &vbo);
//        vbo = 0;
//    }
//
//    super::clean();
//}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************* transform ***************************************************************************/
///***********************************************************************************************************************************************************************/
//void AsteroidField::transform(glm::vec3 ship_pos, Input *input)
//{
//    for (unsigned int i = 0; i < m_amount; i++)
//    {
//        glm::mat4 model(1.0f);
//
//        model = glm::translate(model, (m_positions[i] + ship_pos));
//
//        rotAngle[i] += 0.005f;
//        if(rotAngle[i] >= 360)
//        {
//            rotAngle[i] -= 360;
//        }
//        model = glm::rotate(model, rotAngle[i], m_rot_vector[i]);
//
//        model = glm::scale(model, glm::vec3(scaleM[i]));
//
//        model_matrices[i] = model;
//    }
//
//    this->initInstances();
//}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************* sendToShad **************************************************************************/
///***********************************************************************************************************************************************************************/
//void AsteroidField::sendToShader(Applications::DataManager &data_manager)
//{
//    if((data_manager.getShader(super::m_type) != nullptr) && (data_manager.getPass() == COLOR_FBO) )
//    {
//        glUseProgram(data_manager.getShader(super::m_type)->getProgramID());
//
//            data_manager.getShader(super::m_type)->setTexture("texture_diffuse1", 0);
//            data_manager.getShader(super::m_type)->setTexture("normalMap", 1);
//            data_manager.getShader(super::m_type)->setMat4("projection", data_manager.getProjMat());
//            data_manager.getShader(super::m_type)->setMat4("view", data_manager.getViewMat());
//            data_manager.getShader(super::m_type)->setVec3("viewPos", data_manager.getCamPos());
//            data_manager.getShader(super::m_type)->setVec3("sunPos", data_manager.getSunPos());
//            data_manager.getShader(super::m_type)->setInt("render_normal", data_manager.getRenderNormal());
//
//        glUseProgram(0);
//    }
//}
//
///***********************************************************************************************************************************************************************/
///****************************************************************************** drawAsteroidField **********************************************************************/
///***********************************************************************************************************************************************************************/
//void AsteroidField::render(Applications::DataManager &data_manager)
//{
//    if(asteroid != nullptr)
//    {
//        if((data_manager.getShader(this->getType()) != nullptr) && (data_manager.getPass() == COLOR_FBO))
//        {
//            glUseProgram(data_manager.getShader(this->getType())->getProgramID());
//        }
//        else if((data_manager.getShader("depth_map") != nullptr) && (data_manager.getPass() == DEPTH_FBO))
//        {
//
//        }
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, asteroid->getTextureLoadedID(0));
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, this->getNormalTextureID());
//
//        for (unsigned int i = 0; i < asteroid->getSizeMeshesVector(); i++)
//        {
//            glBindVertexArray(asteroid->getMeshVAO(i));
//            glDrawElementsInstanced(GL_TRIANGLES, asteroid->getMeshVectorIndiceSize(i), GL_UNSIGNED_INT, 0, m_amount);
//            glBindVertexArray(0);
//        }
//
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, 0);
//            
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, 0);
//
//        glUseProgram(0);
//
//    }
//}
//
///***********************************************************************************************************************************************************************/
///************************************************************************** initTransformations ************************************************************************/
///***********************************************************************************************************************************************************************/
//void AsteroidField::initTransformations()
//{           
//    model_matrices = new glm::mat4[m_amount];
//    m_positions = new glm::vec3[m_amount];
//    rotAngle = new float[m_amount];
//    scaleM = new float[m_amount];
//    m_rot_vector = new glm::vec3[m_amount];
//
//    float radius = 190.0f;
//    float offset = 10.0f;
//
//    for (unsigned int i = 0; i < m_amount; i++)
//    {
//        glm::mat4 model(1.0f);
//        float min = -offset;
//        float max = offset;
//        // ==================== translation configurations ====================
//        float angle = (float) i / (float) m_amount * 360.0f;
//        float displacement = min + ((float) rand() / RAND_MAX * (max - min + 1.0));
//        m_positions[i].x = cos(glm::radians(angle)) * radius + displacement;
//        displacement = min + ((float) rand() / RAND_MAX * (max - min + 1.0));
//        m_positions[i].y = sin(glm::radians(angle)) * radius + displacement;
//        min = -10.0f;
//        max = 10.0f;
//        displacement = min + ((float) rand() / RAND_MAX * (max - min + 1.0));
//        m_positions[i].z = displacement * 0.4f;
//        model = glm::translate(model, m_positions[i]);
//        // ==================== rotation configurations ====================
//        rotAngle[i] = (rand() % 360);
//        min = -1.0f;
//        max = 1.0f;
//        m_rot_vector[i].x = min + ((float) rand() / RAND_MAX * (max - min));
//        m_rot_vector[i].y = min + ((float) rand() / RAND_MAX * (max - min));
//        m_rot_vector[i].z = min + ((float) rand() / RAND_MAX * (max - min));
//        model = glm::rotate(model, rotAngle[i], m_rot_vector[i]);
//        // ==================== scale configurations ====================
//        min = 0.1f;
//        max = 0.8f;
//        scaleM[i] = min + ((float) rand() / RAND_MAX * (max - min));
//        model = glm::scale(model, glm::vec3(scaleM[i]));
//        
//        model_matrices[i] = model;
//    }
//}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************** initInstance ***********************************************************************/
///***********************************************************************************************************************************************************************/
//void AsteroidField::initInstances()
//{
//    // configure instanced array
//    if(glIsBuffer(vbo) == GL_TRUE)
//    {
//        glDeleteBuffers(1, &vbo);
//    }
//    glGenBuffers(1, &vbo);
//    assert(vbo != 0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, m_amount * sizeof(glm::mat4), &model_matrices[0], GL_STATIC_DRAW);
//
//    // set transformation matrices as an instance vertex attribute (with divisor 1)
//    // note: we're cheating a little by taking the, now publicly declared, VAO of the model's mesh(es) and adding new vertexAttribPointers
//    // normally you'd want to do this in a more organized fashion, but for learning purposes this will do.
//    // -----------------------------------------------------------------------------------------------------------------------------------
//    for (unsigned int i = 0; i < asteroid->getSizeMeshesVector(); i++)
//    {
//        unsigned int VAO = asteroid->getMeshVAO(i);
//        glBindVertexArray(VAO);
//        // set attribute pointers for matrix (4 times vec4)
//        glEnableVertexAttribArray(3);
//        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
//        glEnableVertexAttribArray(4);
//        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
//        glEnableVertexAttribArray(5);
//        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
//        glEnableVertexAttribArray(6);
//        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));
//
//        glVertexAttribDivisor(3, 1);
//        glVertexAttribDivisor(4, 1);
//        glVertexAttribDivisor(5, 1);
//        glVertexAttribDivisor(6, 1);
//
//        glBindVertexArray(0);
//    }
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//}

/***********************************************************************************************************************************************************************/
/************************************************************************************ updateCount **********************************************************************/
/***********************************************************************************************************************************************************************/
// void AsteroidField::updateCount(RenderData &render_data)
// {
//     if(render_data.getAsteroidCount() != m_amount)
//     {
//         if(model_matrices != nullptr)
//         {
//             delete [] model_matrices;
//         }

//         if(m_positions != nullptr)
//         {
//             delete [] m_positions;
//         }

//         if(rotAngle != nullptr)
//         {
//             delete [] rotAngle;
//         }

//         if(scaleM != nullptr)
//         {
//             delete [] scaleM;
//         }

//         if(m_rot_vector != nullptr)
//         {
//             delete [] m_rot_vector;
//         }

//         m_amount = render_data.getAsteroidCount();

//         this->initModel();
//         this->initInstanced(model_matrices);
//     }
// }