/**
	- Какому паттерну проектирования соответствует UIFactory?
	- В каких случаях используется этот паттернн проектирования?
*/

#pragma once

#include "moving_platform.hpp"
#include "jumping_enemy.hpp"
#include "flying_enemy.hpp"
#include "game.hpp"
#include "game_map.hpp"
#include "mario.hpp"

namespace biv {
	class UIFactory {
		protected:
			Game* game = nullptr;
			
		protected:
			UIFactory(Game* game) : game(game) {}

		public:
			virtual void clear_data() = 0;
			virtual void create_box(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_enemy(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_full_box(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_mario(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_money(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_ship(
				const Coord& top_left, const int width, const int height) = 0;
			virtual GameMap* get_game_map(const int height, const int width) = 0;
			
			virtual Mario* get_mario() = 0;
			
			virtual FlyingEnemy* create_flying_enemy(const Coord& top_left, const int width, const int height, float hspeed) = 0;
			
			virtual JumpingEnemy* create_jumping_enemy(const Coord& top_left, const int width, const int height, int jump_interval) = 0;
			
			virtual MovingPlatform* create_moving_platform(const Coord& top_left, const int width, const int height, float hspeed, float left_bound, float right_bound) = 0;
	};
}
