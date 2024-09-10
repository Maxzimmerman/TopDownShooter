#include "enemy.hpp"
#include <raylib.h>
#include <raymath.h>

Enemy::Enemy()
{
    texture = LoadTexture("C:\\Users\\Max Zimmermann\\source\\repos\\TopDownShooter\\assets\\enemies\\two\\idle_0.png");
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
    DrawTexture(texture, position.x, position.y, WHITE);
}

void Enemy::Update(const Vector2& playerPosition, const std::vector<std::unique_ptr<Enemy>>& enemies) {
    // Follow player
    Vector2 direction = { playerPosition.x - position.x, playerPosition.y - position.y };
    direction = Vector2Normalize(direction);
    position = { position.x + direction.x * 100 * GetFrameTime(), position.y + direction.y * 100 * GetFrameTime() };

    // Separation from other enemies
    for (const auto& other : enemies) {
        if (other.get() != this) { // Avoid self-check
            Vector2 distance = { position.x - other->position.x, position.y - other->position.y };
            float length = sqrt(distance.x * distance.x + distance.y * distance.y);

            if (length < 20.0f) { // Separation distance
                Vector2 repulsion = Vector2Normalize(distance);
                position = { position.x + repulsion.x * (20.0f - length) * 100 * GetFrameTime(), position.y + repulsion.y * (20.0f - length) * 100 * GetFrameTime() };
            }
        }
    }
}

Rectangle Enemy::GetRect() {
	return { position.x, position.y };
}