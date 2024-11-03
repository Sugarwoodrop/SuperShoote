#include "ButtonStatistics.h"

Statistics::ButtonStatistics::ButtonStatistics(std::string Name)
{
	this->FileName = FileName = Const::NameStatisticsFile;
	setName(Name);
}

void Statistics::ButtonStatistics::onClick() const
{
	system("cls");
	std::ifstream FILE(FileName, std::ios::binary);
	if (!FILE) {
		std::cout << "Нету записей" << std::endl;
	}
	else {
		std::cout << "Nickname   Score   W/L" << std::endl;
		while (!FILE.eof()) {
			std::string line;
			std::getline(FILE, line);
			std::cout << line << std::endl;
		}
	}
	system("pause");
	system("cls");
	Sleep(Const::SleepInStatics);
}
