
#include "Bell/Core/Input.h"
#include "Bell/Core/Application.h"

#include "GLFW/glfw3.h"


namespace Bell
{

   bool Input::isKeyPressed(int keyCode)
   {
      auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      auto state = glfwGetKey(window, keyCode);
      
      return state == GLFW_PRESS;
   }

   bool Input ::isMousePressed(int Button)
   {
      auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      auto state = glfwGetMouseButton(window, Button);

      return state == GLFW_PRESS;
   }

   std::pair<float, float> Input::GetMousePosition()
   {
      auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      double xpos, ypos;
      glfwGetCursorPos(window, &xpos, &ypos);

      return { (float)xpos, (float)ypos };   
   }

   float Input::GetMouseX()
   {
      auto [x,y] = GetMousePosition();

      return x;
   }

   float Input::GetMouseY()
   {
      auto [x,y] = GetMousePosition();

      return y;
   }

}
