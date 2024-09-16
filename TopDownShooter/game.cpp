#include "game.hpp"
#include <iostream>
#include "vector"
#include "bullet.hpp"
#include <string>

Game::Game()
{
	player = new Player();
	camera = new Cameraa();
	mineField = new MineField();
	startButton = new Button();
	restartButton = new Button();
	goBackToHomeButton = new Button();
	startButton->text = "Start";
	restartButton->text = "Restart";
	goBackToHomeButton->text = "Home";
	player->weapon->setType(RIFLE);
	SpawnEnemies(6);
}

void Game::Draw() {
	// Dra all gameObjects
	player->Draw();
	DrawLivePoinst();
	DrawLevel();
	DrawMagazineAndPrgressbar();
	DrawXp();

	for (auto& bullet : player->weapon->bullets) {
		bullet.Draw();
	}

	for (auto& enemy : enemies) {
		enemy->Draw();
	}

	for (auto& xp : xps) {
		xp->Draw();
	}

	mineField->Draw();
}

void Game::Update() {
	// update all gameObjects
	for (auto& bullet : player->weapon->bullets) {
		bullet.Update();
	}

	camera->Update(player->GetCenter());
	player->Update();
	player->weapon->Reload();
	DeleteInactiveLasers();
	DeleteInactiveEnemies();

	for (auto& enemy : enemies) {
		enemy->Update(player->GetCenter(), enemies);
	}

	mineField->setTarget(player);
	mineField->Update();

	CheckCollisions();
}

void Game::HandleInput() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		player->weapon->ShootBullets(GetMousePosition(), player->GetCenter());
	}
	else if (IsKeyDown(KEY_W))
		player->MoveUp();
	else if (IsKeyDown(KEY_S))
		player->MoveDown();
	else if (IsKeyDown(KEY_A))
		player->MoveLeft();
	else if (IsKeyDown(KEY_D))
		player->MoveRight();
}

void Game::DeleteInactiveLasers() {
	for (auto it = player->weapon->bullets.begin(); it != player->weapon->bullets.end();) {
		if (!it->active) {
			it = player->weapon->bullets.erase(it);
		}
		else {
			++it;
		}
	}
}

void Game::SpawnEnemies(int howManyEnemies)
{
	if (enemies.size() < howManyEnemies) {
		for (int i = 0; i < howManyEnemies; i++) {
			auto x = GetRandomValue(0, player->getPosition().x + 200);
			auto y = GetRandomValue(0, player->getPosition().y + 200);
			Vector2 vec;
			vec.x = x;
			vec.y = y;
			enemies.push_back(std::make_unique<Enemy>(vec));
		}
	}
}

void Game::DeleteInactiveEnemies()
{
	for (auto it = enemies.begin(); it != enemies.end();) {
		if (!(*it)->active)
			it = enemies.erase(it);
		else
			++it;
	}
}

void Game::CheckCollisions()
{
	// Check for collision Bullets -> Enemy
	for (auto& bullet : player->weapon->bullets) {
		auto it = enemies.begin();
		while (it != enemies.end()) {
			if (CheckCollision((*it)->GetRect(), bullet.GetRect())) {
				// Create xps where enemy died
				for (int i = 1; i < 4; i++) {
					Vector2 pos = (*it)->position;
					int x = GetRandomValue(20, 60);
					int y = GetRandomValue(20, 60);
					Vector2 xpPos = { pos.x + x + i, pos.y + y + i };
					XPType type = TYPE1;
					xps.push_back(std::make_unique<XP>(xpPos));
				}
				it = enemies.erase(it);
				bullet.active = false;
			}
			else {
				++it;
			}
		}
	}

	// Check for collision Enemy -> Player
	auto it = enemies.begin();
	while (it != enemies.end()) {
		if (CheckCollision((*it)->GetRect(), player->getRect())) {
			it = enemies.erase(it);
			player->TakeLivePoints();
		}
		else {
			it++;
		}
	}

	// Check for collision Player -> Xp
	auto xpI = xps.begin();
	while (xpI != xps.end()) {
		if (CheckCollision((*xpI)->getRect(), player->getRect())) {
			player->xp += (*xpI)->getPoints();
			xpI = xps.erase(xpI);
		}
		else {
			xpI++;
		}
	}
}

void Game::DrawLivePoinst()
{
	for (int i = 0; i < player->getLivePoints(); i++) {
		DrawRectangle(player->getPosition().x + 500 + i * 40, player->getPosition().y + 450, 30, 30, RED);
	}
}

bool Game::CheckIfWon()
{
	if (enemies.size() <= 0 || player->xp >= 100)
		return true;
	else
		return false;
}

bool Game::CheckIfLose() {
	if (player->getLivePoints() <= 0)
		return true;
	else
		return false;
}

void Game::DrawLevel()
{
	DrawText((" Level " + std::to_string(level)).c_str(), player->getPosition().x + 530, player->getPosition().y - 450, 20, WHITE);
}

bool Game::CheckCollision(const Rectangle& firstRect, const Rectangle& secondRect)
{
	// x from right and left
	if ((firstRect.x + firstRect.width) >= secondRect.x && firstRect.x <= (secondRect.x + secondRect.width) &&
		// top and bottom
		(firstRect.y + firstRect.height) >= secondRect.y && firstRect.y <= (secondRect.y + secondRect.height)) {
		return true;
	}
	else {
		return false;
	}
}

void Game::Reset(int howManyEnemies)
{
	enemies.clear();
	xps.clear();
	player->xp = 0;
	player->setLivePoints(5);
	SpawnEnemies(howManyEnemies);
}

void Game::DrawMagazineAndPrgressbar()
{
	player->weapon->DrawReloadProgressBar({ player->getPosition().x - 500, player->getPosition().y + 450 }, 120, 30);
	DrawText((std::to_string(player->weapon->getMagazine())).c_str(), player->getPosition().x - 445, player->getPosition().y + 456, 20, WHITE);
}

void Game::DrawXp()
{
	DrawText(std::to_string(player->xp).c_str(), player->getPosition().x - 445, player->getPosition().y - 456, 20, WHITE);
}
