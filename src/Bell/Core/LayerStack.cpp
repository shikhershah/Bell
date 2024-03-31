
#include <algorithm>

#include "LayerStack.h"

namespace Bell
{

   void LayerStack::PushLayer(Layer* layer)
   {

      Layers.emplace(Layers.begin() + LayerIndex, layer);
      LayerIndex++;

   }

   void LayerStack::PushOverlay(Layer* overlay)
   {

      Layers.emplace_back(overlay);

   }

   void LayerStack::PopLayer(Layer* layer)
   {
      auto it = std::find(Layers.begin() + LayerIndex, Layers.end(), layer);

      if(it != Layers.end())
      {
         Layers.erase(it);
         LayerIndex--;
      }
   }

   
   void LayerStack::PopOverlay(Layer* overlay)
   {
      auto it = std::find(Layers.begin() + LayerIndex, Layers.end(), overlay);
      if (it != Layers.end())
      {
         overlay->OnDetach();
	 Layers.erase(it);
      }
   }


}






