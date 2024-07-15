#include "game.hpp"
#include <iostream>
#include "vector"
#include "bullet.hpp"

Game::Game()
{
	
}

void Game::Draw() {
	player.Draw();
	camera.Draw();
	DrawLivePoinst();
	DrawLevel();

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
	camera.Update(player.GetCenter());
	DeleteInactiveLasers();
	SpawnEnemies();
	DeleteInactiveEnemies();

	for (auto& enemy : enemies) {
		enemy.Update(player.GetCenter(), enemies);
	}

	CheckCollisions();
}

void Game::HandleInput() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		player.ShootBullets(GetMousePosition(), camera);
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
	if (enemies.size() < 10) {
		for (int i = 0; i < 10; i++) {
			auto x = GetRandomValue(0, player.position.x + 200);
			auto y = GetRandomValue(0, player.position.y + 200);
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
	auto it = enemies.begin();
	while (it != enemies.end()) {
		if (CheckCollisionRecs(it->GetRect(), player.getRect())) {
			it = enemies.erase(it);
			player.TakeLivePoints();
		}
		else {
			++it;
		}
	}
}

void Game::DrawLivePoinst()
{
	std::cout << player.livePoints << std::endl;
	for (int i = 0; i < player.livePoints; i++) {
		DrawRectangle(player.position.x + 500 + i * 40, player.position.y + 450, 30, 30, RED);
	}
}

bool Game::CheckIfGameEnd()
{
	if (player.livePoints <= 0 || enemies.size() <= 0)
		return true;
	return false;
}

void Game::DrawLevel()
{
	DrawText("Level " + level, player.position.x + 530, player.position.y - 450, 20, WHITE);
}
