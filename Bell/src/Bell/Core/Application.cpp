#include <stdlib.h>
#include <functional>

#include "Application.h"
#include "Logging.h"
#include "Input.h"

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
      Engine_INFO("Push imgui overlay");
      PushOverlay(imGuiLayer);
   }

   Application::~Application()
   {
   }

 
   void Application::Run()
   {

     // WindowResize e (100,100);
     // Engine_TRACE(e);
      while(m_Running)
      {
         glClearColor(1,0,1,1);
         glClear(GL_COLOR_BUFFER_BIT);
         
         imGuiLayer->Begin();
        /*{
					Engine_INFO("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
			}*/
         ImDrawList* DrawList = ImGui::GetWindowDrawList();
         DrawList->AddTriangleFilled(ImVec2(50,100), ImVec2(150,100), ImVec2(100,50), ImColor(2500,0,0));
        

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
