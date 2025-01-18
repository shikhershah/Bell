#ifndef SHADER_H
#define SHADER_H

#include "../Core/Logging.h"

namespace Bell
{

    class Shader
    {
    private:

    uint32_t RendererID;
        
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        //virtual void 


    };
    
  

}

#endif //SHADER_H