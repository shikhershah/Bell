#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Platform/MacWindow.h"
#include "../Events/Event.h"

namespace Bell
{

   class Application
   {
      private:
         std::unique_ptr<Window> m_window;

      public:
      Application();
      virtual ~Application();
      
      void Run();
      void OnEvent(Event &e);

   };

   
   Application* CreateApp();
}


#endif //APPLICATION_H
