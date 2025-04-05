#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <vector>
#include <string>

namespace Bell
{
   enum class ShaderDataType
   {
      None = 0,
      Int,
      Int2,
      Int3,
      Int4,
      Float,
      Float2,
      Float3,
      Float4,
      Mat3,
      Mat4,
      Bool
   };

   static uint32_t ShaderDataTypeSize(ShaderDataType type)
   {
      switch(type)
      {
         case ShaderDataType::Int:
            return 4;
            break;
         case ShaderDataType::Int2:
            return 4*2;
            break;
         case ShaderDataType::Int3:
            return 4*3;
            break;
         case ShaderDataType::Int4:
            return 4*4;
            break;
         case ShaderDataType::Float:
            return 4;
            break;
         case ShaderDataType::Float2:
            return 4*2;
            break;
         case ShaderDataType::Float3:
            return 4*3;
            break;
         case ShaderDataType::Float4:
            return 4*4;
            break;
         case ShaderDataType::Mat3:
            return 4*3*3;
            break;
         case ShaderDataType::Mat4:
            return 4 * 4 * 4;
            break;
         case ShaderDataType::Bool:
            return 1;
            break;

      }
      
      return 0;
   }

   struct BufferElement
   {
      std::string Name;
      ShaderDataType ShaderType;
      uint32_t Size;
      size_t Offset;
      bool Normalized;

      BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Name(name), ShaderType(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
		{
		}

      uint32_t GetComponentCount() const
		{
			switch (ShaderType)
			{
            case ShaderDataType::Int:     return 1;
				case ShaderDataType::Int2:    return 2;
				case ShaderDataType::Int3:    return 3;
				case ShaderDataType::Int4:    return 4;
				case ShaderDataType::Float:   return 1;
				case ShaderDataType::Float2:  return 2;
				case ShaderDataType::Float3:  return 3;
				case ShaderDataType::Float4:  return 4;
				case ShaderDataType::Mat3:    return 3; // 3* float3
				case ShaderDataType::Mat4:    return 4; // 4* float4
				case ShaderDataType::Bool:    return 1;
			}

			
			return 0;
		}
   };

   class BufferLayout
   {
      private:
         
         std::vector<BufferElement> Elements;

         uint32_t stride;

         void CalculateOffsetAndStride()
         {
            size_t offset = 0;
            stride = 0;

            for (auto& element : Elements)
			   {
				   element.Offset = offset;
				   offset += element.Size;
				   stride += element.Size;
			   }
         }


      public:

         BufferLayout() {}
      
         BufferLayout(std::initializer_list<BufferElement> elements) : Elements(elements)
         {
            CalculateOffsetAndStride();
         }

         inline const std::vector<BufferElement> &GetElements() const {return Elements;}

         std::vector<BufferElement>::iterator begin() { return Elements.begin(); }
         std::vector<BufferElement>::iterator end() { return Elements.end(); }

         std::vector<BufferElement>::const_iterator begin() const { return Elements.begin(); }
         std::vector<BufferElement>::const_iterator end() const { return Elements.end(); }

         uint32_t GetStride() const { return stride; }

   };

   class VertexBuffer
   {

      private:


      public:

         virtual ~VertexBuffer() = default;

         virtual void Bind() const = 0;
         virtual void Unbind() const = 0;

         virtual void SetLayout(const BufferLayout& layout) = 0;
         virtual const BufferLayout& GetLayout() const = 0;

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
