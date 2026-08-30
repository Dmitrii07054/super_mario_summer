#include "flying_enemy.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, int width, int height, float hspeed)
    : ConsoleEnemy(top_left, width, height) {
    this->hspeed = hspeed;
    this->vspeed = 0;
}

void FlyingEnemy::move_vertically() noexcept {
	
}