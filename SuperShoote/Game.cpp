#include "Game.h"
void GAME::Game::AddEntityMap(MAP::Map& map)
{
	for (auto& obj : entity) {
		map.AddEntity(obj->ReturnSprite(), obj->Xposition(), obj->Yposition());
	}
}

void GAME::Game::AddEnemies(MAP::Map& map)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, map.HightMap()-1);
	int FirstPosition= dist(gen);
	int SecondPosition= dist(gen);
	int ThirdPosition= dist(gen);
	while (SecondPosition == FirstPosition) {
		SecondPosition = dist(gen);
	}
	while (ThirdPosition == FirstPosition || ThirdPosition == SecondPosition) {
		ThirdPosition = dist(gen);
	}

	entity.push_back(std::make_shared<ENEMIES::Enemies>(map.WidthMap() - Const::DTAOEFTW, FirstPosition));

	entity.push_back(std::make_shared<ENEMIES::Enemies>(map.WidthMap() - Const::DTAOEFTW, SecondPosition));

	entity.push_back(std::make_shared<ENEMIES::Enemies>(map.WidthMap() - Const::DTAOEFTW, ThirdPosition));

}

void GAME::Game::checkCollisions(MAP::Map& map)
{
	for (auto& obj : entity) {
		if (obj->Yposition() == 0) {
			obj->AddY();
		}
		if (obj->Yposition() == (map.HightMap()-1)) {
			obj->minusY();
		}
		if (obj->Xposition() == 0) {
			obj->WentBeyond();
		}
		if (obj->Xposition() == (map.WidthMap() - 1)) {
			obj->WentBeyond();
		}
	}
}

void GAME::Game::logic(MAP::Map& map)
{
	for (auto& obj : entity) {
		obj->Moving();
	}
	checkCollisions(map);

	for (auto it = entity.begin(); it != entity.end();) {
		if ((*it)->OutOfBeyond()) {
			if ((*it)->getType() == "Enemies") {
				Score -= Const::TakingAwayTheScore;
				if (Score < Const::MinScore) {
					Score = Const::MinScore;
				}
			}
			it = entity.erase(it);
		}
		else {
			it++;
		}
	}

	auto now = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - TimeToWave).count();
	std::cout << "Время до новой волны " << Const::TimeToEnemies - elapsed << std::endl;

	if (elapsed >= Const::TimeToEnemies) {
		AddEnemies(map);
		TimeToWave = std::chrono::steady_clock::now();
	}
	AddEntityMap(map);

	EntityCollision();
	for (int i = 0; i < entity.size(); i++) {
		entity[i]->Shooting(entity);
	}
}

void GAME::Game::END(std::string Nickname)
{
	system("cls");

	std::ofstream FILE(Const::NameStatisticsFile, std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
	if (!FILE) {
		FILE.open(Const::NameStatisticsFile, std::ios::binary | std::ios::out);
	}
	FILE << Nickname;
	FILE << Const::TheDividingMarkInTheFile;

	FILE << Score;
	FILE << Const::TheDividingMarkInTheFile;

	if (entity[0]->viewHP() > 0) {
		std::cout << "=============" << std::endl;
		std::cout << "=============" << std::endl;
		std::cout << std::endl;
		std::cout << " YOU WINNING" << std::endl;
		std::cout << std::endl;
		std::cout << "=============" << std::endl;
		std::cout << "=============" << std::endl;
		FILE << "Win";
		FILE << "\n";
	}
	else {
		std::cout << "===========" << std::endl;
		std::cout << " ПОТРАЧЕНО" << std::endl;
		std::cout << "===========" << std::endl;
		FILE << "Loss";
		FILE << "\n";
	}
	FILE.close();
}

void GAME::Game::EntityCollision()
{

	for (int i = 0; i < entity.size(); i++) {
		for (int j = 1; j < entity.size(); j++) {
			auto now = std::chrono::steady_clock::now();
			auto Damage1 = std::chrono::duration_cast<std::chrono::seconds>(now - entity[i]->LastDamageTime()).count();
			auto Damage2 = std::chrono::duration_cast<std::chrono::seconds>(now - entity[j]->LastDamageTime()).count();
			if (entity[i]->Colliding(*entity[j]) && Damage1 >= 1) {
				entity[i]->DamageReceived(entity[j]->damage());
				entity[i]->NewLastDamageTime(now);
			}
			if (entity[i]->Colliding(*entity[j]) && Damage2 >= 1) {
				entity[j]->DamageReceived(entity[i]->damage());
				entity[j]->NewLastDamageTime(now);
			}
		}
	}

	for (auto it = entity.begin(); it != entity.end();) {
		if ((*it)->ReturnSprite() == Const::TextureMap) {
			if ((*it)->getType() == "Enemies") {
				Score += Const::ScoreForKillingAnEnemy;
			}
			it = entity.erase(it);
		}
		else {
			it++;
		}
	}
}

void GAME::Game::run(std::string Nickname)
{
	TimeToWave = std::chrono::steady_clock::now();

	std::shared_ptr<PLAYER::Player> Player(new PLAYER::Player);
	entity.push_back(Player);

	auto lastMoveTime = std::chrono::steady_clock::now();
	auto ENDTIME = std::chrono::steady_clock::now();

	while (!Player->DEAD()) {
		MAP::Map map;

		logic(map);
;		map.RenderMAP();
		auto ite = entity.begin();
		std::cout << "HP" << (*ite)->viewHP() << std::endl;
		std::cout << "Score " << Score << std::endl;
		auto now = std::chrono::steady_clock::now();
		auto End = std::chrono::duration_cast<std::chrono::seconds>(now - ENDTIME).count();
		if (End >= Const::TimeToWin) {
			break;
		}
		Sleep(Const::SleepInTheGameCycle);
	}
	END(Nickname);
	Sleep(Const::SleepAfterEnd);
	system("pause");
	system("cls");
	Sleep(Const::SleepBeforeReturningToTheMenu);
}
