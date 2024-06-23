#ifndef APPEVENT_H
#define APPEVENT_H

#include "Event.h"


namespace Bell
{
   class WindowResizeEvent : public Event
   {
      private:
         unsigned int WindowWidth, WindowHeight;

      public:
         
         WindowResizeEvent(unsigned int width, unsigned int height)
            : WindowWidth(width), WindowHeight(height) {}

         unsigned int GetWidth() const 
         {
            return WindowWidth;
         }
         unsigned int GetHeight() const
         {
            return WindowHeight;
         }

         std::string ToString() const override
         {
               std::stringstream ss;
               ss << "WindowResizeEvent: " << WindowWidth << " , " << WindowHeight;

               return ss.str();
         }

         EVENT_CLASS_Function(WindowResize);
         EVENT_CLASS_Type(App);
   };

   class WindowCloseEvent : public Event
   {
      public:
     
      WindowCloseEvent() = default;
   
      EVENT_CLASS_Function(WindowClose);
      EVENT_CLASS_Type(App);


   };

   class AppTickEvent : public Event
   {
      public:
      AppTickEvent() = default;

      EVENT_CLASS_Function(AppTick);
      EVENT_CLASS_Type(App);

   };

   class AppUpdateEvent : public Event
   {
      public:
      AppUpdateEvent() = default;

      EVENT_CLASS_Function(AppUpdate);
      EVENT_CLASS_Type(App);
   };

   class AppRenderEvent : public Event
   {
      public:
      AppRenderEvent() = default;

      EVENT_CLASS_Function(AppRender);
      EVENT_CLASS_Type(App);
   };



}
#endif //APPEVENT_H
