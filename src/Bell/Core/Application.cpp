#include <stdlib.h>

#include "Application.h"
#include "../Events/AppEvent.h"
#include "Logging.h"

#include "/Users/shikhershah/Projects/GameEngine/Bell/External/glfw/include/GLFW/glfw3.h"

//#include "External/glfw/include/GLFW/glfw3.h"



namespace Bell
{


   Application::Application()
   {
      m_window = Window::Create();
   }

   Application::~Application()
   {
   }

   void Application::CreateWindow()
   {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        exit (EXIT_FAILURE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
         exit (EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    exit (EXIT_SUCCESS);


   }

   void Application::Run()
   {

      WindowResize e (100,100);
      Engine_TRACE(e);
     // CreateWindow();
      while(true);
  
   }


}
