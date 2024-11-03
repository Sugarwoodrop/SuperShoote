#pragma once

#include <fstream>
#include "Button.h"
#include <string> 
#include <windows.h>

namespace Statistics {
    class ButtonStatistics :
        public BUTTON::Button
    {
        private:
            std::string FileName;
    public:
        ButtonStatistics(std::string Name);
        void onClick() const override;
    };
}

