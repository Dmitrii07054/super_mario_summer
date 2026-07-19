#pragma once

#include "console_enemy.hpp"

namespace biv {
	class JumpingEnemy: public ConsoleEnemy {
	private:
		int jump_timer_;
		int jump_interval_;
		bool is_jumping_;
		float start_y_;
			
	public:
		JumpingEnemy(const Coord& top_left, int width, int height, int jump_interval);
			
		void move_vertically() noexcept override;
		void move_horizontally() noexcept override;
	};
}
