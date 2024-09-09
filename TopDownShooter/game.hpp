#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"
#include "enemy.hpp" 
#include "button.hpp"
#include "XP.hpp"

class Game {
public:
	std::vector<std::unique_ptr<XP>> xps;
	Player* player;
	Cameraa* camera;
	std::vector<std::unique_ptr<Enemy>> enemies;
	int level = 1;
	Button* startButton;
	Button* restartButton;
	Button* goBackToHomeButton;
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
	bool CheckCollision(const Rectangle& firstRect, const Rectangle& secondRect);
	void Reset(int howManyEnemies);
	void DrawMagazineAndPrgressbar();
	void DrawXp();
};