#include "game.hpp"
#include <iostream>
#include "vector"
#include "bullet.hpp"

Game::Game()
{
	
}

void Game::Draw() {
	camera.Draw();
	player.Draw();
	player.shooter.Draw();
	for (auto& bullet: player.shooter.bullets) {
		bullet.Draw();
	}
}

void Game::Update() {
	for (auto& bullet: player.shooter.bullets) {
		bullet.Update();
	}
	std::cout << player.shooter.bullets.size() << std::endl;
	player.shooter.Update(player.GetCenter());
	camera.Update(player.position);
}

void Game::HandleInput() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		player.shooter.FireBullets();
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
