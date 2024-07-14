#include "player.hpp"
#include "shooter.hpp"
#include "bullet.hpp"
#include <raymath.h>

Player::Player() {
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	radius = 5;
	speed = 200;
	color = WHITE;
	livePoints = 5;
}

void Player::Draw()
{
	if(livePoints > 0)
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

void Player::ShootBullets(Vector2 mousePosition)
{
	Vector2 direction = Vector2Subtract(mousePosition, GetCenter());
	direction = Vector2Normalize(direction);
	bullets.push_back(Bullet(GetCenter(), direction, 600, GREEN));
}

void Player::TakeLivePoints()
{
	livePoints--;
}

Vector2 Player::GetCenter() {
	Vector2 p;
	p.x = position.x + radius / 2;
	p.y = position.y + radius / 2;
	return p;
}