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
public:
	std::vector<Bullet> bullets;
	Shooter();
	void Draw();
	void Update();
	Rectangle GetRect();
};