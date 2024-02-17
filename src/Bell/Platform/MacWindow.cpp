#include "MacWindow.h"
#include "../Core/Logging.h"
#include<memory>

namespace Bell
{

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

      if (!glfwInit())
         exit(EXIT_FAILURE);

      m_window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), NULL, NULL);
     Engine_TRACE("Window Created");

       if (!m_window)
      {
         glfwTerminate();
         exit(EXIT_FAILURE);
      }

      /* Make the window's context current */
      glfwMakeContextCurrent(m_window);
      SetVSync(true);
    
      glfwSetWindowSizeCallback(m_window, 

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
      glfwSwapBuffers(m_window);
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