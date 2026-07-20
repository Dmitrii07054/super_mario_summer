#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
    init_data();
}

bool ThirdLevel::is_final() const noexcept {
    return true;
}

biv::GameLevel* ThirdLevel::get_next() {
    return nullptr;
}

void ThirdLevel::init_data() {
    ui_factory->create_mario({5, 20}, 3, 3);
    
    ui_factory->create_ship({0, 25}, 20, 2);
    
    ui_factory->create_ship({30, 22}, 15, 2);
    ui_factory->create_ship({50, 19}, 12, 2);
    ui_factory->create_ship({70, 16}, 10, 2);
    ui_factory->create_ship({90, 13}, 12, 2);
    ui_factory->create_ship({110, 10}, 15, 2);
	
	ui_factory->create_moving_platform({100, 25}, 10, 2, 0.2f, 90, 130);
    
    ui_factory->create_ship({140, 25}, 20, 2);
    
    ui_factory->create_flying_enemy({35, 15}, 3, 2, 0.1f);
    ui_factory->create_flying_enemy({55, 10}, 3, 2, 0.15f);
    ui_factory->create_flying_enemy({75, 8}, 3, 2, 0.2f);
    ui_factory->create_flying_enemy({95, 6}, 3, 2, 0.12f);
    
    ui_factory->create_enemy({33, 22}, 3, 2);
    ui_factory->create_enemy({55, 19}, 3, 2);
    ui_factory->create_enemy({95, 13}, 3, 2);
    
    ui_factory->create_box({60, 10}, 5, 3);
    ui_factory->create_full_box({80, 7}, 5, 3);
    ui_factory->create_box({100, 4}, 5, 3);
}

	