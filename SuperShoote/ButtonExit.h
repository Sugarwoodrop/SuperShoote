#pragma once
#include "Button.h"
namespace Exit {
    class ButtonExit :
        public BUTTON::Button
    {
    public:
        ButtonExit(std::string Name);
        void onClick() const override;
    };
}

