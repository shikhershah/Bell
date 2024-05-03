#ifndef APPLICATION_H
#define APPLICATION_H

//#include "Bell/ImGui/ImGuiLayer.h"
#include "LayerStack.h"

#include "Bell/Platform/MacWindow.h"
#include "Bell/Events/Event.h"
#include "Bell/Events/AppEvent.h"

#include "Bell/ImGui/ImGuiLayer.h"


namespace Bell
{

   class ImGuiLayer;
   class Application
   {
      private:

         bool m_Running = true;
         std::unique_ptr<Window> m_window;

         static Application* Instance;
         bool OnWindowClose(WindowCloseEvent& e);

          ImGuiLayer* imGuiLayer; 

      public:
       
         Application();
         virtual ~Application();

      
         void Run();
         void OnEvent(Event &e);

         LayerStack app_LayerStack;
         void PushStack(Layer* layer);
         void PushOverlay(Layer* layer);


         Window& GetWindow() { return *m_window; }
         static Application& Get() { return *Instance; }

   };

   
   Application* CreateApp();
}


#endif //APPLICATION_H
