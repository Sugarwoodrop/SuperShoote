#include "Player.h"

PLAYER::Player::Player()
{
	for (int i = 0; i < Const::AddHPPlayer; i++) {
		ChangeHP();
	}
	ChangeDamage();
	initSprite(Const::SpritePlayer);
	ChangeX(Const::StartingPlayerPositionX);
	ChangeY(Const::StartingPlayerPositionY);
	DirectionBullet(Const::FromLeftToRight);
	dead = false;
}

void PLAYER::Player::Moving()
{
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - LastMoveTime()).count();

	if (elapsed >= Const::DelayPlayerMovingMillisecond) {
		if (GetKeyState(VK_UP) & Const::ButtonOnTheKeyboardIsPressed) {
			minusY();
			NewLastMoveTime(currentTime);
			return;
		}
		if (GetKeyState(VK_DOWN) & Const::ButtonOnTheKeyboardIsPressed) {
			AddY();
			NewLastMoveTime(currentTime);
			return;
		}

	}
}

void PLAYER::Player::Dead()
{
	dead = true;
	return;
}

std::string PLAYER::Player::getType()
{
	return "Player";
}

void PLAYER::Player::Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity)
{
	if (GetKeyState(VK_SPACE) & Const::ButtonOnTheKeyboardIsPressed) {
		auto now = std::chrono::steady_clock::now();
		auto Bullet = std::chrono::duration_cast<std::chrono::seconds>(now - LastBulletTime()).count();
		if (Bullet >= Const::DelayPlayerShootingSecond) {
			entity.push_back(std::make_shared<BULLET::Bullet>(Xposition(), Yposition(), returnDirectionBullet()));
			NewLastBulletTime(now);
		}
	}
}

bool PLAYER::Player::DEAD()
{
	return dead;
}

bool PLAYER::Player::CheackDead()
{
	return dead;
}

bool PLAYER::Player::Colliding( ENTITY::Entity& other)
{
	return (Xposition() == other.Xposition() && Yposition() == other.Yposition());
}
