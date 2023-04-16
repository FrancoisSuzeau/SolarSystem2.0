/*
AUTHOR : SUZEAU François

DATE : 06/02/2022

MODULE : Objects::TexturedObjects::SquareTextured::LensFlare

NAMEFILE : FlareTexture.hpp

PURPOSE : 
*/

#ifndef FLARETEXTURE_H
#define FLARETEXTURE_H


/********************************************************************* includes *********************************************************************/

        #include <iostream>
        #include "Square.hpp"
        #include <cassert>
        #include <glm/glm.hpp>

/********************************************************************* class definition *********************************************************************/
namespace Engine {

    namespace DiscreteSimulationEngine {

        namespace Objects {

            namespace OpenGL {

                class FlareTexture : public Square
                {
                    private:

                        typedef Square super;

                    
                        int             texture_w;
                        int             texture_h;
                        float           m_brightness;
                   

                    public:

                        FlareTexture(float size, std::string const type, std::string const texture_path);
                        ~FlareTexture();

                        float getLightStrength() override;
                        float getOppacity() override;
                        //void transform(glm::vec3 ship_pos = glm::vec3(0.f)) override;

                        /*

                        void clean();

                        void updateBrightness(float const new_val);*/



                };

            }

        }

    }

}
        
#endif