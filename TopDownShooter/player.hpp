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
public:
	int livePoints;
	Vector2 position;
	std::vector<Bullet> bullets;
	Player();
	void Draw();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	Vector2 GetCenter();
	Rectangle getRect();
	void ShootBullets(Vector2 mousePosition, Cameraa& camera);
	void TakeLivePoints();
};