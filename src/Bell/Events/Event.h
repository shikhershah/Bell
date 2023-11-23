#ifndef EVENT_H
#define EVENT_H



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
      Application = BIT(0)
      Input = BIT(1),
      Mouse = BIT(2),
      MouseButton = BIT(3),
      Keyboard = BIT(4)
   };


   #define EVENT_CLASS_Function(function) static EventFunction GetStaticFunction() { return EventFunction::function; }\
								virtual EventFunction GetEventFunction() const override { return GetStaticFunction(); }\
								virtual const char* GetName() const override { return #function; }

   #define EVENT_CLASS_Type(type) virtual int GetTypeFlag() const override { return type; }



   class Event
   {
      public:
         virtual ~Event() = default;

         bool Handled = false;
   
         virtual GetEventFunction() const = 0;
         virtual const char* GetEventName() const = 0;
         virtual GetEventTypeFlag() const = 0;
         virtual std::string ToString() { return GetEventName();}

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
            if(m_Event.GetEventFunction() == T.GetStaticType())
            {
               m_Event.Handled |= func(stat-c_cast<T&>(m_Event));
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
