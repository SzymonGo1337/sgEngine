#include "Window.hpp"

namespace sg {
    Window::Window(SGchar* title, SGint width, SGint height) : m_isRuning(SGtrue) {
        #ifdef __APPLE__
    		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		#endif

        m_window = glfwCreateWindow(width, height, title, SGnull, SGnull);
    }

    Window::~Window() {
        delete this;
    }

    void Window::MakeWindowContext() {
        glfwMakeContextCurrent(m_window);
    }

    void Window::Clear(SGfloat r, SGfloat g, SGfloat b, SGfloat a) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, a);
    }
    
    void Window::Update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
    
    void Window::SetVSync(SGbool enabled) {
        if(enabled != m_vsync) {
            glfwSwapInterval(enabled);
            m_vsync = enabled;
        }
    }

    void Window::SetIcon(SGchar* filename) {
        GLFWimage icons[1];
        icons[0].pixels = SOIL_load_image(filename, &icons[0].width, &icons[0].height, 0, SOIL_LOAD_RGBA);
        glfwSetWindowIcon(m_window, 1, icons);
        SOIL_free_image_data(icons[0].pixels);
    }

    void Window::Shutdown() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    SGbool Window::GetStatus() {
        return m_isRuning;
    }

    GLFWwindow* Window::GetWindow() {
        return m_window;
    }
};