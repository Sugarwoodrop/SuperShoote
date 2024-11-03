#pragma once
#include <iostream>
#include <windows.h>
#include <chrono>
#include <random>
#include "Const.h"

namespace ENTITY {
	class Entity
	{
	private:
		char Sprite;
		int HP = Const::EntityHP;
		int Damage = Const::EntityDamage;
		bool wentBeyond = false;

		std::chrono::steady_clock::time_point lastMoveTime;
		std::chrono::steady_clock::time_point lastBulletTime;
		std::chrono::steady_clock::time_point lastdamageReceived;
		int directionBullet;
		int x, y;
	public:
		Entity();
		virtual ~Entity() = default;

		void ChangeX(int x);
		void ChangeY(int y);
		void ChangeHP();
		void ChangeDamage();
		void initSprite(char Sprite);

		int damage();

		void WentBeyond();

		bool OutOfBeyond();

		int viewHP();

		void AddY();
		void AddX();
		void minusY();
		void minusX();


		int Xposition();
		int Yposition();

		char ReturnSprite();

		void DamageReceived(int Damage);

		void virtual Moving() = 0;




		std::chrono::steady_clock::time_point LastMoveTime();

		void NewLastMoveTime(std::chrono::steady_clock::time_point NewTime);

		std::chrono::steady_clock::time_point virtual LastBulletTime();

		void NewLastBulletTime(std::chrono::steady_clock::time_point NewTime);

		std::chrono::steady_clock::time_point virtual LastDamageTime();

		void NewLastDamageTime(std::chrono::steady_clock::time_point NewTime);



		std::string virtual getType() = 0;

		void virtual Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity) = 0;

		void DirectionBullet(int DirectionBullet);

		int returnDirectionBullet();

		bool virtual Colliding( Entity& other) = 0;

		void virtual Dead() = 0;
	};
}

