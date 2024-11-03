#include "Bullet.h"

BULLET::Bullet::Bullet(int x, int y, int DirectionMoving)
{
	DirectionBullet(DirectionMoving);
	if (returnDirectionBullet() == Const::FromLeftToRight) {
		ChangeX(x+Const::DistanceFromTheShooter);
		initSprite(Const::BulletSpritePlayer);
	}
	if (returnDirectionBullet() == Const::FromRightToLeft) {
		ChangeX(x - Const::DistanceFromTheShooter);
		initSprite(Const::BulletSpriteEnemies);
	}
	ChangeY(y);
}

void BULLET::Bullet::Moving()
{
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - LastMoveTime()).count();
	if (elapsed >= Const::DelayBulletMovingMillisecond) {
		if (returnDirectionBullet() == Const::FromLeftToRight) {
			AddX();
			NewLastMoveTime(currentTime);
			return;
		}
		if (returnDirectionBullet() == Const::FromRightToLeft) {
			minusX();
			NewLastMoveTime(currentTime);
			return;
		}
	}
}

void BULLET::Bullet::Dead()
{
	initSprite(Const::DeadSprite);
}

std::string BULLET::Bullet::getType()
{
	return "Bullet";
}

std::chrono::steady_clock::time_point BULLET::Bullet::LastBulletTime()
{
	return std::chrono::steady_clock::now();
}

void BULLET::Bullet::Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity)
{
	return;
}

bool BULLET::Bullet::Colliding(ENTITY::Entity& other)
{
	return (Xposition() == other.Xposition() && Yposition() == other.Yposition() && returnDirectionBullet() != other.returnDirectionBullet() && damage() != other.damage());
}