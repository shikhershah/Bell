#ifndef RENDERER_H
#define RENDERER_H

#include "Bell/Core/Logging.h"

namespace Bell
{

    enum class RendererAPI
    {
        None = 0,
        OpenGL = 1
    };

    class Renderer
    {
        private:

            static RendererAPI s_RendererAPI;

        public:
            inline static RendererAPI GetAPI()
            { 
                //Engine_TRACE("Reached Renderer API - Get");
                return s_RendererAPI;
            }
    };
}

#endif //RENDERER_H