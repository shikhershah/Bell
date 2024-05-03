#ifndef IMGUI_H
#define IMGUI_H

#include "Bell/Core/Application.h"
#include "Bell/Core/Layer.h"


#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace Bell
{

   class ImGuiLayer : public Layer
   {

   private: 
      bool blockEvents = true;

   public:
      ImGuiLayer();
      ~ImGuiLayer() = default;

      virtual void OnAttach() override;
      virtual void OnDetach() override;
      virtual void OnEvent(Event& event) override;
      
      void Begin();
      void End();

      void BlockEvents(bool block) {blockEvents = block;}



   };

}
#endif //IMGUI_H
