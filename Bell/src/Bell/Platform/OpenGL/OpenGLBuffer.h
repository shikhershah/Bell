#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Bell/Renderer/Buffer.h"

namespace Bell
{

    class OpenGLVertexBuffer : public VertexBuffer
    {
        private:
            uint32_t VertexBufferID;

        public:
            OpenGLVertexBuffer(float* vertices, uint32_t size);
            virtual ~OpenGLVertexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;

    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
        private:
            uint32_t IndexBufferID;

        public:
            OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
            virtual ~OpenGLIndexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;

    };
}








#endif //OPENGLBUFFER_H