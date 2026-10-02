#pragma once

namespace dim {
	class OSControlSettings {
		public:
			virtual void init() = 0;
			virtual void set_cursor_start_position() = 0;
	};
}
