#include "game.hpp"
#include <iostream>
#include "vector"

Game::Game()
{

}

void Game::Draw() {
	player.Draw();
	for (auto& bullet: player.bullets) {
		bullet.Draw();
	}
}

void Game::Update() {
	for (auto& bullet: player.bullets) {
		bullet.Update();
	}
}

void Game::HandleInput() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		std::vector<const char*> directions;
		directions.push_back("up");
		directions.push_back("down");
		directions.push_back("left");
		directions.push_back("right");
		int random = GetRandomValue(0, directions.size() - 1);
		player.FireBullet(directions[random]);
	}
	else if (IsKeyDown(KEY_W))
		player.MoveUp();
	else if (IsKeyDown(KEY_S))
		player.MoveDown();
	else if (IsKeyDown(KEY_A))
		player.MoveLeft();
	else if (IsKeyDown(KEY_D))
		player.MoveRight();
}
