#include "ButtonPlayGame.h"

PlayGame::ButtonPlayGame::ButtonPlayGame(std::string Name)
{

	setName(Name);
}
void PlayGame::ButtonPlayGame::onClick() const
{
	Sleep(Const::SleepInClick);
	char YesOrNot = Const::Zero;
	std::string Nickname;
	while (YesOrNot != Const::Yes && YesOrNot != Const::yes) {
		system("cls");
		YesOrNot = Const::Zero;
		std::cout << "Введите Никнейм" << std::endl;
		std::cin >> Nickname;
		std::cout << "Оставить этот ник? y/n" << std::endl;
		while (YesOrNot != Const::Yes && YesOrNot != Const::yes && YesOrNot != Const::No && YesOrNot != Const::no) {
			std::cin >> YesOrNot;
		}
	}

	system("cls");
	GAME::Game game;
	game.run(Nickname);
};
