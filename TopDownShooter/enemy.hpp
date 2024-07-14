#include <raylib.h>
#include <iostream>
#include <vector>

class Enemy {
public:
	Vector2 position;
	int radius;
	bool active;
	Enemy();
	Enemy(Vector2 position);
	void Draw();
	void Update(Vector2 playerPosition, const std::vector<Enemy>& enemies);
	Rectangle GetRect();
};