
#include "Bell/Core/Logging.h"

#include "ImGuiLayer.h"
#include "Bell/Core/Application.h"

namespace Bell
{

   ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
   {
   }

   void ImGuiLayer::OnAttach()
   {

      // Setup Dear ImGui context
      IMGUI_CHECKVERSION();
      ImGui::CreateContext();
      ImGuiIO& io = ImGui::GetIO();
      io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
      //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch


      Application& app = Application::Get();
      GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

      // Setup Platform/Renderer backends
      ImGui_ImplGlfw_InitForOpenGL(window, true);

      Engine_INFO("IMGUI INIT"); 
      ImGui_ImplOpenGL3_Init();
   }

   void ImGuiLayer::OnDetach()
   {
      ImGui_ImplOpenGL3_Shutdown();
      ImGui_ImplGlfw_Shutdown();
      ImGui::DestroyContext();


   }
   
   void ImGuiLayer::OnEvent(Event& event)
   {
      if(blockEvents == true)
      {

         ImGuiIO& io = ImGui::GetIO();

         event.Handled |= event.IsEventType(Mouse) & io.WantCaptureMouse;
	      event.Handled |= event.IsEventType(Keyboard) & io.WantCaptureKeyboard;

      }
   

   }

   void ImGuiLayer::Begin()
   {
      // Start the Dear ImGui frame
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      static bool show = true;
      ImGui::ShowDemoWindow(&show);

      //ImVec2 startingPos;

      //startingPos.x = -414.59;
      //startingPos.y = 111.047;

      //ImGui::SetWindowPos(startingPos, true);

      

  //    Engine_INFO("IMGUI show demo window");

   }

   void ImGuiLayer::End()
   {
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
   }


}
