#pragma once
#include "Game.h"
#include "Button.h"
#include <string> 
#include <fstream>

namespace PlayGame {
    class ButtonPlayGame :
        public BUTTON::Button
    {
    public:
        ButtonPlayGame(std::string Name);
        void onClick() const override;
    };
}

