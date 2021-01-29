#pragma once
#ifndef SG_CORE
#define SG_CORE

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <SOIL2/SOIL2.h>
#include <SOIL2/stb_image.h>

#define SG_ENGINE_VERSION "0.1.4"

#include <math.h>
#include <time.h>
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <chrono>
#include <filesystem>
#include <sstream>
#include <string>

typedef int SGint;
typedef unsigned int SGuint;
typedef float SGfloat;
typedef long SGufloat;
typedef unsigned long SGulong;
typedef char SGchar;
typedef unsigned char SGuchar;
typedef bool SGbool;
typedef void (*SGvoid)(void);

#ifdef __unix__
    #define SG_LINUX
#elif defined(_WIN32) || defined(WIN32)
    #define SG_WINDOWS
#endif

#ifdef __APPLE__
    #define SG_APPLE
#endif

#define SGtrue true
#define SGfalse false
#define SGnull NULL
#define SGnullptr nullptr
#define SGloader GLADloadproc

#define SG_ENDLINE "[0m\n"
#define SG_DEBUG_PREFIX "[90m[[36mDEBUG[90m]"
#define SG_ERROR_PREFIX "[90m[[33mERROR[90m]"
#define SG_CRITICAL_ERROR_PREFIX "[90m[[31mCRITICAL ERROR[90m]"

#include "../sg/Core/Logger.hpp"
#include "../sg/Core/Window.hpp"

#include "../sg/Renderer/Shader.hpp"
#include "../sg/Renderer/Texture.hpp"
#include "../sg/Renderer/VertexBuffer.hpp"

namespace sg {
    class Core {
        public:
            Core(SGint versionMajor = 3, SGint versionMinor = 3, SGbool debugMode = SGfalse);
            ~Core();

            void Initialize();
            void InitGLLoader(SGloader procAddress);

            SGint GetVersionMajor();
            SGint GetVersionMinor();
            SGbool GetDebugMode();

        private:
            SGbool m_initialized, m_debugMode;
            SGint m_versionMajor, m_versionMinor;
    };
};

template<typename T, uint32_t D>
using SGvec = glm::vec<D, T>;

using SGfloat2 = SGvec<float, 2>;
using SGfloat3 = SGvec<float, 3>;
using SGfloat4 = SGvec<float, 4>;

using SGuint2 = SGvec<uint32_t, 2>;
using SGuint3 = SGvec<uint32_t, 3>;
using SGuint4 = SGvec<uint32_t, 4>;

using SGint2 = SGvec<int, 2>;
using SGint3 = SGvec<int, 3>;
using SGint4 = SGvec<int, 4>;

using SGMat4 = glm::mat4;

using SGColor = SGvec<float, 4>;

template<typename T>
std::ostream& operator<<(std::ostream& os, const SGvec<T, 2>& v) {
	os << "(x=" << v.x << ", y=" << v.y << ")";
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const SGvec<T, 3>& v) {
	os << "(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
	return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const SGvec<T, 4>& v) {
	os << "(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ", w=" << v.w << ")";
	return os;
}

#endif