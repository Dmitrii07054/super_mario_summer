#pragma once

#include "rect.hpp"
#include "speed.hpp"
#include "rect_map_movable_adapter.hpp"
#include "movable.hpp"
#include "collisionable.hpp"
#include "console_ui_obj_rect_adapter.hpp"

namespace biv {
    class FlyingEnemy : public RectMapMovableAdapter,
                        public Movable,
                        public Collisionable,
                        public ConsoleUIObjectRectAdapter {
    public:
        FlyingEnemy(const Coord& top_left, int width, int height, float hspeed);

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
