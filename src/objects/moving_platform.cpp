#include "moving_platform.hpp"

using biv::MovingPlatform;

MovingPlatform::MovingPlatform(const Coord& top_left, int width, int height,
                               float hspeed, float left_bound, float right_bound)
    : Rect(top_left, width, height)
    , left_bound_(left_bound)
    , right_bound_(right_bound)
    , moving_right_(true)
    , hspeed_(hspeed)
    , vspeed_(0) {
}

void MovingPlatform::move_horizontally() {
    if (moving_right_) {
        top_left.x += hspeed_;
        if (top_left.x + width >= right_bound_) {
            moving_right_ = false;
        }
    } else {
        top_left.x -= hspeed_;
        if (top_left.x <= left_bound_) {
            moving_right_ = true;
        }
    }
}

void MovingPlatform::move_vertically() {
    // Не падаем
}

char MovingPlatform::get_brush() const noexcept {
    return '~';
}