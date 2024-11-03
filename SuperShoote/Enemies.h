#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <cstdlib> 
#include <ctime> 
#include <random>

namespace ENEMIES {
    class Enemies :
        public ENTITY::Entity
    {
    public:
        Enemies(int x, int y);
        void Moving() override;
        void Dead() override;
        std::string getType() override;
        void Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity) override;
        bool  Colliding(ENTITY::Entity& other) override;
    };
}

