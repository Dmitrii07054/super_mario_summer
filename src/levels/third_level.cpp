#include "third_level.hpp"

using dim::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
    init_data();
}

bool ThirdLevel::is_final() const noexcept {
    return true;
}

dim::GameLevel* ThirdLevel::get_next() {
    return nullptr;
}

void ThirdLevel::init_data() {
    ui_factory->create_mario({39, 10}, 3, 3);
    
    ui_factory->create_ship({20, 25}, 40, 2);
    ui_factory->create_ship({60, 20}, 10, 7);
    ui_factory->create_ship({80, 25}, 20, 2);
    ui_factory->create_ship({120, 20}, 10, 7);
    ui_factory->create_ship({150, 25}, 40, 2);
    ui_factory->create_ship({210, 20}, 10, 7);
    
    ui_factory->create_moving_platform({170, 20}, 8, 2, 0.15f, 160, 200);
    ui_factory->create_moving_platform({170, 25}, 6, 2, 0.2f, 180, 220);
    
    
    ui_factory->create_flying_enemy({45, 12}, 3, 2, 0.1f);
    ui_factory->create_flying_enemy({85, 15}, 3, 2, 0.15f);
    ui_factory->create_flying_enemy({130, 10}, 3, 2, 0.12f);
    ui_factory->create_flying_enemy({190, 10}, 3, 2, 0.15f);
    ui_factory->create_flying_enemy({250, 8}, 3, 2, 0.2f);
    
    ui_factory->create_jumping_enemy({23, 23}, 3, 2, 30);
    ui_factory->create_jumping_enemy({83, 23}, 3, 2, 25);
    ui_factory->create_jumping_enemy({153, 23}, 3, 2, 20);
    ui_factory->create_jumping_enemy({185, 23}, 3, 2, 15); 
    
    ui_factory->create_enemy({65, 18}, 3, 2);
    ui_factory->create_enemy({95, 23}, 3, 2);
    ui_factory->create_enemy({155, 23}, 3, 2);
    ui_factory->create_enemy({215, 18}, 3, 2);
    
    ui_factory->create_full_box({40, 15}, 5, 3);
    ui_factory->create_box({100, 10}, 5, 3);
    ui_factory->create_full_box({180, 15}, 5, 3);
    ui_factory->create_full_box({220, 13}, 5, 3);
	
	ui_factory->create_moving_platform({230, 10}, 8, 2, 0.15f, 220, 260);
}