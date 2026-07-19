#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, int width, int height, int jump_interval)
    : ConsoleEnemy(top_left, width, height)
    , jump_timer_(0)
    , jump_interval_(jump_interval)
    , is_jumping_(false)
    , start_y_(top_left.y) {
    this->hspeed = 0;
    this->vspeed = 0;
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

void JumpingEnemy::move_horizontally() noexcept {
	
}