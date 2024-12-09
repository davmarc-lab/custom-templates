#include "../../include/Core/Window.hpp"

#include "../../include/Graphic.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

namespace ogl {
// error callback
static void errorCallback(int code, const char* description) {
    std::cerr << "GLFW error (" << code << ") -> (" << description << ")\n";
}

// resize Callback
static void resizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);

    auto pt = (Window *)glfwGetWindowUserPointer(window);
    pt->setWidth(width);
    pt->setHeight(height);
}

// keyboard input callback
static void keyboardCallback(GLFWwindow *window, int key, int code, int action, int mod) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

Window::Window(const WindowSettings &settings) : Layer("GLFW Window"), m_settings(settings) {}

void Window::toggleVsync() {
    this->m_settings.vsync = !this->m_settings.vsync;
    glfwSwapInterval(this->m_settings.vsync ? 1 : 0);
}

bool Window::isVsyncEnabled() const { return this->m_settings.vsync; }

void Window::onAttach() {
    if (this->m_attached)
        return;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glfwSetErrorCallback(errorCallback);

    this->m_context = glfwCreateWindow(this->m_settings.size.x, this->m_settings.size.y, this->m_settings.name.c_str(),
                                       this->m_settings.fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    ASSERT(this->m_context != nullptr);

    glfwMakeContextCurrent(this->m_context);
    glfwSetWindowUserPointer(this->m_context, this);

    // custom parameters
    if (this->m_settings.maximized)
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    if (this->m_settings.focused)
        glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);

    if (this->m_settings.decorated)
        glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

    // icon???

    // init glad for this context
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        /* BT_ERROR_CORE("Failed to initialize GLAD."); */
        glfwTerminate();
        /* BT_INFO_CORE("To be replaced with event."); */
        exit(EXIT_FAILURE);
    }

    // resize callback
    glfwSetFramebufferSizeCallback(this->m_context, resizeCallback);

    // keyboard callback
    glfwSetKeyCallback(this->m_context, keyboardCallback);

    // error callback

    // debug callback

    // enable blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    this->m_clearMask |= GL_COLOR_BUFFER_BIT;

    // missing depth and cull structs

    this->m_attached = true;
}

void Window::onDetach() { glfwDestroyWindow(this->m_context); }

void Window::onUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(this->m_context);
}

void Window::onRender() {
    glClearColor(this->m_settings.bgColor.r, this->m_settings.bgColor.g, this->m_settings.bgColor.b, this->m_settings.bgColor.a);
    glClear(this->m_clearMask);
}

void Window::begin() {}

void Window::end() {}

} // namespace ogl
