#include <stdlib.h>
#include <functional>

#include "Application.h"
#include "Logging.h"
#include "Input.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#define BELL_BIND_EVENT(x) std::bind(&x,this ,std::placeholders::_1)

namespace Bell
{
   Application* Application::Instance = nullptr;

   Application::Application()
   {
      Instance = this;

      m_window = Window::Create();
      m_window->SetEventCallback(BELL_BIND_EVENT(Application::OnEvent));

      imGuiLayer = new ImGuiLayer();
      PushOverlay(imGuiLayer);
      Engine_INFO("Push imgui overlay");
      
      //Draw a triangle
      glGenVertexArrays(1, &VertexArray);
      glBindVertexArray(VertexArray);

      //glGenBuffers(1, &VertexBuffer);
      //glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

      float vertices[3 * 3]
      {
         -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
      };
     
      VertexBuffPtr.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
      Engine_TRACE("Created VertexBuffer");
     //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);

      //glGenBuffers(1, &IndexBuffer);
      //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);

      unsigned int indices[] = {0,1,2};
      IndexBuffPtr.reset(IndexBuffer::Create(indices, sizeof(indices)));
      //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
      Engine_TRACE("Reached Create IndexBuffer");
      std::string VertexSrc = R"(
         #version 330 core

         layout(location = 0) in vec3 a_Position;

         void main()
         {
            gl_Position = vec4(a_Position, 1.0);
         }
      
      
      )";

      std::string FragmentSrc = R"(
         #version 330 core

         layout(location = 0) out vec4 color;

         void main()
         {
           color = vec4(0.8, 0.2, 0.3, 1.0);
         }
      
      
      )";
      
      ShaderPtr.reset(new Shader(VertexSrc, FragmentSrc));
      //Engine_TRACE("Reached end of Application constructor");
   }

   Application::~Application()
   {
   }

 
   void Application::Run()
   {
      Engine_TRACE("Reached Run App");
      //WindowResize e(100,100);
      //Engine_TRACE(e);
      while(m_Running)
      {
         /* float time = Time::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time; */
         Engine_TRACE("Start Running App");
         //glClearColor(0.1f,0.1f,0.1f,0.0f);
         glClearColor(1.0f,1.0f,1.0f,1.0f);
         glClear(GL_COLOR_BUFFER_BIT);

         
         
         glBindVertexArray(VertexArray);
         ShaderPtr->Bind();
         glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
         Engine_TRACE("Draw Triangle");
         
         for (Layer* layer : m_LayerStack)
						layer->OnUpdate();

         imGuiLayer->Begin();
        {
					Engine_INFO("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
			}
         imGuiLayer->End();

         m_window->OnUpdate();

      }
  
   }

   void Application::OnEvent(Event& e)
   {

      EventDispatcher Dispatcher(e);
      Dispatcher.Dispatch<WindowCloseEvent>(BELL_BIND_EVENT(Application::OnWindowClose));

      Engine_TRACE("{0}", e);


   }

   void Application::PushStack(Layer* layer)
   {

      app_LayerStack.PushLayer(layer);
      layer->OnAttach();
   }

   void Application::PushOverlay(Layer* layer)
   {
      
      app_LayerStack.PushOverlay(layer);
      layer->OnAttach();
   }

   bool Application::OnWindowClose(WindowCloseEvent& e)
   {
      m_Running = false;

      return true;
   }

}
