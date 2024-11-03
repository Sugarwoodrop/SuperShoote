#pragma once
#include <iostream>
#include "Const.h"
#include <windows.h>
namespace MAP {
	class Map
	{
	private:
		int Hight;
		int Wight;
		char** MAP;
	public:
		Map();
		~Map();

		char CheacPosition(int x, int y);

		void AddEntity(char Sprite, int x, int y);
		void DeleteEntity(int x, int y);

		int HightMap();
		int WidthMap();
		void RenderMAP();
	};
}
