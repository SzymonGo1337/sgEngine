#include "VertexBuffer.hpp"

namespace sg {
    VertexBuffer::VertexBuffer(SGulong size) : m_static(SGfalse) {
        glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 5, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(float) * 5, (void*)(sizeof(float) * 3));
    }
        
    VertexBuffer::VertexBuffer(const void* data, SGulong size) {
        glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 5, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(float) * 5, (void*)(sizeof(float) * 3));
    }

	VertexBuffer::~VertexBuffer() {
		delete this;
	}

    void VertexBuffer::SetData(const void* data, SGulong size) const {
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    SGulong VertexBuffer::_GetAttribSize(VertexAttribType attrib) const {
		switch (attrib) {
			case sg::VertexAttribType::Float:
			return sizeof(float);
			case sg::VertexAttribType::Float2:
			return sizeof(float) * 2;
			case sg::VertexAttribType::Float3:
			return sizeof(float) * 3;
			case sg::VertexAttribType::Float4:
			return sizeof(float) * 4;

			case sg::VertexAttribType::Int:
			case sg::VertexAttribType::Int2:
			case sg::VertexAttribType::Int3:
			case sg::VertexAttribType::Int4:
			return sizeof(int);

			case sg::VertexAttribType::Texture:
			return sizeof(int);

			case sg::VertexAttribType::Byte:
			return sizeof(char);
		}
	}
    
    void VertexBuffer::SetLayout(const std::vector<VertexAttribType>& layout) const {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
		SGulong size = [&]() {
			SGulong size = 0;
			for(auto attrib : layout)
				size += _GetAttribSize(attrib);
			return size;
		} ();
		SGulong stride = 0;
		for (SGuint i = 0; i < layout.size(); i++) {
			glEnableVertexAttribArray(i);
			auto attrib = layout[i];
			switch (attrib) {
				case VertexAttribType::Float:
					glVertexAttribPointer(i, 1, GL_FLOAT, false, size, (void*)stride);
				break;
				case VertexAttribType::Float2:
					glVertexAttribPointer(i, 2, GL_FLOAT, false, size, (void*)stride);
				break;
				case VertexAttribType::Float3:
					glVertexAttribPointer(i, 3, GL_FLOAT, false, size, (void*)stride);
				break;
				case VertexAttribType::Float4:
					glVertexAttribPointer(i, 4, GL_FLOAT, false, size, (void*)stride);
				break;
			}

			stride += _GetAttribSize(attrib);
		}
    }

    void VertexBuffer::Bind() const {
        glBindVertexArray(VAO);
    }
    
    void VertexBuffer::Unbind() const {
        glBindVertexArray(0);
    }

    SGuint VertexBuffer::GetVBO() const {
        return VBO;
    }

    SGuint VertexBuffer::GetVAO() const {
        return VAO;
    }
};