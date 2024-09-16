#include <raylib.h>
#include <iostream>
#include <vector>
#include "XP.hpp"

class Enemy {
public:
	Vector2 position;
	int radius;
	bool active;
	Enemy();
	Enemy(Vector2 position);
	void Draw();
	void Update(const Vector2& playerPosition, const std::vector<std::unique_ptr<Enemy>>& enemies);
	Rectangle GetRect();
};