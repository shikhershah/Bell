#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "Event.h"


namespace Bell
{

   class MouseMove : public Event
   {

   private:
      float  m_MouseX, m_MouseY;


   public:

      MouseMove(const float x, const float y): m_MouseX(x), m_MouseY(y){}

      float GetX() const { return m_MouseX};
      float GetY() const { return m_MouseY}; 

      std::string ToString() const  override 
      {

         std::stringstream ss;
         ss << "MouseMoved x:" << m_MouseX << " y: " << m_MouseY;
         return ss.str();
      }

      EVENT_CLASS_Function(MouseMove);
      EVENT_CLASS_Type(Mouse);

   }


   class MousePress : public Event
   {

   public:



   }

}
#endif //MOUSEEVENT_H
