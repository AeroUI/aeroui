/**
 * @file AeroImage.hpp
 * @author your name (you@domain.com)
 * @brief Image Loading Functionalities
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __INCLUDE_AERO_IMAGE_HPP__
#define __INCLUDE_AERO_IMAGE_HPP__

#include <cstring>
#include "AeroRect.hpp"

namespace AeroUI {

    class Texture;
    
    // TODO: add adv image functionalities
    class Image {
    public:
        virtual ~Image();

        Image& setTexture(const char* path);
        Image& setTexture(const std::shared_ptr<Texture>* inTexture);
        Image& setUVs(const Rect& UVs);
    
    protected:
        virtual bool isFixedSize() const override;

    private:
        std::shared_ptr<Texture> m_texture { nullptr };
        Rect m_UVs {};
    }
}

#endif /* __INCLUDE_AERO_IMAGE_HPP__ */