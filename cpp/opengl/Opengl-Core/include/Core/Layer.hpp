#pragma once

#include <string>

namespace ogl {
class Layer {
  public:
    Layer(const std::string &name) : m_name(std::move(name)) {}
    Layer() : Layer("Simple Layer") {}
    Layer(const Layer &other) = delete;
    ~Layer() = default;

    virtual void onAttach() {}
    virtual void onDetach() {}

    virtual void onUpdate() {}
    virtual void onRender() {}

    virtual void begin() {}
    virtual void end() {}

  protected:
    std::string m_name{"Layer"};
    bool m_attached = false;
};
} // namespace ogl
