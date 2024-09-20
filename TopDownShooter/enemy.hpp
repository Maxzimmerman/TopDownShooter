#include <raylib.h>
#include <iostream>
#include <vector>
#include "XP.hpp"
#include <string>

class Enemy {
public:
	Vector2 position;
	int radius;
	bool active;
	int livePoints;
	Enemy();
	Enemy(Vector2 position);
	Enemy(Vector2 position, int livePoints);
	void Draw();
	void Update(const Vector2& playerPosition, const std::vector<std::unique_ptr<Enemy>>& enemies);
	Rectangle GetRect();
	void takeLivePoint() { livePoints--; }
	int getLivePoinsts() { return livePoints; }
};