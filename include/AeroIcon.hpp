/**
 * @file icons.hpp
 * @author Krisna Pranav
 * @brief 
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_ICONS_HPP__
#define __INCLUDE_ICONS_HPP__

#include "AeroRect.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace AeroUI {

class Texture;

class Icons {
public:
    /**
     * @brief Types
     * 
     */
    enum class Type : uint8_t {
        ArrowLeft,
        ArrowRight,
        ArrowUp,
        ArrowDown,
        Check,
        Expand,
        Collapse,
        Plus,
        Minus,
        Close,
        Minimize,
        Maximize,
        Restore,
        Max
    };

    /**
     * @brief Definition[name, fileName]
     * 
     */
    struct Definition {
    public:
        std::string name {};
        std::string fileName {};
    };

    /**
     * @brief toString
     * 
     * @param inType 
     * @return const char* 
     */
    static const char* toString(Type inType);

    /**
     * @brief toType obj
     * 
     * @param name 
     * @return Type 
     */
    static Type toType(const std::string& name);

    Icons();
    ~Icons();

    /**
     * @brief initialize
     * 
     */
    void initialize();
    void initialize(const std::vector<Definition>& Definitions, const vector& iconSize);

    /**
     * @brief Get the Texture object
     * 
     * @return std::shared_ptr<Texture> 
     */
    std::shared_ptr<Texture> getTexture() const;

    /**
     * @brief getUVs
     * 
     * @param inType 
     * @return Rect 
     */
    Rect getUVs(Type inType) const;

    /**
     * @brief UVs normalized
     * 
     * @param inType 
     * @return Rect 
     */
    Rect getUVsNormalized(Type inType) const;

private:
    std::shared_ptr<Texture> m_texture;
    Rect m_UVs[(uint32_t)Type::Max];
    
};

}

#endif