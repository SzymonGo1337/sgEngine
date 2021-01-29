#include "Core.hpp"

namespace sg {
    Core::Core(SGint versionMajor, SGint versionMinor, SGbool debugMode) : m_versionMajor(versionMajor), m_versionMinor(versionMinor), m_debugMode(debugMode) {
        #ifdef _WIN32
            system("Setlocal");
        #endif
        srand(time(NULL));
        Initialize();
    }

    Core::~Core() {
        delete this;
    }

    void Core::Initialize() {
        if(!glfwInit()) {
            sg::Log(1, "GLFW Init Error", SGtrue);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_versionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_versionMinor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        m_initialized = SGtrue;
    }

    void Core::InitGLLoader(SGloader procAddress) {
        gladLoadGLLoader(procAddress);
    }

    SGint Core::GetVersionMajor() {
        return m_versionMajor;
    }

    SGint Core::GetVersionMinor() {
        return m_versionMinor;
    }

    SGbool Core::GetDebugMode() {
        return m_debugMode;
    }
};