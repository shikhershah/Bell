#ifndef KEYEVENT_H
#define KEYEVENT_H



namespace Bell
{

   class KeyEvent : public Event
   {
      protected:
         int m_keycode;

         KeyEvent (int keyCode) : m_keycode(keyCode){};   
      private:

        // KeyEvent(const KeyCode keycode): m_keycode(keycode) {};

         //KeyCode m_keycode;
         inline int GetKeyCode() const
         {
            return m_keycode;
         }

      public:

         EVENT_CLASS_Type(Keyboard | Input);


   };

   class KeyPressEvent : public KeyEvent
   {
      private:
         bool m_isrepeat;

      public:

      KeyPressEvent(int keyCode, bool isRepeat = false) 
         : KeyEvent(keyCode), m_isrepeat(isRepeat) {};

      inline bool GetisRepeat() const 
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

   class KeyReleaseEvent : public KeyEvent
   {
      public:

         KeyReleaseEvent(int keyCode)
            : KeyEvent(keyCode) {};

         std::string ToString() const override
         {
            std::stringstream ss;
            ss << "Keyrelease: " << m_keycode;

            return ss.str();
         }

         EVENT_CLASS_Function(KeyRelease);
   };

   class KeyTypeEvent : public KeyEvent
   {
      public:

         KeyTypeEvent(int keyCode)
            : KeyEvent(keyCode) {};

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
