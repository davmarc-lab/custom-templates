#pragma once

#include <GLFW/glfw3.h>

#include "Utils.hpp"
#include "Structs.hpp"

#include <string>

struct WindowSettings {
    std::string name = "GLFW Window";
    Pair<int> size{1600, 900};
    Pair<int> position{0, 0};

    bool maximized = false;
    bool vsync = true;
    Color bgColor = {0.3f, 0.3f, 0.3f, 1.0f};
};

class Window {
  public:

  private:
    GLFWwindow *m_context = nullptr;
};
