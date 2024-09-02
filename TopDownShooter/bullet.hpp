#pragma once
#include <raylib.h>

class Bullet {
private:
	Rectangle rect;
	Vector2 direction;
	Color color;
	int speed;
	float liveTime;
public:
	Vector2 position;
	bool active;
	Bullet(const Vector2& position, const Vector2& direction, int speed, const Color& color);
	Bullet();
	void Draw();
	void Update();
	Rectangle GetRect();
};