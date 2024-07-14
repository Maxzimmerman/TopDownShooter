#pragma once
#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"

class Shooter {
private:
	Rectangle rect;
	int speed;
	Color color;
	float rotation;
public:
	Vector2 position;
	std::vector<Bullet> bullets;
	Shooter();
	void Draw();
	void Update(Vector2 playesrPosition);
	void Rotate(Vector2 playerPosition);
	Rectangle GetRect();
	void FireBullets(Vector2 playerPosition, Vector2 mousePosition);
};