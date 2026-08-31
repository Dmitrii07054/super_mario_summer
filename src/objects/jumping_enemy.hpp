#pragma once

#include "rect.hpp"
#include "speed.hpp"
#include "rect_map_movable_adapter.hpp"
#include "movable.hpp"
#include "collisionable.hpp"
#include "console_ui_obj_rect_adapter.hpp"

namespace biv {
    class JumpingEnemy : public RectMapMovableAdapter,
                         public Movable,
                         public Collisionable,
                         public ConsoleUIObjectRectAdapter {
    private:
        int jump_timer_;
        int jump_interval_;
        bool is_jumping_;
        float start_y_;

    public:
        JumpingEnemy(const Coord& top_left, int width, int height, int jump_interval);

        Rect get_rect() const noexcept override;
        Speed get_speed() const noexcept override;

        void move_vertically() noexcept override;
        void move_horizontally() noexcept override;

        void process_horizontal_static_collision(Rect* obj) noexcept override;
        void process_vertical_static_collision(Rect* obj) noexcept override;
        void process_mario_collision(Collisionable* mario) noexcept override;

        char get_brush() const noexcept override;
    };
}
