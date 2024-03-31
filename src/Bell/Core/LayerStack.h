#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <vector>
#include <algorithm>

#include "Layer.h"

namespace Bell
{

   class LayerStack
   {
      private:
         std::vector<Layer*> Layers;

         unsigned int LayerIndex = 0;

      public:
         LayerStack() = default;
        // ~LayerStack();

         void PushLayer(Layer* layer);
         void PushOverlay(Layer* overlay);
         
         void PopLayer(Layer* layer);
         void PopOverlay(Layer* overlay);

         std::vector<Layer*>::iterator begin() { return Layers.begin(); }
         std::vector<Layer*>::iterator end() { return Layers.end();   }
         std::vector<Layer*>::reverse_iterator rbegin() { return Layers.rbegin(); }
         std::vector<Layer*>::reverse_iterator rend() { return Layers.rend(); }

        // std::vector<Layer*>::iterator 
   };


}


#endif //LAYERSTACK_H
