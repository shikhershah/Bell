#ifndef WINDOW_H
#define WINDOW_H 

#include <memory>
#include <sstream>
#include <functional>

#include "Bell/Events/Event.h"


namespace Bell
{


   struct WindowProperties
   {

      std::string Title;
      uint32_t Width;
      uint32_t Height;

      WindowProperties(const std::string& title = "Bell",
            uint32_t width = 640, 
            uint32_t height = 480): Title(title), Width(width), Height(height)
      {
      }


   };


   class Window
   {
      public:
         using EventCallbackFn = std::function<void(Event&)>;
         
         virtual ~Window() {} ;

         virtual void OnUpdate() = 0;

         virtual uint32_t GetWidth() const = 0;
         virtual uint32_t GetHeight() const = 0;

         //Window attributes
         virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        
         virtual void SetVSync(bool Enabled) = 0;
         virtual bool IsVSync() const = 0; 


         static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties());


   };

}

#endif //WINDOW_H
