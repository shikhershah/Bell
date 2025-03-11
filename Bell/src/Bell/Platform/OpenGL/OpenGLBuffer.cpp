#include "OpenGLBuffer.h"
#include "Bell/Core/Logging.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Bell
{
    // OpenGL Vertex Buffer Implementation
    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
    {
        Engine_TRACE("Reached OpenGL implementation of VertexBuffer");

        //glCreateBuffers(1, &VertexBufferID);
        glGenBuffers(1, &VertexBufferID);
        Engine_TRACE("Generated a buffer");

		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

        Engine_TRACE("Reached end of OpenGL implementation of VertexBuffer");
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &VertexBufferID);
    }

    void OpenGLVertexBuffer::Bind() const
    { 
        glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
    }

    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    //OpenGL Index Buffer Implementation
    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t size)
    {
        //printf("vertices: %d, %d, %d ", *indices, *indices+1, *indices+2);
        glGenBuffers(1, &IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &IndexBufferID);
    }

    void OpenGLIndexBuffer::Bind() const
    { 
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
    }

    void OpenGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}