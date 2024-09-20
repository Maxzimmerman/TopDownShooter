#include "enemy.hpp"
#include <raylib.h>
#include <raymath.h>

Enemy::Enemy()
{
	position = { 0, 0 };
	radius = 20;
	active = true;
    livePoints = 3;
}

Enemy::Enemy(Vector2 position) {
	this->position = position;
	radius = 20;
	active = true;
    livePoints = 3;
}

Enemy::Enemy(Vector2 position, int livePoints)
{
    this->position = position;
    radius = 20;
    active = true;
    this->livePoints = livePoints;
}

void Enemy::Draw() {
    DrawCircle(position.x, position.y, radius, RED);
    DrawText(std::to_string(livePoints).c_str(), position.x - radius / 2, position.y - radius / 2, 20, WHITE);
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