#ifndef APPEVENT_H
#define APPEVENT_H

#include "Event.h"


namespace Bell
{
   class WindowResize : public Event
   {
      private:
         unsigned int WindowWidth, WindowHeight;

      public:
         
         WindowResize(unsigned int width, unsigned int height)
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
         EVENT_CLASS_Type(Application);
   };

   class WindowClose : public Event
   {
     
      WindowClose() = default;
   
      EVENT_CLASS_Function(WindowClose);
      EVENT_CLASS_Type(Application);


   };

   class AppTick : public Event
   {
      AppTick() = default;

      EVENT_CLASS_Function(AppTick);
      EVENT_CLASS_Type(Application);

   };

   class AppUpdate : public Event
   {
      AppUpdate() = default;

      EVENT_CLASS_Function(AppUpdate);
      EVENT_CLASS_Type(Application);
   };

   class AppRender : public Event
   {
      AppRender() = default;

      EVENT_CLASS_Function(AppRender);
      EVENT_CLASS_Type(Application);
   };



}
#endif //APPEVENT_H
