#pragma once
#include <raylib.h>

class Bullet {
private:
	Rectangle rect;
	Vector2 position;
	Vector2 direction;
	Color color;
	int speed;
	float liveTime;
public:
	bool active;
	Bullet(Vector2 position, Vector2 direction, int speed, Color color);
	Bullet();
	void Draw();
	void Update();
	Rectangle GetRect();
};