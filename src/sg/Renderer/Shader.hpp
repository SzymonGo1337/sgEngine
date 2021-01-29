#pragma once
#ifndef SG_SHADER
#define SG_SHADER

#include "../Core.hpp"

namespace sg {
    class Shader {
        public:
            Shader(const SGchar* vertexShaderSource, const SGchar* fragmentShaderSource, GLFWwindow* window);
            Shader(std::string vertexFilename, std::string fragmentFilename, SGbool load, GLFWwindow* window);
            ~Shader();

            void Bind();
            void Unbind();
            
            SGuint GetUniformLocation(SGchar* uniform);
            SGuint GetProgram();

        private:
            SGuint m_program;
    };
};

#endif