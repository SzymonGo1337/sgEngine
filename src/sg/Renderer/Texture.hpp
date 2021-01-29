#pragma once
#ifndef SG_TEXTURE
#define SG_TEXTURE

#include "../Core.hpp"

namespace sg {
    class Texture {
        public:
            Texture(const SGchar* filename);
            ~Texture();

            void Bind();
            void Unbind();

        private:
            SGuint m_texture;
    };
};

#endif