#pragma once

#include "rect_map_movable_adapter.hpp"
#include "movable.hpp"

namespace dim {
	class Ship : public RectMapMovableAdapter, virtual public Movable {
		public:
			Ship(
				const Coord& top_left, const int width, const int height
			) : RectMapMovableAdapter(top_left, width, height) {}
	};
}
