#pragma once

#include "console_enemy.hpp"

namespace biv {
    class FlyingEnemy : public ConsoleEnemy {
    public:
        FlyingEnemy(const Coord& top_left, int width, int height, float hspeed);
        void move_vertically() noexcept override;
    };
}