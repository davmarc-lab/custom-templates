#pragma once

#include "Utils.hpp"

#include <cstddef>

namespace ogl {

struct RendererStats {
    int drawCalls = 0;
};

class Renderer {
  public:
    void drawArrays(const unsigned int &vao, const unsigned int &mode, const int &first, const size_t &size);

    void drawElements(const unsigned int &vao, const unsigned int &mode, const size_t& size, const unsigned int &type, const void *indices);

    RendererStats getRendererStats() const { return this->m_stats; }

    Renderer(Renderer &other) = delete;

    void operator=(const Renderer &other) = delete;

    inline static Shared<Renderer> instance() {
        if (s_pointer == nullptr) {
            Shared<Renderer> copy(new Renderer());
            copy.swap(s_pointer);
        }
        return s_pointer;
    }

    ~Renderer() = default;

  private:
    Renderer() = default;

    inline static Shared<Renderer> s_pointer = nullptr;

    RendererStats m_stats{};
};

} // namespace ogl
