#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"
#include "enemy.hpp" 
#include "button.hpp"

class Game {
public:
	Player* player = new Player();
	Cameraa* camera = new Cameraa();
	std::vector<Enemy> enemies;
	int level = 1;
	Button* startButton = new Button();
	Button* restartButton = new Button();
	Button* goBackToHomeButton = new Button();
	Game();
	void HandleInput();
	void Update();
	void Draw();
	void DeleteInactiveLasers();
	void SpawnEnemies(int howManyEnemies);
	void DeleteInactiveEnemies();
	void CheckCollisions();
	void DrawLivePoinst();
	bool CheckIfWon();
	bool CheckIfLose();
	void DrawLevel();
	bool CheckCollision(Rectangle firstRect, Rectangle secondRect);
	void Reset(int howManyEnemies);
	void DrawMagazineAndPrgressbar();
};