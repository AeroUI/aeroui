/**
 * @file AeroPopup.hpp
 * @author Krisna Pranav
 * @brief Popup Functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroCallbacks.hpp"
#include "AeroMouse.hpp"
#include <cstdint>
#include <functional>
#include <memory>

namespace AeroUI {
    class Container;
    class Control;
    class Paint;
    struct Vector2;

    class Popup {
    public:
        enum class State: uint8_t {
            None,
            Opening,
            Opened
        };

        Popup();
        ~Popup();

        void open(const std::shared_ptr<Container>& inContainer, bool Modal);
        void close();
        void update();
        bool isModal() const;
        const std::shared_ptr<Container>& getContainer() const;
        bool hasControl(const std::shared_ptr<Control>& item) const;
        void onMousEMove(const Vector2& position);
        std::weak_ptr<Control> getControl(const Vector2& position) const;
        void onPaint(Paint& Brush);
        void setOnInvalidate(onInvalidateSignature Fn);
        void setOnClose(onContainerSignature Fn);

    private:
        std::shared_ptr<Container> m_container;
        bool m_Modal;
        State m_State;
        onInvalidateSignature m_onInvalidate;
        onContainerSignature m_onClose;
    };
}