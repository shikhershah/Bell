
#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Bell
{


   class GraphicsContext
   {

      public:
         virtual ~GraphicsContext() = default;

         virtual void Init() = 0;
         virtual void SwapBuffer() = 0 ;

         static  std::unique_ptr<GraphicsContext>Create(void* window);  

   };

}



#endif //GRAPHICSCONTEXT_H
