#include "Menu.h"
MANU::Menu::Menu()
{
	cursor = Const::StartPisitionCursor;
	LastMoveCursor = std::chrono::steady_clock::now();
}
void MANU::Menu::run()
{
	Buttons.push_back(std::make_shared <PlayGame::ButtonPlayGame>(Const::ButtonStartGame));
	Buttons.push_back(std::make_shared <Statistics::ButtonStatistics>(Const::ButtonStatistics));
	Buttons.push_back(std::make_shared <Exit::ButtonExit>(Const::ButtonExit));
	while (true) {
		std::vector<std::string> menu = Const::MenuBox;
		render(menu);
		menu[1] = Buttons[0]->getName();
		menu[2] = Buttons[1]->getName();
		menu[3] = Buttons[2]->getName();
		menu[cursor] += Const::TextureCursor;
		if (GetKeyState(VK_RETURN) & Const::ButtonOnTheKeyboardIsPressed) {
			Buttons[cursor-1]->onClick();
		}
		Сursor();
		render(menu);
		Sleep(Const::SleepInMenu);
	}
}

void MANU::Menu::render(std::vector<std::string> menu)
{
	std::string buffer;
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 0; i < menu.size(); i++) {
		buffer += menu[i];
		buffer += "\n";
	}
	std::cout<<buffer<<std::endl;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void MANU::Menu::Сursor()
{
	auto now = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - LastMoveCursor).count();

	if (elapsed >= Const::DelayCursorMovingMillisecond) {
		if (GetKeyState(VK_UP) & Const::ButtonOnTheKeyboardIsPressed) {
			cursor--;
		}
		if (GetKeyState(VK_DOWN) & Const::ButtonOnTheKeyboardIsPressed) {
			cursor++;
		}
		if (cursor > Buttons.size()) {
			cursor = Buttons.size();
		}
		if (cursor < Const::StartPisitionCursor) {
			cursor = Const::StartPisitionCursor;
		}
		LastMoveCursor = now;
	}
}
