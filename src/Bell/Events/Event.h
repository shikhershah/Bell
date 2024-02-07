#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <sstream>

namespace Bell
{



   enum class EventFunction
   {
      None = 0, //default
      WindowClose, WindowResize, WindowOnFocus, WindowLoseFocus, WindowMove,
      AppTick, AppUpdate , AppRender, 
      MousePress, MouseRelease, MouseMove, MouseScroll,
      KeyPress, KeyRelease, KeyType
   };

   enum EventType
   {

      None = 0,
      Application,
      Input,
      Mouse,
      MouseButton,
      Keyboard
   };


   #define EVENT_CLASS_Function(function) static EventFunction GetStaticFunction() { return EventFunction::function; }\
								virtual EventFunction GetEventFunction() const override { return GetStaticFunction(); }\
								virtual const char* GetEventName() const override { return #function; }

   #define EVENT_CLASS_Type(type) virtual int GetEventTypeFlag() const override { return type; }



   class Event
   {
      public:
         virtual ~Event() = default;

         bool Handled = false;
   
         virtual EventFunction  GetEventFunction() const = 0;
         virtual const char* GetEventName() const = 0;
         virtual int GetEventTypeFlag() const = 0;
         virtual std::string ToString() const  { return GetEventName();}

         bool IsEventType(EventType type)
         {
            return GetEventTypeFlag() & type;
         }
   };

   class EventDispatcher
   {
      private:
         Event& m_Event;
      public:
         EventDispatcher(Event& event)
            :m_Event(event)
         {
         }

         template<typename T, typename F>
         bool Dispatch(const F& func)
         {
            if(m_Event.GetEventFunction() == T::GetStaticType())
            {
               m_Event.Handled |= func(static_cast<T&>(m_Event));
               return true;
            }
            return false;
         }
   };
 
   inline std::ostream& operator<<(std::ostream& os, const Event& e)
   {
      return os << e.ToString();
   }
		
}








#endif //EVENT_H
