#include<memory>

#include "MacWindow.h"
#include "../Core/Logging.h"

#include "../Events/AppEvent.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"

#include "Bell/Platform/OpenGL/OpenGLContext.h" 

namespace Bell
{
   static void GLFWErrorCallback(int error, const char* description)
   {

      Engine_ERROR("GLFW ERROR: ({0}): {1} ", error, description);


   }

   std::unique_ptr<Window> Window::Create(const WindowProperties& props)
   {

      return std::make_unique<MacWindow>(props);  
   }

   MacWindow::MacWindow(const WindowProperties& props)
   {

      Init(props);
   }

   MacWindow::~MacWindow()
   {

      Close();
   }

   void MacWindow::Init(const WindowProperties& props)
   {

      windowData.Title = props.Title;
      windowData.Width = props.Width;
      windowData.Height = props.Height;

      Engine_INFO("Props Width: {0}", props.Width);
      Engine_INFO("Props Height: {0}", props.Height);

      

      if (!glfwInit())
         exit(EXIT_FAILURE);

      glfwSetErrorCallback(GLFWErrorCallback);

      
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

      m_window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), NULL, NULL);
      Engine_TRACE("Window Created");

     

      //Maximize window without fullscreen. 
      //glfwMaximizeWindow(m_window);

       if (!m_window)
      {
         glfwTerminate();
         exit(EXIT_FAILURE);
      }

      m_Context = new OpenGLContext(m_window);
      m_Context->Init();
      
      //glfwSetWindowUserPointer(m_window, &windowData);
      /* Make the window's context current 
       * moved to OpenGLContext
       */
      //glfwMakeContextCurrent(m_window);
      glfwSetWindowUserPointer(m_window, &windowData);
      //initialize GLAD: load all OpenGL functions
      //int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

      Engine_INFO(GLFW_OPENGL_CORE_PROFILE);
      

      SetVSync(true);
    
      glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
      {
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         Data.Width = width;
         Data.Height = height;

         WindowResizeEvent event(width,height);
         
         

         Data.EventCallback(event);
      });

      glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
      {
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         WindowCloseEvent close;

         Data.EventCallback(close);

      });

      glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
      {
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         switch (action)
         {
	    case GLFW_PRESS:
	    {
	       KeyPressEvent event(key, 0);
	       Data.EventCallback(event);
	       break;
	    }
	    case GLFW_RELEASE:
	    {
	       KeyReleaseEvent event(key);
	       Data.EventCallback(event);
	       break;
	    }
	    case GLFW_REPEAT:
	    {
	       KeyPressEvent event(key, true);
	       Data.EventCallback(event);
	       break;
	    }
	 }
      });

      glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
      {
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         MouseMoveEvent event((float)xpos, (float)ypos);
         Data.EventCallback(event);

      });

      glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
      {
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         switch(action)
         {

            case GLFW_PRESS:
            {
               MouseButtonPress event(button);
               Data.EventCallback(event);
               
               break;
            }
            case GLFW_RELEASE:
            {
               MouseButtonRelease event(button);
               Data.EventCallback(event);

               break;
            }

         }


      });

      glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
      {
         
         WindowData& Data = *(WindowData*) glfwGetWindowUserPointer(window);

         MouseScrollEvent event((float)xOffset, (float)yOffset);
         Data.EventCallback(event);


      });

   }

   void MacWindow::Close()
   {

      glfwDestroyWindow(m_window);

      glfwTerminate();
      exit(EXIT_SUCCESS);


   }

   void MacWindow::OnUpdate()
   {
      glfwPollEvents();
      //glfwSwapBuffers(m_window);

      m_Context->SwapBuffer();
   }

   void MacWindow::SetVSync(bool Enabled)
   {
      if(Enabled)
         glfwSwapInterval(1); // wait time for swapping buffers and returning
   }

   bool MacWindow::IsVSync() const
   {
      return windowData.VSync;

   }

}
