#include "player.hpp"

Player::Player() {
    width = 50;
    height = 50;
    position = {0,0};
}

Player::Player(Vector2 position) {
    width = 50;
    height = 50;
    position - position;
}

void Player::Update() {
    position.y += 20 * GetFrameTime();
}

void Player::Draw() {
    DrawRectangle(position.x, position.y, width, height, GREEN);
}