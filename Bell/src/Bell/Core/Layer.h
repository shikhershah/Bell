#ifndef LAYER_H
#define LAYER_H

#include "Bell/Events/Event.h"
#include "Bell/Core/Timestep.h"

namespace Bell
{
   class Layer
   {

   protected:
      std::string LayerName;

   public:
      Layer(const std::string& name = "Layer");

      virtual void OnAttach() {}
      virtual void OnDetach() {}
      virtual void OnUpdate() {}
      virtual void OnImGuiRender() {}
      virtual void OnEvent(Event& event) {}

      const std::string& GetLayerName() const {return LayerName; }
   };

}
#endif //LAYER_H
