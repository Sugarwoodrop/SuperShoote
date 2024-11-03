#pragma once
#include "Entity.h"
namespace BULLET {
    class Bullet :
        public ENTITY::Entity
    {
    public:
        Bullet(int x, int y, int DirectionMoving);
        void Moving() override;
        void Dead() override;
        std::string getType() override;
        std::chrono::steady_clock::time_point LastBulletTime() override;
        void Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity) override;
        bool  Colliding(ENTITY::Entity& other) override;
    };
}

