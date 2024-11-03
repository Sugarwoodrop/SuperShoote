#pragma once
#include "iostream"
#include <vector>

namespace Const {
	// Константы кнопак
	const std::string ButtonIndent = "      ";
	const char Zero = ' ';
	const char Yes = 'Y';
	const char yes = 'y';
	const char No = 'N';
	const char no = 'n';
	const int SleepInClick = 400;
	const int SleepInStatics = 200;
	const std::string NameStatisticsFile = "Stat.top";

	// Константы Сущностей
	const int EntityHP = 1;
	const int EntityDamage = 1;
	const int DeadHP = 0;
	const char DeadSprite = ' ';

	// Константы Игрока
	const int AddHPPlayer = 5;
	const int StartingPlayerPositionX = 1;
	const int StartingPlayerPositionY = 1;
	const char SpritePlayer = '}';
	const int DelayPlayerMovingMillisecond = 250;
	const int DelayPlayerShootingSecond = 1;

	//Константы Пуль
	const char BulletSpritePlayer = '~';
	const char BulletSpriteEnemies = '-';
	const int DistanceFromTheShooter = 1;
	const int DelayBulletMovingMillisecond = 200;

	// Константы врагов
	const char SpriteEnemies = '#';
	const int DelayEnemiesMovingMillisecond = 400;
	const int DelayEnimiesProobabilityOfMoving = 30;
	const int EnemiesTheProbabilityOfMovingY = 30;
	const int EnemiesTheProbabilityOfMovingUp = 50;
	const int EnemiesTheProbabilityOfMovingLeft = 15;
	const int DelayEnemiesShootingSecond = 1;


	// Константы направления движения
	const int FromLeftToRight = 1;
	const int FromRightToLeft = 2;


	// Константы карты
	const int Hight = 9;
	const int Wight = 25;
	const char TextureUpWall = '|';
	const char TextureDownWall = '|';
	const char TextureLeftWall = ' ';
	const char TextureRightWall = ' ';
	const char TextureMap = ' ';

	// Константы Меню
	const int StartPisitionCursor = 1;
	const char TextureCursor = '<';
	const int DelayCursorMovingMillisecond = 120;
	const int CursorOutOfBeyond = 0;
	const int SleepInMenu = 5;
	const std::vector<std::string> MenuBox = {
		"--------------------",
		"+                   ",
		"+                   ",
		"+                   ",
		"+                   ",
		"+                   ",
		"--------------------",
		"      ~     -   ~ #    ",
		"}~         ~   -   -  -   -# ",
		"--------------------"
	};
	const std::string ButtonStartGame = "Start Game";
	const std::string ButtonStatistics = "Statistics";
	const std::string ButtonExit = "Exit";

	// Константы класса Game
	const int StartScore = 0;
	const int TimeToWin = 123;
	const int DTAOEFTW = 2;  //Distances the appearance of enemies from the wall(Расстояния появление врагов от стены) минумум 2
	const int TakingAwayTheScore = 1;
	const int ScoreForKillingAnEnemy = 2;
	const int MinScore = 0;
	const int TimeToEnemies = 9;
	const std::string TheDividingMarkInTheFile = " | ";
	const int SleepInTheGameCycle = 10;
	const int SleepAfterEnd = 200;
	const int SleepBeforeReturningToTheMenu = 200;

	const int ButtonOnTheKeyboardIsPressed = 0x8000;
}