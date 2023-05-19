/**
 * @file AeroIcons.cpp
 * @author Krisna Pranav
 * @brief AeroIcons functionalities
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#include "include/AeroIcon.hpp"
#include "include/AeroColour.hpp"
#include "AeroTexture.hpp"
#include <cstring>

namespace AeroUI {

    /**
     * @brief toString obj
     * 
     * @param inType 
     * @return const char* 
     */
    const char* Icons::toString(Type inType) {
        switch (inType) {
            case Type::ArrowLeft: return "ArrowLeft";
            case Type::ArrowRight: return "ArrowRight";
            case Type::ArrowUp: return "ArrowUp";
            case Type::ArrowDown: return "ArrowDown";
            case Type::Check: return "Check";
            case Type::Expand: return "Expand";
            case Type::Collapse: return "Collapse";
            case Type::Plus: return "Plus";
            case Type::Close: return "Close";
            case Type::Maximize: return "Maximize";
            case Type::Minimize: return "Minimize";
            case Type::Restore: return "Restore";
        
        default:
            break;
        }

        return "None";
    }

    /**
     * @brief toType
     * 
     * @param Name 
     * @return Icons::Type 
     */
    Icons::Type Icons::toType(const std::string& Name) {
        for(int I = 0; I < (int)Type::Max; I++) {
            if(Name == toString((Type)I)) {
                return (Type)I;
            }
        }

        return Type::Max;
    }

    Icons::Icons()
        : m_texture(nullptr) {}
    
    Icons::~Icons() {}

    /**
     * @brief intialize
     * 
     */
    void Icons::initialize() {
        if(m_texture) {
            return;
        }

        const uint32_t width = 160;
        const uint32_t height = 32;

        const char* Data = "ICONS"; // add the ascii icons for testing
        
        std::vector<uint8_t> Buffer;
        Buffer.resize(width * height * 4);
        uint32_t index = 0;

        for(uint32_t y = 0; y < height; y++) {
            for(uint32_t x = 0; x < width; x++) {
                const uint32_t pos = x + y * width;
                const char ch = data[pos];
                color col;

                switch(ch) {
                    case 'x':
                    case '.' : col = color(255, 255, 255, 255); break;

                default:
                    break;
                }

                Buffer[index] = col.R;
                Buffer[index + 1] = col.G;
                Buffer[index + 2] = col.B;
                Buffer[index + 3] = col.A;
                index += 4;
            }
        }

        m_texture = Texture::load(Buffer, width, height);

        m_UVs[(int)Type::ArrowRight] = { 0.0f, 0.0f, 16.0f, 16.0f };
    }

    void AeroUI::Icons::initialize(const std::vector<Definition>& Definitions, const vector& iconSize) {
        const uint32_t iconW = (uint32_t)iconSize.X;
        const uint32_t iconH = (uint32_t)iconSize.Y;
        const uint32_t width = iconW;
        const uint32_t height = iconH * (uint32_t)Type::Max;
        std::vector<uint8_t> data;
        data.resize(width * height * 4);

        size_t dataOffset = 0;
        vector offset;

        for(const Definition& Item: Definitions) {
            const std::vector<uint8_t> iconData = Texture::loadSVGData(Item.fileName.c_str(), iconW, iconH);
            memcpy(&data[dataOffset], iconData.data(), iconData.size());
            dataOffset += iconData.size();

            Type iconType = toType(Item.name);
            m_UVs[(int)iconType] = { offset.X, offset.Y, offset.X + iconSize.X, offset.Y + iconSize.Y};
            offset.Y += iconSize.Y;
        }
        m_texture = Texture::load(data, width, height);
    }

    /**
     * @brief getTexture
     * 
     * @return std::shared_ptr<Texture> 
     */
    std::shared_ptr<Texture> Icons::getTexture() const {
        return m_texture;
    }

    /**
     * @brief getUVs
     * 
     * @param inType 
     * @return Rect 
     */
    Rect Icons::getUVs(Type inType) const {
        return m_UVs[(int)inType];
    }

    /**
     * @brief getUVs normalized obj
     * 
     * @param inType 
     * @return Rect 
     */
    Rect Icons::getUVsNormalized(Type inType) const {
        const Rect& UVs = m_UVs[(int)inType];
        const vector size = m_texture->getSize();
        return Rect(UVs.min / size, UVs.max / size);
    }

}
