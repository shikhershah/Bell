#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Bell/Core/Logging.h"
#include "OpenGLContext.h"



namespace Bell
{

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : WindowHandle(windowHandle)
    {

    }

    void OpenGLContext::Init()
    {

        /* Make the window's context current */
      glfwMakeContextCurrent(WindowHandle);
      
      //initialize GLAD: load all OpenGL functions
      int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

      Engine_INFO(GLFW_OPENGL_CORE_PROFILE);

    } 

    void OpenGLContext::SwapBuffer()
    {   

        glfwSwapBuffers(WindowHandle);
    }

}