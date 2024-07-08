#include "player.hpp"

Player::Player() {
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	radius = 5;
	speed = 200;
	color = WHITE;
}

void Player::Draw()
{
	DrawCircle(position.x, position.y, radius, color);
}

void Player::MoveLeft() {
	position.x -= speed * GetFrameTime();
}

void Player::MoveRight() {
	position.x += speed * GetFrameTime();
}

void Player::MoveUp() {
	position.y -= speed * GetFrameTime();
}

void Player::MoveDown() {
	position.y += speed * GetFrameTime();
}

void Player::FireBullet(const char* direction)
{
	bullets.push_back(Bullet({ position.x + radius / 2, position.y + radius / 2}, 600, direction, GREEN));
}

Rectangle Player::getRect() {
	Rectangle rect;
	rect.x = position.x - radius / 2;
	rect.y = position.y - radius / 2;
	rect.width = radius;
	rect.height = radius;
	return rect;
}