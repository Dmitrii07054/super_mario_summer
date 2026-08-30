#pragma once

#include "console_ship.hpp"

namespace biv {
    class MovingPlatform : public ConsoleShip {
    private:
        float left_bound_;
        float right_bound_;
        bool moving_right_;

    public:
        MovingPlatform(const Coord& top_left, int width, int height,
                       float hspeed, float left_bound, float right_bound);

        void move_horizontally() noexcept override;
		void move_vertically() noexcept override;
		
		void move_map_left() noexcept override;
		void move_map_right() noexcept override;
		
    };
}
