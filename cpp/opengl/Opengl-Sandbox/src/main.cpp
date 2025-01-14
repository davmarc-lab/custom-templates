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

    ogl::FrameBuffer fb{{GL_FRAMEBUFFER, 100, 100}};
    fb.onAttach();

    fb.setRenderBuffer({GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, 100, 100});

    ogl::Texture t = ogl::Texture({GL_TEXTURE_2D, 0, GL_RGB, 0, GL_RGB, GL_UNSIGNED_BYTE}, 100, 100);
    t.onAttach();
    t.createTexture2D(NULL);
    t.setTexParameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    t.setTexParameteri(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    fb.setColorTexture(t);

    std::cout << fb.createFrameBuffer() << "\n";

    ogl::UniformBuffer ub("name");
    ub.onAttach();
    ub.bind();
    ub.unbind();
    ub.onDetach();

    while (!glfwWindowShouldClose(w.getContext())) {
        w.onUpdate();
        w.onRender();
    }

    w.onDetach();

    return 0;
}
