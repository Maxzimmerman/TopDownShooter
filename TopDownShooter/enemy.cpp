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

void Enemy::Update(Vector2 playerPosition, const std::vector<Enemy>& enemies) {
    // Follow player
    Vector2 direction = Vector2Subtract(playerPosition, position);
    direction = Vector2Normalize(direction);
    position = Vector2Add(position, Vector2Scale(direction, 100 * GetFrameTime()));

    // Separation from other enemies
    for (const auto& other : enemies) {
        if (&other != this) { // Avoid self-check
            Vector2 distance = Vector2Subtract(position, other.position);
            float length = Vector2Length(distance);

            if (length < 20.0f) { // Separation distance
                Vector2 repulsion = Vector2Normalize(distance);
                position = Vector2Add(position, Vector2Scale(repulsion, (20.0f - length) * 100 * GetFrameTime())); // Increase the repulsion force
            }
        }
    }
}

Rectangle Enemy::GetRect() {
	return { position.x, position.y };
}