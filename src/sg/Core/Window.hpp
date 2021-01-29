#pragma once
#ifndef SG_WINDOW
#define SG_WINDOW

#include "../Core.hpp"

namespace sg {
    class Window {
        public:
            Window(SGchar* title = "sgEngine", SGint width = 1280, SGint height = 720);
            ~Window();

            void MakeWindowContext();
            void Clear(SGfloat r, SGfloat g, SGfloat b, SGfloat a);
            void Update();
            void SetVSync(SGbool enabled);
            void SetIcon(SGchar* filename);
            void Shutdown();

            SGbool GetStatus();
            GLFWwindow* GetWindow();

        private:
            SGbool m_isRuning, m_vsync;
            GLFWwindow* m_window;
    };
};

#endif