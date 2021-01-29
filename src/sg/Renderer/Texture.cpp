#include "Texture.hpp"

namespace sg {
    Texture::Texture(const SGchar* filename) {
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_set_flip_vertically_on_load(true);

        SGint width, height, nrChannels;
        SGuchar *data = stbi_load(filename, &width, &height, &nrChannels, 0);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }

    Texture::~Texture() {
        delete this;
    }

    void Texture::Bind() {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    void Texture::Unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};