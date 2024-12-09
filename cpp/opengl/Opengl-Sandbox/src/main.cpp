#include <iostream>

#include "../../Opengl-Core/include/Core.hpp"

int main(int argc, char *argv[]) {
    ogl::WindowSettings s{};
    s.decorated = false;

    ogl::Window w{s};
    w.onAttach();

    while (!glfwWindowShouldClose(w.getContext())) {
        w.onUpdate();
        w.onRender();
    }

    w.onDetach();

    return 0;
}
