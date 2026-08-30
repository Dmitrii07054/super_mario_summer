#include "flying_enemy.hpp"
#include "mario.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, int width, int height, float hspeed)
    : ConsoleEnemy(top_left, width, height) {
    this->hspeed = hspeed;
    this->vspeed = 0;
}

void FlyingEnemy::move_vertically() noexcept {

}

void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
    Mario* mario_ptr = static_cast<Mario*>(mario);
    
    if (mario_ptr->get_vspeed() > 0 && 
        mario_ptr->get_bottom() >= this->get_top() && 
        mario_ptr->get_bottom() <= this->get_top() + 10) {
        kill();
    } else {
        mario_ptr->kill();
    }
}