#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H


#include "Bell/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Bell
{


   class OpenGLContext : public GraphicsContext  
   {
   private:
      GLFWwindow* WindowHandle;


   public:
      OpenGLContext(GLFWwindow* windowHandle);

      virtual void Init() override;
      virtual void SwapBuffer() override;

   };

}



#endif //OPENGELCONETEXT_H

