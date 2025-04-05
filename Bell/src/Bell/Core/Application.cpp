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
   static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
   {
      switch (type)
      {
         case ShaderDataType::Int:     return GL_INT;
         case ShaderDataType::Int2:    return GL_INT;
         case ShaderDataType::Int3:    return GL_INT;
         case ShaderDataType::Int4:    return GL_INT;
         case ShaderDataType::Float:   return GL_FLOAT;
         case ShaderDataType::Float2:  return GL_FLOAT;
         case ShaderDataType::Float3:  return GL_FLOAT;
         case ShaderDataType::Float4:  return GL_FLOAT;
         case ShaderDataType::Mat3:    return GL_FLOAT; // 3* float3
         case ShaderDataType::Mat4:    return GL_FLOAT; // 4* float4
         case ShaderDataType::Bool:    return GL_BOOL;
      
         default:
            break;
      }

      return 0;
   }

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

      float vertices[3 * 7]
      {
         -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f,1.0f,
         0.0f,  0.5f, 0.0f, 0.7f, -0.2f, 0.0f,1.0f
      };
     
      VertexBuffPtr.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
      Engine_TRACE("Created VertexBuffer");
     //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

     {
     BufferLayout layout =
     {
         {ShaderDataType::Float3, "a_Position"},
         {ShaderDataType::Float4, "a_Color"}
     };

      VertexBuffPtr->SetLayout(layout);

     }

     uint32_t index = 0;
     for (const auto& elements : VertexBuffPtr->GetLayout())
     {
         glEnableVertexAttribArray(index);
         glVertexAttribPointer(index,
            elements.GetComponentCount(),
            ShaderDataTypeToOpenGLBaseType(elements.ShaderType),
            GL_FALSE,VertexBuffPtr->GetLayout().GetStride(),
            (const void*)elements.Offset);
         index++;
     }
     
      //glGenBuffers(1, &IndexBuffer);
      //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);

      unsigned int indices[] = {0,1,2};
      IndexBuffPtr.reset(IndexBuffer::Create(indices, sizeof(indices)));
      //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
      Engine_TRACE("Reached Create IndexBuffer");
      std::string VertexSrc = R"(
         #version 330 core

         layout(location = 0) in vec3 a_Position;
         layout(location = 1) in vec4 a_Color;

         out vec3 v_Position;
         out vec4 v_Color;

         void main()
         {
            v_Position = a_Position;
            v_Color = a_Color;
            gl_Position = vec4(a_Position, 1.0);
         }
      
      
      )";

      std::string FragmentSrc = R"(
         #version 330 core

         layout(location = 0) out vec4 color;

         in vec3 v_Position;
         in vec4 v_Color;

         void main()
         {
           color = vec4(0.8, 0.2, 0.3, 1.0);
           color = v_Color;
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
