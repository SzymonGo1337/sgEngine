#include "Logger.hpp"

namespace sg {
    Log::Log() { }

    Log::Log(SGint code, SGchar* message, SGbool critical) {
        if(critical) {
            std::cout << SG_CRITICAL_ERROR_PREFIX << " " << message << " | " << code << SG_ENDLINE;
            std::cin.get();
            exit(EXIT_FAILURE);
        } else {
            std::cout << SG_ERROR_PREFIX << " " << message << " | " << code << SG_ENDLINE;
        }
    }

    Log::Log(SGint code, SGchar* message, SGbool critical, GLFWwindow* window) {
        if(critical) {
            glfwHideWindow(window);
            std::cout << SG_CRITICAL_ERROR_PREFIX << " " << message << " | " << code << SG_ENDLINE;
            std::cin.get();
            exit(EXIT_FAILURE);
        } else {
            std::cout << SG_ERROR_PREFIX << " " << message << " | " << code << SG_ENDLINE;
        }
    }

    Log::Log(SGchar* prefix, SGchar* message) {
        std::cout << prefix << " " << message << SG_ENDLINE;
    }

    Log::~Log() {
        delete this;
    }

    void Log::Initialize(SGbool debug) {
        if(debug) {
            std::cout << SG_DEBUG_PREFIX << " " << "Debug Mode: Activated" << SG_ENDLINE;
            std::cout << SG_DEBUG_PREFIX << " " << "OpenGL Version: " << glGetString(GL_VERSION) << SG_ENDLINE;
            std::cout << SG_DEBUG_PREFIX << " " << "sgEngine Version: " << SG_ENGINE_VERSION << SG_ENDLINE;
        }
    }
};