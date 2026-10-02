#include "moving_platform.hpp"
#include "movable.hpp"

using dim::MovingPlatform;

MovingPlatform::MovingPlatform(const Coord& top_left, int width, int height,
                               float hspeed, float left_bound, float right_bound)
    : ConsoleShip(top_left, width, height)
    , left_bound_(left_bound)
    , right_bound_(right_bound)
    , moving_right_(true) {
    this->hspeed = hspeed;
    this->vspeed = 0;
}

void MovingPlatform::move_horizontally() noexcept {
    if (moving_right_) {
        top_left.x += this->hspeed;
        if (top_left.x + width >= right_bound_) {
            moving_right_ = false;
        }
    } else {
        top_left.x -= this->hspeed;
        if (top_left.x <= left_bound_) {
            moving_right_ = true;
        }
    }
}

void MovingPlatform::move_vertically() noexcept {
	
}

void MovingPlatform::move_map_left() noexcept {
	top_left.x -= 1.0f;
	left_bound_ -= 1.0f;
	right_bound_ -= 1.0f;
}

void MovingPlatform::move_map_right() noexcept {
	top_left.x += 1.0f;
	left_bound_ += 1.0f;
	right_bound_ += 1.0f;
}
