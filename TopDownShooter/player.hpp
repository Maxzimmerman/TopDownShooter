#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"

class Player {
private:
	Vector2 position;
	Color color;
	int radius;
	float speed;
public:
	std::vector<Bullet> bullets;
	Player();
	void Draw();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void FireBullet(const char* direction);
	Rectangle getRect();
};