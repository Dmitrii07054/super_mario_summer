#pragma once

#include "os_control_settings.hpp"

namespace dim {
	class WindowsControlSettings : public OSControlSettings {
		public:
			void init() override;
			void set_cursor_start_position() override;
	};
}
