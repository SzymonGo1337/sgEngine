#include "Shader.hpp"

namespace sg {
    Shader::Shader(const SGchar* vertexShaderSource, const SGchar* fragmentShaderSource, GLFWwindow* window) {
        SGint success;
        SGuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, SGnull);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            sg::Log(512, "Vertex Shader Compilation Error", SGtrue, window);
        }

        SGuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, SGnull);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            sg::Log(512, "Fragment Shader Compilation Error", SGtrue, window);
        }

        m_program = glCreateProgram();
        glAttachShader(m_program, vertexShader);
        glAttachShader(m_program, fragmentShader);
        glLinkProgram(m_program);
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);
        if(!success) {
            sg::Log(512, "Program Shader Link Error", SGtrue, window);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    Shader::Shader(std::string vertexFilename, std::string fragmentFilename, SGbool load, GLFWwindow* window) {
        std::string content1, content2;
        std::ifstream vertexFile(vertexFilename, std::ios::in);
        std::ifstream fragmentFile(fragmentFilename, std::ios::in);

        if(!vertexFile.is_open()) {
            sg::Log(440, "Vertex Shader Loading Error", SGtrue, window);
        }

        std::string line1 = "";
        while(!vertexFile.eof()) {
            std::getline(vertexFile, line1);
            content1.append(line1 + "\n");
        }

        vertexFile.close();
        const SGchar* vertexShaderSource = content1.c_str();

        if(!fragmentFile.is_open()) {
            sg::Log(440, "Fragment Shader Loading Error", SGtrue, window);
        }

        std::string line2 = "";
        while(!fragmentFile.eof()) {
            std::getline(fragmentFile, line2);
            content2.append(line2 + "\n");
        }

        fragmentFile.close();
        const SGchar* fragmentShaderSource = content2.c_str();

        SGint success;
        SGuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, SGnull);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            sg::Log(512, "Vertex Shader Compilation Error", SGtrue, window);
        }

        SGuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, SGnull);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            sg::Log(512, "Fragment Shader Compilation Error", SGtrue, window);
        }

        m_program = glCreateProgram();
        glAttachShader(m_program, vertexShader);
        glAttachShader(m_program, fragmentShader);
        glLinkProgram(m_program);
        glGetProgramiv(m_program, GL_LINK_STATUS, &success);
        if(!success) {
            sg::Log(512, "Program Shader Link Error", SGtrue, window);
        }
    }

    Shader::~Shader() {
        delete this;
    }

    void Shader::Bind() {
        glUseProgram(m_program);
    }
    
    void Shader::Unbind() {
        glUseProgram(0);
    }

    SGuint Shader::GetUniformLocation(SGchar* uniform) {
        return glGetUniformLocation(GetProgram(), uniform);
    }

    SGuint Shader::GetProgram() {
        return m_program;
    }
};