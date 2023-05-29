/**
 * @file AeroFont.hpp
 * @author Krisna Pranav
 * @brief Aero Font Fuctionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroVector.hpp"
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace AeroUI {
    struct Rect;
    class Texture;

    class Font {
    public:
        struct Range {
            uint32_t min { 0 };
            uint32_t max { 0 };
        };

        static Range baseLatin;
        static Range latin1Supplement;
        static Range latinExtended1;
        static Range latinExtended2;

        struct Glyph {
        public:
            Glyph();

            AeroUI::vector min {};
            AeroUI::vector max {};
            AeroUI::vector offset {};
            AeroUI::vector offset2 {};
            AeroUI::vector advance {};
        };  

        static std::shared_ptr<Font> create(const char* path, float size, const std::vector<Range>& Ranges = { baseLatin, latin1Supplement });
        static void setTabSize(int tabSize);
        static int tabSize;

        Font();
        ~Font();

        bool load(const char* path, float size, const std::vector<Range>& Ranges);

        // TODO: add some more functionalities on drawing, measuring the font thing, need to expand the font functionalities 
    };
}