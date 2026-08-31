#include "jumping_enemy.hpp"
#include "mario.hpp"
#include "map_movable.hpp"

using namespace biv;
using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, int width, int height, int jump_interval)
    : RectMapMovableAdapter(top_left, width, height)
    , jump_timer_(0)
    , jump_interval_(jump_interval)
    , is_jumping_(false)
    , start_y_(top_left.y) {
    this->hspeed = 0;
    this->vspeed = 0;
}

Rect JumpingEnemy::get_rect() const noexcept {
    return {top_left, width, height};
}

Speed JumpingEnemy::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void JumpingEnemy::move_horizontally() noexcept {

}

void JumpingEnemy::move_vertically() noexcept {
    if (!is_jumping_) {
        jump_timer_++;
        if (jump_timer_ >= jump_interval_) {
            is_jumping_ = true;
            jump_timer_ = 0;
            vspeed = -1.2f;
        }
    } else {
        vspeed += 0.05f;
        if (vspeed > 0.98f) vspeed = 0.98f;
        top_left.y += vspeed;
        if (top_left.y >= start_y_) {
            top_left.y = start_y_;
            is_jumping_ = false;
            vspeed = 0;
        }
    }
}

void JumpingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {

}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
    if (vspeed > 0) {
        top_left.y -= vspeed;
        vspeed = 0;
        is_jumping_ = false;
    }
}

void JumpingEnemy::process_mario_collision(Collisionable* mario) noexcept {
    Mario* mario_ptr = static_cast<Mario*>(mario);

    if (mario_ptr->get_vspeed() > 0 &&
        mario_ptr->get_bottom() >= this->get_top() &&
        mario_ptr->get_bottom() <= this->get_top() + 10 &&
        mario_ptr->get_x() + 2 >= this->get_left() && 
        mario_ptr->get_x() + 2 <= this->get_right()) {
        kill();
    } else {
        mario_ptr->kill();
    }
}

char JumpingEnemy::get_brush() const noexcept {
    return 'J';
}
