#include "flying_enemy.hpp"
#include "mario.hpp"
#include "map_movable.hpp"

using namespace biv;
using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, int width, int height, float hspeed)
    : RectMapMovableAdapter(top_left, width, height) {
    this->hspeed = hspeed;
    this->vspeed = 0;
}

Rect FlyingEnemy::get_rect() const noexcept {
    return {top_left, width, height};
}

Speed FlyingEnemy::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void FlyingEnemy::move_horizontally() noexcept {
    top_left.x += hspeed;
}

void FlyingEnemy::move_vertically() noexcept {
    if (!is_active()) {
        Movable::move_vertically();
    }
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
    hspeed = -hspeed;
    move_horizontally();
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
    vspeed = 0;
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

char FlyingEnemy::get_brush() const noexcept {
    return 'F';
}
