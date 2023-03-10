/*
AUTHOR : SUZEAU François

DATE : 13/03/2022

MODULE : Loader

NAMEFILE : Loader.hpp

PURPOSE : header of the Loader class
*/

#ifndef LOADER_H
#define LOADER_H


/********************************************************************* includes *********************************************************************/
        #include <iostream>
        #include <fstream>
        #include <chilkat/CkJsonArray.h>
        #include <chilkat/CkJsonObject.h>
        #include <cassert>

       #include <GL/glew.h>
       #include <SDL2/SDL.h>
        #include <SDL2/SDL_image.h>
        /*#include <SDL2/SDL_mixer.h>*/

/********************************************************************* class definition *********************************************************************/

namespace DataManagementLayer {

    class Loader
    {

        private:

            //This class cannot be instanced
            Loader();
            ~Loader();

            /*static SDL_Surface* pixelsInverter(SDL_Surface *src_img);*/




        public:

            static CkJsonObject* loadJsonObject(std::string object_name);

            /*
            static bool loadWithStbi(std::string file_path, GLuint &id, int &w, int &h);
            static unsigned int loadWithStbi(const char *path, const std::string &directory);
            static  Mix_Music* loadWithSDLMixer(std::string file_path, Mix_Music *m_music);
            static unsigned int loadSkyboxTextures(std::vector<std::string> faces);
            static GLuint       loadTextureWithSDL(std::string path);
            static void initializeMap();
            static GLuint       loadFlareTexture(std::string text_path, int &img_w, int &img_h);*/


    };

    /*void renderLogTextureLoaded(std::string const texture_path);*/

}

        


#endif