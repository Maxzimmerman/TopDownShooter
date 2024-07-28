#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"
#include "enemy.hpp" 
#include "button.hpp"

class Game {
public:
	Player player;
	Cameraa camera;
	std::vector<Enemy> enemies;
	int level = 1;
	Button startButton;
	Button restartButton;
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
	bool CheckCollision(Vector2 firstRect, Vector2 secondRect);
};