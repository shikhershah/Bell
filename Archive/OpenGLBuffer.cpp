#include "OpenGLBuffer.h"
#include <glad/glad.h>

namespace Bell
{

   OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
   {
      glCreateBuffers(1, &RendererID);
      glBufferData(GL_ARRAY_BUFFER, size, vertices,GL_STATIC_DRAW);

   }

   OpenGLVertexBuffer::~OpenGLVertexBuffer()
   {

      glDeleteBuffers(1, &RendererID);
   }

   void OpenGLVertexBuffer::Bind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER, RendererID);
   }

   void OpenGLVertexBuffer::Unbind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER,0);
   }


}

