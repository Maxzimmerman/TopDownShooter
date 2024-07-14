#include "shooter.hpp"
#include <cmath> // For atan2f
#include "raymath.h"

Shooter::Shooter() {
    rect.width = 10;
    rect.height = 30;
    position.x = rect.width / 2;
    position.y = rect.height / 2;
    speed = 50;
    color = BLUE;
    rotation = 0;
}

void Shooter::Draw() {
    Vector2 origin = { rect.width / 2, rect.height / 2 };
    DrawRectanglePro(rect, origin, rotation, color);
}

void Shooter::Update(Vector2 playerPosition) {
    Rotate(playerPosition);
}

void Shooter::Rotate(Vector2 playerPosition) {
    Vector2 mousePosition = GetMousePosition();
    float dx = mousePosition.x - playerPosition.x;
    float dy = mousePosition.y - playerPosition.y;
    rotation = atan2f(dy, dx) * (180.0f / PI);

    // Distance from the player center to the shooter center
    float distanceFromPlayer = 40.0f;
    position.x = playerPosition.x + cos(rotation * (PI / 180.0f)) * distanceFromPlayer;
    position.y = playerPosition.y + sin(rotation * (PI / 180.0f)) * distanceFromPlayer;

    // Update rect position for drawing
    rect.x = position.x;
    rect.y = position.y;
}

Rectangle Shooter::GetRect() {
    return { position.x - rect.width / 2, position.y - rect.height / 2, rect.width, rect.height };
}

void Shooter::FireBullets(Vector2 playerPosition, Vector2 mousePosition)
{
    Vector2 direction = Vector2Subtract(mousePosition, playerPosition);
    direction = Vector2Normalize(direction);
    bullets.push_back(Bullet(playerPosition, direction, 600, GREEN));
}
