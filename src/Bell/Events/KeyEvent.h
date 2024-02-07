#ifndef KEYEVENT_H
#define KEYEVENT_H



namespace Bell
{

   class KeyEvent : public Event
   {
   
      private:

         KeyEvent(const KeyCode keycode)
            : m_keycode(keycode) {};

         KeyCode m_keycode;


      public:

         EVENT_CLASS_Type(KeyBoard | Input);


   };

   class KeyPress : public KeyEvent
   {
      private:
         bool m_isrepeat;

      public:

      KeyPress(const KeyCode keycode, bool IsRepeat = false) 
         : KeyEvent(keycode), m_isrepeat(IsRepeat) {};

      bool IsRepeat() const 
      {
         return m_isrepeat;
      }

      std::string ToString() const override
      {
         std::stringstream ss;
         ss << "KeyPress: " << m_keycode << "(repeat = " << m_isrepeat << ")";

         return ss.str();
      }

      EVENT_CLASS_Function(KeyPress);

   };

   class KeyRelease : public KeyEvent
   {
      public:

         KeyRelease(const KeyCode keycode)
            : KeyEvent(keycode);

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "Keyrelease: " << m_keycode;

            return ss.str();
         }

         EVENT_CLASS_Function(KeyRelease);
   };

   class KeyType : public KeyEvent
   {
      public:

         KeyType(const KeyCode keycode)
            : KeyEvent(keycode);

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "KeyType: " << m_keycode;

            return ss.str();
         }

         EVENT_CLASS_Function(KeyType);
   };

}






#endif //KEYEVENT_H
