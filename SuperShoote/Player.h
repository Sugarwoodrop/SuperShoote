#pragma once
#include "Entity.h"
#include "Bullet.h"

namespace PLAYER {
    class Player :
        public ENTITY::Entity
    {
    private:
        bool dead;
    public:
        Player();
        void Moving() override;
        void Dead() override;
        std::string getType() override;
        void Shooting(std::vector<std::shared_ptr<ENTITY::Entity>>& entity) override;
        bool DEAD();
        bool CheackDead();
        bool  Colliding( ENTITY::Entity& other) override;
    };
}

