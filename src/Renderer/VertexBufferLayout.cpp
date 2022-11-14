#include "VertexBufferLayout.h"

namespace Renderer {

	VertexBufferLayout::VertexBufferLayout()
	: m_stride(0)
	{

	}

	void VertexBufferLayout::reserveElements(const size_t count) {
		m_layoutElements.reserve(count);
	}

	void VertexBufferLayout::addElementLayoutFloat(const unsigned int count, const bool normalized) {
		m_layoutElements.push_back({ static_cast<GLint>(count), GL_FLOAT, normalized, static_cast<unsigned int>(count * sizeof(GLfloat)) });
		m_stride += m_layoutElements.back().size;
	}

}