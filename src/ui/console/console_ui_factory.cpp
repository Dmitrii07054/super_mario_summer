#include "console_ui_factory.hpp"

using dim::ConsoleUIFactory;

ConsoleUIFactory::ConsoleUIFactory(Game* game) : UIFactory(game) {}

void ConsoleUIFactory::clear_data() {
	game->remove_objs();
	game_map->remove_objs();
	delete mario;
	mario = nullptr;
	boxes.clear();
	full_boxes.clear();
	ships.clear();
	enemies.clear();
	moneys.clear();
	flying_enemies_.clear();
	jumping_enemies_.clear();
	moving_platforms_.clear();
}


void ConsoleUIFactory::create_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleBox* box = new ConsoleBox(top_left, width, height);
	boxes.push_back(box);
	game->add_map_movable(box);
	game->add_static_obj(box);
	game_map->add_obj(box);
}

void ConsoleUIFactory::create_enemy(
	const Coord& top_left, const int width, const int height
) {
	ConsoleEnemy* enemy = new ConsoleEnemy(top_left, width, height);
	enemies.push_back(enemy);
	game->add_map_movable(enemy);
	game->add_movable(enemy);
	game->add_collisionable(enemy);
	game_map->add_obj(enemy);
}

void ConsoleUIFactory::create_full_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleFullBox* full_box = new ConsoleFullBox(top_left, width, height, this);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box);
	game->add_map_movable(full_box);
	game->add_static_obj(full_box);
	game_map->add_obj(full_box);
}

void ConsoleUIFactory::create_mario(
	const Coord& top_left, const int width, const int height
) {
	game->remove_collisionable(mario);
	game->remove_movable(mario);
	game->remove_mario();
	game_map->remove_obj(mario);
	delete mario;
	mario = nullptr;
	
	mario = new ConsoleMario(top_left, width, height);
	game->add_collisionable(mario);
	game->add_movable(mario);
	game->add_mario(mario);
	game_map->add_obj(mario);
}

void ConsoleUIFactory::create_money(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMoney* money = new ConsoleMoney(top_left, width, height);
	moneys.push_back(money);
	game->add_map_movable(money);
	game->add_movable(money);
	game->add_collisionable(money);
	game_map->add_obj(money);
}

void ConsoleUIFactory::create_ship(
	const Coord& top_left, const int width, const int height
) {
	ConsoleShip* ship = new ConsoleShip(top_left, width, height);
	ships.push_back(ship);
	game->add_map_movable(ship);
	game->add_static_obj(ship);
	game_map->add_obj(ship);
}

dim::GameMap* ConsoleUIFactory::get_game_map(const int height, const int width) {
	if (game_map == nullptr) {
		game_map = new ConsoleGameMap(height, width);
	}
	return game_map;
}

dim::Mario* ConsoleUIFactory::get_mario() {
	return mario;
}


dim::FlyingEnemy* ConsoleUIFactory::create_flying_enemy(
    const Coord& top_left, const int width, const int height, float hspeed) {
    
    FlyingEnemy* enemy = new FlyingEnemy(top_left, width, height, hspeed);
    flying_enemies_.push_back(enemy);
    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
    return enemy;
}

dim::JumpingEnemy* ConsoleUIFactory::create_jumping_enemy(
    const Coord& top_left, const int width, const int height, int jump_interval) {

    JumpingEnemy* enemy = new JumpingEnemy(top_left, width, height, jump_interval);
    jumping_enemies_.push_back(enemy);
    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
    return enemy;
}

dim::MovingPlatform* ConsoleUIFactory::create_moving_platform(
    const Coord& top_left, const int width, const int height,
    float hspeed, float left_bound, float right_bound) {

    MovingPlatform* platform = new MovingPlatform(top_left, width, height,
                                                  hspeed, left_bound, right_bound);
    moving_platforms_.push_back(platform);
    game->add_map_movable(platform);
    game->add_static_obj(platform);
    game_map->add_obj(platform);
	game->add_movable(platform);
    return platform;
}
