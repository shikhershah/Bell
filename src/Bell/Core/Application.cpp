#include <stdlib.h>

#include "Application.h"
#include "../Events/AppEvent.h"
#include "Logging.h"

#include "/Users/shikhershah/Projects/GameEngine/Bell/External/glfw/include/GLFW/glfw3.h"

//#include "External/glfw/include/GLFW/glfw3.h"

#define BELL_BIND_EVENT(x) std::bind(&x, std::placeholders::_1)

namespace Bell
{


   Application::Application()
   {
      m_window = Window::Create();
      m_window->SetEventCallback(BELL_BIND_EVENT(Application::);
   }

   Application::~Application()
   {
   }

 
   void Application::Run()
   {

      WindowResize e (100,100);
      Engine_TRACE(e);
      //CreateWindow();
      while(true)
      {
         glClearColor(1,0,1,1);
         glClear(GL_COLOR_BUFFER_BIT);
         m_window->OnUpdate();
      }
  
   }


}
