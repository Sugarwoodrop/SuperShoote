#pragma once
#include <fstream>
#include "Const.h"
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Bullet.h"
#include "Enemies.h"
#include <memory>
#include <random>

namespace GAME {
	class Game
	{
	private:

		int Score = Const::StartScore;

		std::vector<std::shared_ptr<ENTITY::Entity>> entity;

		std::chrono::steady_clock::time_point TimeToWave;

		void AddEntityMap(MAP::Map& map);

		void AddEnemies(MAP::Map& map);

		void checkCollisions(MAP::Map& map);

		void logic(MAP::Map& map);
		void END(std::string Nickname);
		void EntityCollision();
	public:

		void run(std::string Nickname);
	};
}

