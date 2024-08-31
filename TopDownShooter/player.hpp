#pragma once
#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"
#include "shooter.hpp"
#include "camera.hpp"

class Player {
private:
	Color color;
	int radius;
	float speed;
	int magazine;
	int magazineSize;
	float refillTime;
	float refillTimer;
	float reloadPregress;
public:
	int livePoints;
	Vector2 position;
	std::vector<Bullet> bullets;
	Player();
	void Draw();
	void Update();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	Vector2 GetCenter();
	Rectangle getRect();
	void ShootBullets(Vector2 mousePosition, Cameraa* camera);
	void TakeLivePoints();
	int getMagazine() { return magazine; }
	void setMagazine(int magazine) { this->magazine = magazine; }
	void decrementMagazine() { magazine--; }
	void DrawReloadProgressBar(Vector2 barPosition, int width, int height);
};