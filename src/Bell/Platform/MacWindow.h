#ifndef MACWINDOW_H
#define MACWINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Bell/Core/Window.h"


namespace Bell
{


   class MacWindow : public Window
   {
      
      private:

         virtual void Init(const WindowProperties& props);
         virtual void Close();

         GLFWwindow* m_window; 

         struct WindowData
         {
            std::string Title; 
            uint32_t Width;
            uint32_t Height;

            bool VSync;
            EventCallbackFn EventCallback;
         };

         WindowData windowData;

      public:

         MacWindow(const WindowProperties& props); //Pass by const reference 
         virtual ~MacWindow();

         void OnUpdate() override;

         uint32_t GetWidth() const override { return windowData.Width; };
         uint32_t GetHeight() const override { return windowData.Height; };

         //Window Attributes 
         void SetEventCallback(const EventCallbackFn& callback) override { windowData.EventCallback = callback; }
		
         void SetVSync(bool Enabled) override;
         bool IsVSync() const override;
   };


}


#endif //MACWINDOW_H
