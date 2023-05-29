/**
 * @file AeroCallbacks.hpp
 * @author your name (you@domain.com)
 * @brief Callbacks functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include <functional>
#include <memory>

namespace AeroUI {
    class Button;
    class Container;
    class Control;
    class MenuItem;
    class ScrollBar;
    class TextSelectable;
    class Tree;

    enum class InvalidType: unsigned char {
        Layout,
        Paint,
        Both
    };
    
    typedef std::function<void()> onEmptySignature;
    typedef std::function<void(const Container&)> onContainerSignature;
    typedef std::function<void(const Control&)> onControlSignature;
    typedef std::function<void(std::shared_ptr<Control>, InvalidType)> onInvalidateSignature;
    typedef std::function<void(const ScrollBar&)> onScrollBarSignature;
    typedef std::function<void(TextSelectable&)> onTextSelectableSignature;
    typedef std::function<void(Tree&)> onTreeSignature;

}