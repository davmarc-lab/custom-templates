#pragma once

#include "Layer.hpp"
#include "Window.hpp"

namespace ogl {

struct ImGuiConfig {};

class ImGuiManager : public Layer {
  public:
    ImGuiManager() = delete;

    ImGuiManager(const ImGuiConfig& config, void *context) : Layer("ImGui Manager"), m_context(context) {}

    virtual void onAttach();
    virtual void onDetach();

    virtual void onUpdate();
    virtual void onRender();

    virtual void begin();
    virtual void end();

  private:
    ImGuiConfig m_config;
    void *m_context;
};

} // namespace ogl
