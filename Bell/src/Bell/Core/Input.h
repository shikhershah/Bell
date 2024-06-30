#include <utility>   

namespace Bell
{

   class Input
   {

      public:
         
         static bool isKeyPressed(int keyCode);
         static bool isMousePressed(int Button);

         static std::pair<float, float> GetMousePosition();
         static float GetMouseX();
         static float GetMouseY();
   };


}
