#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Event.h"


namespace Bell
{

   class MouseMoveEvent : public Event
   {

   private:
      float  m_MouseX, m_MouseY;


   public:

      MouseMoveEvent(const float x, const float y): m_MouseX(x), m_MouseY(y){}

      float GetX() const { return m_MouseX;};
      float GetY() const { return m_MouseY;}; 

      std::string ToString() const  override 
      {

         std::stringstream ss;
         ss << "MouseMoved x:" << m_MouseX << " y: " << m_MouseY;
         return ss.str();
      }

      EVENT_CLASS_Function(MouseMove);
      EVENT_CLASS_Type(Mouse);

   };

   class MouseButtonEvent : public Event
   {
      protected:
         int m_button;
         MouseButtonEvent(int button) : m_button(button){}

      public:
         inline int getbutton() const
         {
            return m_button;
         }

         EVENT_CLASS_Type(MouseButton);

   };

   class MouseButtonPress : public MouseButtonEvent
   {

   public:

      MouseButtonPress(int button) : MouseButtonEvent(button){};

      std::string ToString() const  override 
      {
         std::stringstream ss;
         ss << "MousePress:" << m_button;
         return ss.str();
      }


      EVENT_CLASS_Function(MousePress);
   };

   class MouseButtonRelease : public MouseButtonEvent
   {
      public:
         
         MouseButtonRelease(int button) : MouseButtonEvent(button){};

       std::string ToString() const  override 
      {
         std::stringstream ss;
         ss << "MouseRelease:" << m_button;
         return ss.str();
      }


         EVENT_CLASS_Function(MouseRelease);

   };

   class MouseScrollEvent : public Event
   {
      private:
         float m_Xoffset, m_Yoffset;

      public:
         MouseScrollEvent(const float Xoffset, const float Yoffset) : m_Xoffset(Xoffset), m_Yoffset(Yoffset){}


         float GetXoffset() const { return m_Xoffset; }
	 float GetYoffset() const { return m_Yoffset; }

	 std::string ToString() const override
	 {
	    std::stringstream ss;
	
            ss << "MouseScrollEvent: " << GetXoffset() << ", " << GetYoffset();
			
            return ss.str();
	 }

         EVENT_CLASS_Function(MouseScroll);
         EVENT_CLASS_Type(Mouse);


   };

}
#endif //MOUSEEVENT_H
