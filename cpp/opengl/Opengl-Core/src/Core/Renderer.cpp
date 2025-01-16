#include "../../include/Core/Renderer.hpp"

#include "../../include/Graphic.hpp"

namespace ogl {

void Renderer::drawArrays(const unsigned int &vao, const unsigned int &mode, const int &first, const size_t &size) {
    glBindVertexArray(vao);
    glDrawArrays(mode, first, size);
    this->m_stats.drawCalls++;
}

void Renderer::drawElements(const unsigned int &vao, const unsigned int &mode, const size_t &size, const unsigned int &type, const void *indices) {
    glBindVertexArray(vao);
    glDrawElements(mode, size, type, indices);
    this->m_stats.drawCalls++;
}

} // namespace ogl
