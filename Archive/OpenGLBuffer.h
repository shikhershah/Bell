#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Buffer.h"

namespace Bell
{

   class OpenGLVertexBuffer : public VertexBuffer
   {
      private:
         uint32_t RendererID;

      public:
        
         OpenGLVertexBuffer(float* vertices, uint32_t size);
         virtual ~OpenGLVertexBuffer(){};

         virtual void Bind() const;
         virtual void Unbind() const;

   };

   class OpenGLIndexBuffer : public IndexBuffer
   {

   };

}

#endif //OPENGLBUFFER_H
