#ifndef OPENGLBUFFER_H
#define OPENGLBUFFER_H

#include "Bell/Renderer/Buffer.h"

namespace Bell
{

    class OpenGLVertexBuffer : public VertexBuffer
    {
        private:
            uint32_t VertexBufferID;

            BufferLayout Layout;

        public:
            OpenGLVertexBuffer(float* vertices, uint32_t size);
            virtual ~OpenGLVertexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;

            virtual const BufferLayout& GetLayout() const override
            {
                return Layout;
            }
            virtual void SetLayout(const BufferLayout& layout) override 
            {
                Layout = layout;
            }


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