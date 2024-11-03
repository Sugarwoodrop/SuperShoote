#include "Enemies.h"

ENEMIES::Enemies::Enemies(int x, int y)
{
	ChangeDamage();
	NewLastBulletTime(std::chrono::steady_clock::time_point());
	initSprite(Const::SpriteEnemies);
	ChangeX(x);
	ChangeY(y);
	DirectionBullet(Const::FromRightToLeft);
}

void ENEMIES::Enemies::Moving()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 100);
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - LastMoveTime()).count();
	if (elapsed >= Const::DelayEnemiesMovingMillisecond) {  // Вынести в константы
		if (dist(gen) >= Const::DelayEnimiesProobabilityOfMoving){
			if (dist(gen) <= Const::EnemiesTheProbabilityOfMovingY) {
				if (dist(gen) >= Const::EnemiesTheProbabilityOfMovingUp) {
					minusY();
					NewLastMoveTime(currentTime);
					return;
				}
				else {
					AddY();
					NewLastMoveTime(currentTime);
					return;
				}
			}
			else {
				if (dist(gen) >= Const::EnemiesTheProbabilityOfMovingLeft) {
					minusX();
					NewLastMoveTime(currentTime);
					return;
				}
			}
		}
	}
}

void ENEMIES::Enemies::Dead()
{
	initSprite(Const::DeadSprite);
}

std::string ENEMIES::Enemies::getType()
{
	return "Enemies";
}

void ENEMIES::Enemies::Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity)
{
	auto now = std::chrono::steady_clock::now();
	auto Bullet = std::chrono::duration_cast<std::chrono::seconds>(now - LastBulletTime()).count();
	if (Bullet >= Const::DelayEnemiesShootingSecond) {
		entity.push_back(std::make_shared<BULLET::Bullet>(Xposition(), Yposition(), returnDirectionBullet()));
		NewLastBulletTime(now);
	}
}

bool ENEMIES::Enemies::Colliding(ENTITY::Entity& other)
{
	return (Xposition() == other.Xposition() && Yposition() == other.Yposition() && returnDirectionBullet() != other.returnDirectionBullet());
}
