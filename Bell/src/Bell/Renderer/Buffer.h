#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

namespace Bell
{

   class VertexBuffer
   {

      private:


      public:

         virtual ~VertexBuffer() = default;

         virtual void Bind() const = 0;
         virtual void Unbind() const = 0;

         static VertexBuffer* Create(float* vertices, uint32_t size);
   };

   class IndexBuffer
   {

      private:


      public:

         virtual ~IndexBuffer() = default;

         virtual void Bind() const = 0;
         virtual void Unbind() const = 0;

         static IndexBuffer* Create(uint32_t* indices, uint32_t size);
   };

}

#endif //BUFFER_H
