
#include "Buffer.h"
#include "Renderer.h"
#include "Bell/Core/Logging.h"
#include "Bell/Platform/OpenGL/OpenGLBuffer.h"

#include <iostream>

namespace Bell
{
    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    {
        Engine_TRACE("Reached VertexBuff Create");
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None :
            
            return nullptr;
            
            break;
        case RendererAPI::OpenGL :
            printf("vertices: %f ", *vertices)  ;
            return new OpenGLVertexBuffer(vertices, size);

            break;
        
        default:
            break;
        }
       // return new OpenGLVertexBuffer(vertices, size);
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        Engine_TRACE("Create OpenGL IndexBuffer reached");
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None :
            
            return nullptr;
            
            break;
        case RendererAPI::OpenGL :
            
            return new OpenGLIndexBuffer(indices, size);

            break;
        
        default:
            break;
        }

    }

}