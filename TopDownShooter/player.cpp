#include "player.hpp"
#include "shooter.hpp"
#include "bullet.hpp"

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

Rectangle Player::getRect() {
	Rectangle rect;
	rect.x = position.x - radius / 2;
	rect.y = position.y - radius / 2;
	rect.width = radius;
	rect.height = radius;
	return rect;
}

Vector2 Player::GetCenter() {
	Vector2 p;
	p.x = position.x + radius / 2;
	p.y = position.y + radius / 2;
	return p;
}