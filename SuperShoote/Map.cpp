#include "Map.h"

MAP::Map::Map()
{
	Hight = Const::Hight;
	Wight = Const::Wight;
	MAP = new char* [Hight];
	for (int i = 0; i < Hight; ++i) {
		MAP[i] = new char[Wight];
	}

	for (int i = 0; i < Wight; ++i) {
		MAP[0][i] = Const::TextureUpWall;
	}
	for (int i = 0; i < Wight; ++i) {
		MAP[Hight - 1][i] = Const::TextureDownWall;
	}
	for (int i = 0; i < Hight; ++i) {
		MAP[i][0] = Const::TextureLeftWall;
	}
	for (int i = 0; i < Hight; ++i) {
		MAP[i][Wight-1] = Const::TextureRightWall;
	}
	for (int i = 1; i < Hight-1; ++i) {
		for (int j = 1; j < Wight-1; ++j) {
			MAP[i][j] = Const::TextureMap;
		}
	}
}

MAP::Map::~Map()
{
	for (int i = 0; i < Hight; ++i) {
		delete[] MAP[i];
	}

	delete[] MAP;
}

char MAP::Map::CheacPosition(int x, int y)
{
	return MAP[y][x];
}

void MAP::Map::AddEntity(char Sprite, int x, int y)
{
	MAP[y][x] = Sprite;
}

void MAP::Map::DeleteEntity(int x, int y)
{
	MAP[y][x] = Const::TextureMap;
}

int MAP::Map::HightMap()
{
	return Hight;
}

int MAP::Map::WidthMap()
{
	return Wight;
}

void MAP::Map::RenderMAP()
{
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::string buffer;
	for (int i = 0; i < Hight; ++i) {
		for (int j = 0; j < Wight; ++j) {
			buffer += MAP[i][j];
		}
		buffer += "\n";
	}
	std::cout << buffer;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
