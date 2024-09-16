#include "enemy.hpp"
#include <raylib.h>
#include <raymath.h>

Enemy::Enemy()
{
	position = { 0, 0 };
	radius = 10;
	active = true;
}

Enemy::Enemy(Vector2 position) {
	this->position = position;
	radius = 10;
	active = true;
}

void Enemy::Draw() {
    DrawCircle(position.x, position.y, radius, RED);
}

void Enemy::Update(const Vector2& playerPosition, const std::vector<std::unique_ptr<Enemy>>& enemies) {
    // Move the enemy in the players direction
    Vector2 direction = Vector2Subtract(playerPosition, position);
    direction = Vector2Normalize(direction);
    position = Vector2Add(position, Vector2Scale(direction, 100 * GetFrameTime()));

    // Separation from other enemies
    for (const auto& other : enemies) {
        if (other.get() != this) { // Avoid self-check
            // get distance between self and other enemy
            Vector2 direction = Vector2Subtract(position, other->position);
            float length = Vector2Length(direction);

            // if distance less than 20 seperate them
            if (length < 20.0f) { // Separation distance
                Vector2 repulsion = Vector2Normalize(direction);
                float seperateBy = 20;
                position = Vector2Add(position, Vector2Scale(repulsion, (seperateBy - length) * 100 * GetFrameTime()));
            }
        }
    }
}

Rectangle Enemy::GetRect() {
	return { position.x, position.y };
}