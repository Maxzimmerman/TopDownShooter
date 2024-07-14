#include "game.hpp"
#include <iostream>
#include "vector"
#include "bullet.hpp"

Game::Game()
{
	
}

void Game::Draw() {
	player.Draw();

	for (auto& bullet: player.bullets) {
		bullet.Draw();
	}

	for (auto& enemy : enemies) {
		enemy.Draw();
	}
}

void Game::Update() {
	for (auto& bullet : player.bullets) {
		bullet.Update();
	}

	DeleteInactiveLasers();
	SpawnEnemies();
	DeleteInactiveEnemies();

	for (auto& enemy : enemies) {
		enemy.Update(player.GetCenter(), enemies);
	}

	CheckCollisions();

	std::cout << player.bullets.size() << std::endl;
	std::cout << enemies.size() << std::endl;
}

void Game::HandleInput() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		player.ShootBullets(GetMousePosition());
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
	if (enemies.size() < 5) {
		for (int i = 0; i < 5; i++) {
			auto x = GetRandomValue(0, GetScreenWidth());
			auto y = GetRandomValue(0, GetScreenHeight());
			Vector2 vec;
			vec.x = x;
			vec.y = y;
			enemies.push_back(Enemy(vec));
		}
	}
}

void Game::DeleteInactiveEnemies()
{
	for (auto it = enemies.begin(); it != enemies.end();) {
		if (!it->active)
			it = enemies.erase(it);
		else
			++it;
	}
}

void Game::CheckCollisions()
{
	// Bullets -> Enemy
	for (auto& bullet : player.bullets) {
		auto it = enemies.begin();
		while (it != enemies.end()) {
			if (CheckCollisionRecs(it->GetRect(), bullet.GetRect())) {
				it = enemies.erase(it);
				bullet.active = false;
			}
			else {
				++it;
			}
		}
	}

	// Enemy -> Player

	for (auto& enemy : enemies) {
		if (CheckCollisionRecs(player.getRect(), enemy.GetRect())) {
			player.TakeLivePoints();
		}
	}
}
