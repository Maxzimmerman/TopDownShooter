#pragma once
#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"
#include "shooter.hpp"

class Player {
private:
	Color color;
	int radius;
	float speed;
public:
	Vector2 position;
	Shooter shooter;
	std::vector<Bullet> bullets;
	Player();
	void Draw();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	Vector2 GetCenter();
	Rectangle getRect();
};