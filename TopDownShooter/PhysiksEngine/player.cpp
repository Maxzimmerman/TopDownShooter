#include "player.hpp"

Player::Player() {
    width = 50;
    height = 50;
    position = {0,0};
    gravity = 40.0f;
}

Player::Player(Vector2 position) {
    width = 50;
    height = 50;
    position = position;
    gravity = 40.0f;
}

Player::Player(Vector2 position, float gravity) {
    width = 50;
    height = 50;
    position = position;
    this->gravity = gravity;
}

void Player::Update() {
    position = { position.x, position.y + gravity * GetFrameTime() };
}

void Player::Draw() {
    DrawRectangle(position.x, position.y, width, height, GREEN);
}