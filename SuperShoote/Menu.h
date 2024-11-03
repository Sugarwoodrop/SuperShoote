#pragma once
#include "Button.h"
#include "Const.h"
#include "ButtonStatistics.h"
#include"ButtonExit.h"
#include "ButtonPlayGame.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include <chrono>


namespace MANU {
	class Menu
	{
	private:
		std::vector<std::shared_ptr<BUTTON::Button>> Buttons;
		int cursor;
		std::chrono::steady_clock::time_point LastMoveCursor;

		void render(std::vector<std::string> menu);
		void Сursor();
	public:
		Menu();
		void run();
	};
}

