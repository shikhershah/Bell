

#include <Bell.h>
#include <Bell/Core/EntryPoint.h>


class SandBox : public Bell::Application
{
   private:


   public:
      SandBox()
      {


      }

      ~SandBox(){}



};


Bell::Application* Bell::CreateApp()
{



   return new SandBox();
}
