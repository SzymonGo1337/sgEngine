#pragma once
#ifndef SG_LOGGER
#define SG_LOGGER

#include "../Core.hpp"

namespace sg {
    class Log {
        public:
            Log();
            Log(SGint code, SGchar* message, SGbool critical);
            Log(SGint code, SGchar* message, SGbool critical, GLFWwindow* window);
            Log(SGchar* prefix, SGchar* message);
            ~Log();

            void Initialize(SGbool debug = SGfalse);
    };
};

#endif