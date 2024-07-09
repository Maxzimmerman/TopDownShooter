#pragma once
#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"

class Shooter {
private:
	Vector2 position;
	Rectangle rect;
	int speed;
	Color color;
	float rotation;
public:
	std::vector<Bullet> bullets;
	Shooter();
	void Draw();
	void Update(Vector2 playesrPosition);
	void Rotate(Vector2 playerPosition);
	Rectangle GetRect();
	void FireBullets(const char* direction);
};