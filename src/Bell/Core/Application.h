#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Platform/MacWindow.h"

namespace Bell
{

   class Application
   {
      private:
         std::unique_ptr<Window> m_window;

      public:
      Application();
      virtual ~Application();
      void CreateWindow();
      void Run();
   };

   
   Application* CreateApp();
}


#endif //APPLICATION_H
