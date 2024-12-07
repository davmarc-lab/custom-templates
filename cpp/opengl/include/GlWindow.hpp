#pragma once

#include "Utils.hpp"
#include <GLFW/glfw3.h>
#include <string>

struct WindowSettings {
    std::string name = "GLFW Window";
    Pair<int> size{1600, 900};
    Pair<int> position{0, 0};

    bool maximized = false;
    bool vsync = true;
    Color bgColor = {0.3f, 0.3f, 0.3f, 1.0f};

};

class GlWindow {
  public:

  private:
    Unique<GLFWwindow> m_context = nullptr;
};
