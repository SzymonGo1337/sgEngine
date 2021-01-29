#pragma once
#ifndef SG_VERTEXBUFFER
#define SG_VERTEXBUFFER

#include "../Core.hpp"

namespace sg {
    enum class VertexAttribType;

    class VertexBuffer {
        public:
            VertexBuffer(SGulong size);
            VertexBuffer(const void* data, SGulong size);
            ~VertexBuffer();

            void SetData(const void* data, SGulong size) const;
            void SetLayout(const std::vector<VertexAttribType>& layout) const;

            void Bind() const;
            void Unbind() const;

            SGuint GetVBO() const;
            SGuint GetVAO() const;

        private:
            SGuint VBO, VAO;
            SGbool m_static = SGfalse;
            
            SGulong _GetAttribSize(VertexAttribType layout) const;
    };

    enum class VertexAttribType {
        Float, Float2, Float3, Float4,
		Int, Int2, Int3, Int4,
		Texture, Byte
    };
};

#endif