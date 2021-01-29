#include "sg/Core.hpp"

#include "../vendor/SimplexNoise/SimplexNoise.h"

void closeCallback(GLFWwindow* window) {
    exit(EXIT_FAILURE);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        closeCallback(window);
    }
}

float verts[] = {
	 0.0f, 0.5f, 0.0f,  0.0f, 0.5f,
	 0.5f, 0.0f, 0.0f,  0.5f, 0.0f,
	-0.5f, 0.0f, 0.0f, -0.5f, 0.0f
};

float indices[] = {
    0.0f, 1.0f, 2.0f,
    2.0f, 1.0f, 3.0f
};

int main(int argv, char** argc) {
    sg::Core core(4, 6, SGtrue);

    sg::Window window;
    window.MakeWindowContext();

    core.InitGLLoader((SGloader)glfwGetProcAddress);

    sg::Log logger;
    logger.Initialize(core.GetDebugMode());

    glViewport(0, 0, 1280, 720);
    glfwSetWindowCloseCallback(window.GetWindow(), closeCallback);
    glfwSetKeyCallback(window.GetWindow(), keyCallback);

    //SimplexNoise test;
    //std::cout << test.noise(rand() % 10, rand() % 10) << "\n";

    sg::Shader shader("vert.glsl", "frag.glsl", SGtrue, window.GetWindow());

    sg::VertexBuffer vb(verts, sizeof(verts));
    vb.SetLayout({sg::VertexAttribType::Float3, sg::VertexAttribType::Float2});

    while(window.GetStatus()) {
		window.Clear(0.2f, 0.3f, 0.3f, 1.0f);

        shader.Bind();
        vb.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.Update();
    }
}