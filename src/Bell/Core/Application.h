#ifndef APPLICATION_H
#define APPLICATION_H


#include "LayerStack.h"
#include "Bell/Platform/MacWindow.h"
#include "Bell/Events/Event.h"
#include "Bell/Events/AppEvent.h"


namespace Bell
{

   class Application
   {
      private:

         bool m_Running = true;
         std::unique_ptr<Window> m_window;

         bool OnWindowClose(WindowCloseEvent& e);

      public:
         Application();
         virtual ~Application();
      
         void Run();
         void OnEvent(Event &e);

         LayerStack app_LayerStack;
         void PushStack(Layer* layer);
         void PushOverlay(Layer* layer);

   };

   
   Application* CreateApp();
}


#endif //APPLICATION_H
