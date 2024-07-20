#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"
#include "enemy.hpp"
#include 

class Game {
public:
	Player player;
	Cameraa camera;
	std::vector<Enemy> enemies;
	int level = 1;

	Game();
	void HandleInput();
	void Update();
	void Draw();
	void DeleteInactiveLasers();
	void SpawnEnemies();
	void DeleteInactiveEnemies();
	void CheckCollisions();
	void DrawLivePoinst();
	bool CheckIfGameEnd();
	void DrawLevel();
};