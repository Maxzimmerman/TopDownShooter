#include "enemy.hpp"
#include <raylib.h>
#include <raymath.h>

Enemy::Enemy()
{
	position = { 0, 0 };
	radius = 5;
	active = true;
}

Enemy::Enemy(Vector2 position) {
	this->position = position;
	radius = 5;
	active = true;
}

void Enemy::Draw() {
	DrawCircle(position.x, position.y, radius, RED);
}

void Enemy::Update(Vector2 playerPosition) {
	Vector2 direction = Vector2Subtract(playerPosition, position);
	direction = Vector2Normalize(direction);
	position = Vector2Add(position, Vector2Scale(direction, 100 * GetFrameTime()));

	if (active) {
		if (position.x < 0)
			active = false;
		else if (position.x > GetScreenWidth())
			active = false;
		else if (position.y < 0)
			active = false;
		else if (position.y > GetScreenHeight())
			active = false;
	}
}

Rectangle Enemy::GetRect() {
	return { position.x, position.y };
}