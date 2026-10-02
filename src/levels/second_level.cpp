#include "second_level.hpp"
#include "third_level.hpp"

using dim::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return false;
}

dim::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new dim::ThirdLevel(ui_factory);
	}
	return next;
}

void SecondLevel::init_data() {
    ui_factory->create_mario({39, 10}, 3, 3);
    
    
	
    ui_factory->create_flying_enemy({85, 15}, 3, 2, 0.15f);
    ui_factory->create_flying_enemy({130, 10}, 3, 2, 0.15f);
    
	ui_factory->create_jumping_enemy({23, 23}, 3, 2, 30);
    ui_factory->create_jumping_enemy({83, 23}, 3, 2, 25);
	
    ui_factory->create_enemy({65, 18}, 3, 2);
    ui_factory->create_enemy({95, 23}, 3, 2);
    ui_factory->create_enemy({155, 23}, 3, 2);
    
    ui_factory->create_full_box({40, 15}, 5, 3);
    ui_factory->create_box({100, 10}, 5, 3);
    ui_factory->create_full_box({180, 15}, 5, 3);
	
	
	ui_factory->create_ship({20, 25}, 40, 2);
    ui_factory->create_ship({60, 20}, 10, 7);
    ui_factory->create_ship({80, 25}, 20, 2);
    ui_factory->create_ship({120, 20}, 10, 7);
    ui_factory->create_ship({150, 25}, 40, 2);
    ui_factory->create_ship({210, 20}, 10, 7);
    
	ui_factory->create_moving_platform({170, 20}, 8, 2, 0.15f, 150, 185);
	ui_factory->create_moving_platform({170, 25}, 6, 2, 0.2f, 150, 175);
	
	ui_factory->create_moving_platform({100, 25}, 10, 2, 0.2f, 100, 120);
	ui_factory->create_moving_platform({230, 10}, 8, 2, 0.15f, 180, 240);
	
	
}