#pragma once

#include "Layer.hpp"

#include "Window.hpp"

namespace ogl {

class ImGuiManager : public Layer {
  public:
    ImGuiManager() = delete;
    ImGuiManager(const std::string &layerName, Window &window, const ImGuiConfigFlags &flags = 0)
        : Layer(std::move(layerName)), m_window(window), m_flags(flags) {}

    ImGuiManager(Window &window, const ImGuiConfigFlags &flags)
        : Layer("ImGui Manager"), m_flags(flags), m_window(window) {}

    virtual void onAttach() override;
    virtual void onDetach() override;

    virtual void onUpdate() override;
    virtual void onRender() override;

    virtual void begin() override;
    virtual void end() override;

  private:
    ImGuiConfigFlags m_flags = 0;
    Window &m_window;
};

} // namespace ogl
