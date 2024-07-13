#pragma once
#include <raylib.h>

class Bullet {
private:
	Rectangle rect;
	Vector2 position;
	const char* direction;
	Color color;
	int speed;
public:
	bool active;
	Bullet(Vector2 posision, int speed, Color color);
	Bullet();
	void Draw();
	void Update();
	Rectangle GetRect();
};