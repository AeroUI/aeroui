/**
 * @file Texture.hpp
 * @author Krisna Pranav
 * @brief Texture[PNG, SVG]
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_TEXTURE_HPP__
#define __INCLUDE_TEXTURE_HPP__

#include "Vector.hpp"
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace AeroUI {

class Texture {
public:
    typedef std::function<uint32_t(const std::vector<uint8_t>&, uint32_t, uint32_t)> OnLoadSignature;

    static void setOnLoad(OnLoadSignature fn);
    static std::shared_ptr<Texture> load(const std::vector<uint8_t>& data, uint32_t width, uint32_t height);
    static std::shared_ptr<Texture> load(const char* path);
    static std::shared_ptr<Texture> loadPNG(const char* path);
    static std::shared_ptr<Texture> loadSVG(const char* path);
    static std::shared_ptr<Texture> loadSVG(const char* path, uint32_t width, uint32_t height);
    static std::shared_ptr<uint8_t> loadSVGData(const char* path, uint32_t width, uint32_t height);

    Texture();
    ~Texture();

    bool isValid() const;
    uint32_t getID() const;
    vector getSize() const;
    const char* path() const;

private:
    static OnLoadSignature s_onLoad;

    uint32_t m_ID { 0 };
    vector m_size {};
    std::string m_path {};
};

}

#endif 