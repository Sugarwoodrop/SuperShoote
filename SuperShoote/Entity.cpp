#include "Entity.h"

ENTITY::Entity::Entity() :lastMoveTime(std::chrono::steady_clock::now()), lastBulletTime(std::chrono::steady_clock::now()), lastdamageReceived(std::chrono::steady_clock::now())
{
}

void ENTITY::Entity::ChangeX(int x)
{
	this->x = x;
}

void ENTITY::Entity::ChangeY(int y)
{
	this->y = y;
}

int ENTITY::Entity::Xposition()
{
	return x;
}

int ENTITY::Entity::Yposition()
{
	return y;
}

char ENTITY::Entity::ReturnSprite()
{
	return Sprite;
}

void ENTITY::Entity::ChangeHP()
{
	HP++;
}

void ENTITY::Entity::ChangeDamage()
{
	Damage++;
}

void ENTITY::Entity::initSprite(char Sprite)
{
	this->Sprite = Sprite;
}


int ENTITY::Entity::damage()
{
	return Damage;
}

void ENTITY::Entity::WentBeyond()
{
	wentBeyond = true;
}

bool ENTITY::Entity::OutOfBeyond()
{
	return wentBeyond;
}

int ENTITY::Entity::viewHP()
{
	return HP;
}

void ENTITY::Entity::AddY()
{
	y++;
}

void ENTITY::Entity::AddX()
{
	x++;
}

void ENTITY::Entity::minusY()
{
	y--;
}

void ENTITY::Entity::minusX()
{
	x--;
}

void ENTITY::Entity::DamageReceived(int Damage)
{
	HP -= Damage;
	if (HP <= Const::DeadHP) {
		Dead();
	}
}

std::chrono::steady_clock::time_point ENTITY::Entity::LastMoveTime()
{
	return lastMoveTime;
}
void ENTITY::Entity::NewLastMoveTime(std::chrono::steady_clock::time_point NewTime)
{
	lastMoveTime = NewTime;
}

std::chrono::steady_clock::time_point ENTITY::Entity::LastBulletTime()
{
	return lastBulletTime;
}

void ENTITY::Entity::NewLastBulletTime(std::chrono::steady_clock::time_point NewTime)
{
	lastBulletTime = NewTime;
}

std::chrono::steady_clock::time_point ENTITY::Entity::LastDamageTime()
{
	return lastdamageReceived;
}

void ENTITY::Entity::NewLastDamageTime(std::chrono::steady_clock::time_point NewTime)
{
	lastdamageReceived = NewTime;
}

void ENTITY::Entity::DirectionBullet(int DirectionBullet)
{
	directionBullet = DirectionBullet;
}

int ENTITY::Entity::returnDirectionBullet()
{
	return directionBullet;
}


