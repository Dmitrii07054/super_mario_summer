#pragma once

#include "console_box.hpp"
#include "console_enemy.hpp"
#include "console_full_box.hpp"
#include "console_game_map.hpp"
#include "console_mario.hpp"
#include "console_money.hpp"
#include "console_ship.hpp"
#include "ui_factory.hpp"
#include "flying_enemy.hpp"
#include "jumping_enemy.hpp"
#include "moving_platform.hpp"

namespace dim {
	class ConsoleUIFactory : public UIFactory {
		private:
			ConsoleGameMap* game_map = nullptr;
			std::vector<ConsoleBox*> boxes;
			std::vector<ConsoleFullBox*> full_boxes;
			std::vector<ConsoleShip*> ships;
			ConsoleMario* mario = nullptr;
			std::vector<ConsoleEnemy*> enemies;
			std::vector<ConsoleMoney*> moneys;
			std::vector<FlyingEnemy*> flying_enemies_;
			std::vector<JumpingEnemy*> jumping_enemies_;
			std::vector<MovingPlatform*> moving_platforms_;

		public:
			ConsoleUIFactory(Game* game);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			
			GameMap* get_game_map(const int height, const int width) override;
			Mario* get_mario() override;
			FlyingEnemy* create_flying_enemy(const Coord& top_left, int width, int height, float hspeed) override;
			JumpingEnemy* create_jumping_enemy(const Coord& top_left, int width, int height, int jump_interval) override;
			MovingPlatform* create_moving_platform(const Coord& pos, int w, int h, float hspeed, float left_bound, float right_bound) override;
			
	};
}
