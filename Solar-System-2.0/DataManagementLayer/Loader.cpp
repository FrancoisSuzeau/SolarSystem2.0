/*
AUTHOR : SUZEAU François

DATE : 13/03/2021

MODULE : Loader

NAMEFILE : Loader.hpp

PURPOSE :   - Load assets for stbi APi
			- Load assets for SDL image API
			- Load assets for SDL mixer API
			- Load assets for SDL TTF API

*/

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "Loader.hpp"

using namespace DataManagementLayer;


/***********************************************************************************************************************************************************************/
/*********************************************************************** Constructor and Destructor ********************************************************************/
/***********************************************************************************************************************************************************************/
Loader::Loader()
{

}

Loader::~Loader()
{

}

/***********************************************************************************************************************************************************************/
/********************************************************************************** Static Functions *******************************************************************/
/***********************************************************************************************************************************************************************/
CkJsonObject* Loader::loadJsonObject(std::string object_name)
{
	std::ifstream flux_in("Contents/configs.json");
	if (flux_in)
	{
		CkJsonObject read_all;
		read_all.Load(std::string((std::istreambuf_iterator<char>(flux_in)), std::istreambuf_iterator<char>()).c_str());
		flux_in.close();
		return read_all.ObjectOf(object_name.c_str());
	}
}

assimp_data Loader::loadModel(std::string const& path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::string err_msg = "Loading Model ASSIMP : ERROR ";
		err_msg.append(import.GetErrorString());
		std::cout << err_msg << std::endl;
		/*showError(nullptr, ErrorHandler(err_msg.c_str()), __FILENAME__, __FUNCTION__, __LINE__);*/
	}
	std::cout << ">> Loading Model ASSIMP : SUCCESS" << std::endl;

	return assimp_data(
		{
			path.substr(0, path.find_last_of('/')),
			scene->mRootNode,
			scene
		}
	);


}

///***********************************************************************************************************************************************************************/
///********************************************************************************** loadWithStbi ***********************************************************************/
///***********************************************************************************************************************************************************************/
//bool Loader::loadWithStbi(std::string file_path, GLuint &id, int &w, int &h)
//{
//    // renderLogTextureLoaded(file_path);
//    unsigned char* image_data = stbi_load(file_path.c_str(), &w, &h, NULL, 4);
//    if (image_data == NULL)
//        return false;
//
//    // Create a OpenGL texture identifier
//    if(glIsTexture(id) == GL_TRUE)
//    {
//        glDeleteTextures(1, &id);
//        id = 0;
//    }
//
//    glGenTextures(1, &id);
//    assert(id != 0);
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, id);
//
//    // Setup filtering parameters for display
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same
//
//    // Upload pixels into texture
//#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
//    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
//#endif
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
//    stbi_image_free(image_data);
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, 0);
//
//    return true;
//}
//
//unsigned int Loader::loadWithStbi(const char *path, const std::string &directory)
//{
//    std::string filename = std::string(path);
//    filename = directory + '/' + filename;
//
//    // renderLogTextureLoaded(filename);
//
//    int width, height, nrComponents;
//    unsigned int textureID = 0;
//    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
//    if (data)
//    {
//        GLenum format;
//        if (nrComponents == 1)
//            format = GL_RED;
//        else if (nrComponents == 3)
//            format = GL_RGB;
//        else if (nrComponents == 4)
//            format = GL_RGBA;
//
//        glGenTextures(1, &textureID);
//        assert(textureID != 0);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, textureID);
//
//            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//            glGenerateMipmap(GL_TEXTURE_2D);
//
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//            stbi_image_free(data);
//
//            std::cout << ">> Texture loading by path: " << path << " SUCCESS" << std::endl;
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, 0);
//
//    }
//    else
//    {
//        std::string err_msg = "Texture failed to load for path : ";
//        err_msg.append(path);
//        showError(nullptr, ErrorHandler(err_msg.c_str()), __FILENAME__, __FUNCTION__, __LINE__);
//        stbi_image_free(data);
//    }
//
//    return textureID;
//}
//
/***********************************************************************************************************************************************************************/
/****************************************************************************** loadWithSDLMixer ***********************************************************************/
/***********************************************************************************************************************************************************************/
Mix_Music* Loader::loadWithSDLMixer(std::string file_path)
{
	Mix_Music* music = NULL;
	/************************************************* load the file ********************************************************/
	music = Mix_LoadMUS(file_path.c_str());
	if (music == NULL)
	{
		std::string err_msg = "Loading file music : ";
		err_msg.append(Mix_GetError());
		//showError(nullptr, ErrorHandler(err_msg.c_str()), __FILENAME__, __FUNCTION__, __LINE__);
		std::cout << err_msg << std::endl;
		return music;
	}
	std::cout << ">> Loading file music : SUCCESS : " << file_path << std::endl;
	return music;
}

///***********************************************************************************************************************************************************************/
///**************************************************************************** loadSkyboxTextures ***********************************************************************/
///***********************************************************************************************************************************************************************/
unsigned int Loader::loadSkyboxTextures(std::vector<std::string> faces)
{
	/************************************************* generate ID ********************************************************/
	unsigned int textID = 0;
	glGenTextures(1, &textID);
	assert(textID != 1);
	//===================================================================================================================

	/************************************************* lock object ********************************************************/
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textID);
	//=====================================================================================================================

	/************************************************* load the file ********************************************************/
	for (unsigned int i(0); i < faces.size(); i++)
	{
		SDL_Surface* picture_SDL = nullptr;
		picture_SDL = IMG_Load(faces[i].c_str());
		if (picture_SDL == nullptr)
		{
			std::string msg_err = ">> Loading file img : ERROR : ";
			msg_err.append(SDL_GetError());
			//showError(nullptr, ErrorHandler(msg_err.c_str()), __FILENAME__, __FUNCTION__, __LINE__);
			std::cout << msg_err << std::endl;
			return 0;
		}
		std::cout << ">> Loading file " << faces[i] << " : SUCCESS" << std::endl;
		//===================================================================================================================

		/************************************************* copying pixels **************************************************************/
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, picture_SDL->w, picture_SDL->h, 0, GL_RGB, GL_UNSIGNED_BYTE, picture_SDL->pixels);
		SDL_FreeSurface(picture_SDL);
		//==============================================================================================================================
	}

	/************************************************* applying layer ********************************************************/
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	//=====================================================================================================================

	/************************************************* unlock object ********************************************************/
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	//=====================================================================================================================

	return textID;
}
//
///***********************************************************************************************************************************************************************/
///********************************************************************************* loadTexture *************************************************************************/
///***********************************************************************************************************************************************************************/
GLuint Loader::loadTextureWithSDL(std::string path)
{
	/************************************************* load the file ********************************************************/
	SDL_Surface* picture_SDL = NULL;
	picture_SDL = IMG_Load(path.c_str());
	if (picture_SDL == NULL)
	{
		std::string msg_err = ">> Loading file img : ERROR : ";
		msg_err.append(SDL_GetError());
		/*showError(nullptr, ErrorHandler(msg_err.c_str()), __FILENAME__, __FUNCTION__, __LINE__);*/
		std::cout << msg_err << std::endl;
		return 0;
	}
	std::cout << ">> Loading file " << path << " : SUCCESS" << std::endl;

	//===================================================================================================================

	/************************************************* invert img ********************************************************/
	SDL_Surface* img_invert = Loader::pixelsInverter(picture_SDL);
	SDL_FreeSurface(picture_SDL);
	//===================================================================================================================

	/************************************************* generate ID ********************************************************/
	GLuint id_texture = 0;
	glGenTextures(1, &id_texture);
	assert(id_texture != 0);
	//===================================================================================================================

	/************************************************* lock object ********************************************************/
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, id_texture);
	//=====================================================================================================================

	/************************************************* determinate the alpha component *************************************/
	GLenum intern_format(0);
	GLenum format(0);

	if (img_invert->format->BytesPerPixel == 3) //there is no alpha component
	{
		intern_format = GL_RGB;

		if (img_invert->format->Rmask == 0xff)
		{
			format = GL_RGB;
		}
		else
		{
			format = GL_BGR;
		}
	}
	else if (img_invert->format->BytesPerPixel == 4) //there is one
	{
		intern_format = GL_RGBA;

		if (img_invert->format->Rmask == 0xff)
		{
			format = GL_RGBA;
		}
		else
		{
			format = GL_BGRA;
		}
	}
	else
	{
		std::string msg_err = ">> Alpha component : ERROR : picture format unknown";
		//showError(nullptr, ErrorHandler(msg_err.c_str()), __FILENAME__, __FUNCTION__, __LINE__);
		std::cout << msg_err << std::endl;
		SDL_FreeSurface(img_invert);
		return 0;
	}
	//=====================================================================================================================

	/************************************************* copying pixels **************************************************************/
	glTexImage2D(GL_TEXTURE_2D, 0, intern_format, img_invert->w, img_invert->h, 0, format, GL_UNSIGNED_BYTE, img_invert->pixels);
	//==============================================================================================================================

	/************************************************* applying layer ********************************************************/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//=====================================================================================================================

	/************************************************* unlock object ********************************************************/
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	//=====================================================================================================================

	SDL_FreeSurface(img_invert);
	return id_texture;
}

///***********************************************************************************************************************************************************************/
///********************************************************************************* pixelInverter ***********************************************************************/
///***********************************************************************************************************************************************************************/
SDL_Surface* Loader::pixelsInverter(SDL_Surface* src_img)
{
	/************************************************* copying img without pixels **************************************************************/
	SDL_Surface* img_inverted = SDL_CreateRGBSurface(0, src_img->w, src_img->h, src_img->format->BitsPerPixel, src_img->format->Rmask,
		src_img->format->Gmask, src_img->format->Bmask, src_img->format->Amask);
	if (img_inverted == NULL)
	{
		std::cout << ">> RGB surface : ERROR : " << SDL_GetError() << std::endl;
		return src_img;
	}
	std::cout << ">> RGB surface : SUCCESS" << std::endl;
	//==============================================================================================================================

	/************************************************* intermediate array  **************************************************************/
	unsigned char* src_pixels = (unsigned char*)src_img->pixels;
	unsigned char* inverted_pixels = (unsigned char*)img_inverted->pixels;
	//==============================================================================================================================

	/************************************************* invert pixels  **************************************************************/
	for (int i(0); i < src_img->h; i++)
	{
		for (int j(0); j < src_img->w * src_img->format->BytesPerPixel; j++)
		{
			inverted_pixels[(src_img->w * src_img->format->BytesPerPixel * (src_img->h - 1 - i)) + j] = src_pixels[(src_img->w * src_img->format->BytesPerPixel * i) + j];
		}

	}
	//==============================================================================================================================

	return img_inverted;
}

///***********************************************************************************************************************************************************************/
///******************************************************************** loadFlareTexture ******************************************************************************/
///***********************************************************************************************************************************************************************/
//GLuint Loader::loadFlareTexture(std::string text_path, int &img_w, int &img_h)
//{
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* image_data = stbi_load(text_path.c_str(), &img_w, &img_h, NULL, 4);
//    if (image_data == NULL)
//        return 0;
//
//    // Create a OpenGL texture identifier
//    GLuint texture_id = 0;
//    glGenTextures(1, &texture_id);
//    assert(texture_id != 0);
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture_id);
//
//    // // Setup filtering parameters for display
//    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
//    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    
//
//        // Upload pixels into texture
//    #if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
//        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
//    #endif
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_w, img_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
//    stbi_image_free(image_data);
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, 0);
//
//    stbi_set_flip_vertically_on_load(false);
//
//    std::cout << ">> Loading File " << text_path << " : SUCCESS" << std::endl;
//    return texture_id;
//}