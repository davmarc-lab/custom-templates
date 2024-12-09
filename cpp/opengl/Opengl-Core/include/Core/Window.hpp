#pragma once

#include "../Graphic.hpp"

#include "Layer.hpp"
#include "Structs.hpp"
#include "Utils.hpp"

#include <string>

namespace ogl {

struct WindowSettings {
    std::string name = "GLFW Window";
    Pair<int> size{1600, 900};
    Pair<int> position{0, 0};

    bool maximized = false;
    bool fullscreen = false;
    bool focused = true;
    bool decorated = true;
    bool vsync = true;
    Color bgColor = {0.3f, 0.3f, 0.3f, 1.0f};
};

class Window : public Layer {
  public:
    Window(const WindowSettings &settings);
    Window() = delete;
    ~Window() = default;

    inline GLFWwindow* getContext() const { return this->m_context; }

    inline int getWidth() const { return this->m_settings.size.x; }
    void setWidth(const int &val) { this->m_settings.size.x = val; }

    inline int getHeight() const { return this->m_settings.size.y; }
    void setHeight(const int &val) { this->m_settings.size.y = val; }

    void toggleVsync();
    bool isVsyncEnabled() const;

    virtual void onAttach() override;
    virtual void onDetach() override;

    virtual void onUpdate() override;
    virtual void onRender() override;

    virtual void begin() override;
    virtual void end() override;

  private:
    GLFWwindow *m_context = nullptr;
    WindowSettings m_settings{};
    unsigned int m_clearMask = 0;
};

} // namespace ogl
