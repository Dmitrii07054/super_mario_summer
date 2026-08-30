#pragma once

#include "rect.hpp"
#include "console_ui_obj_rect_adapter.hpp"

namespace biv {
    class MovingPlatform : public Rect, public ConsoleUIObjectRectAdapter {
    private:
        float left_bound_;
        float right_bound_;
        bool moving_right_;
        float hspeed_;
        float vspeed_;

    public:
        MovingPlatform(const Coord& top_left, int width, int height,
                       float hspeed, float left_bound, float right_bound);

        void move_horizontally();
        void move_vertically();

        char get_brush() const noexcept override;
    };
}