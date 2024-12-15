#include <iostream>
#include <vector>

#include "../../Opengl-Core/include/Core.hpp"

struct vec3 {
    float x, y, z;
};

int main(int argc, char *argv[]) {
    ogl::WindowSettings s{};
    s.decorated = false;

    ogl::Window w{s};
    w.onAttach();

    ogl::VertexBuffer vb{};
    std::vector<vec3> v{{2, 3, 4}, {1, 1, 1}};
    vb.setup(v.data(), v.size(), 0);

    while (!glfwWindowShouldClose(w.getContext())) {
        w.onUpdate();
        w.onRender();
    }

    w.onDetach();

    return 0;
}
