/**
 * @file AeroMessageBox.hpp
 * @author Krisna Pranav
 * @brief Message Box
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#include <functional>

namespace AeroUI {
    class Application;

    namespace MessageBox {
        namespace Buttons {
            enum Type {
                None = 0,
                Ok = 1 << 0,
                Yes = 1 << 1,
                No = 1 << 2,
                Cancel = 1 << 3,

                OKCancel = Ok | Cancel,
                YesNo = Yes | No,
                YesNoCancel = Yes | No | Cancel
            };
        }

        enum class Response {
            Accept,
            Reject,
            Cancel,
        };

        typedef std::function<void(Response)> onResponseSignature;

        void show(Application& App, const char32_t* Title, const char32_t* Message, onResponseSignature&& fn, Buttons::Type ButtonTypes = Buttons::Type::OKCancel);
    }
}