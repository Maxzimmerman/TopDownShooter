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

	for (auto& enemy : enemies) {
		enemy.Draw();
	}
}

void Game::Update() {
	DeleteInactiveLasers();
	player.shooter.Update(player.GetCenter());
	camera.Update(player.position);
	SpawnEnemies();
	std::cout << player.shooter.bullets.size() << std::endl;
	std::cout << enemies.size() << std::endl;

	for (auto& bullet: player.shooter.bullets) {
		bullet.Update();
	}

	for (auto& enemy : enemies) {
		enemy.Update(player.GetCenter());
	}
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

void Game::DeleteInactiveLasers() {
	for (auto it = player.bullets.begin(); it != player.bullets.end();) {
		if (!it->active) {
			it = player.bullets.erase(it);
		}
		else {
			++it;
		}
	}
}

void Game::SpawnEnemies()
{
	if (enemies.size() < 10000) {
		for (int i = 0; i < 10; i++) {
			auto x = GetRandomValue(0, GetScreenWidth());
			auto y = GetRandomValue(0, GetScreenHeight());
			Vector2 vec;
			vec.x = x;
			vec.y = y;
			enemies.push_back(Enemy(vec));
		}
	}
}
