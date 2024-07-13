#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"
#include "enemy.hpp"

class Game {
public:
	Player player;
	Cameraa camera;
	std::vector<Enemy> enemies;
	Game();
	void HandleInput();
	void Update();
	void Draw();
	void DeleteInactiveLasers();
	void SpawnEnemies();
};