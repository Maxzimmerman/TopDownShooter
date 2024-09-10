#include "player.hpp"
#include "bullet.hpp"
#include <raymath.h>
#include "camera.hpp"

Player::Player() {
	weapon = std::make_unique<Weapon>();
	texture = LoadTexture("C:\\Users\\Max Zimmermann\\source\\repos\\TopDownShooter\\assets\\characters\\three\\idle_0.png");
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	radius = 5;
	speed = 200;
	color = WHITE;
	livePoints = 5;
	xp = 0;
}

void Player::Draw()
{
	if (livePoints > 0)
		DrawTexture(texture, position.x, position.y, WHITE);
}

void Player::Update()
{
	
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

void Player::TakeLivePoints()
{
	livePoints--;
}

int Player::getLivePoints()
{
	return livePoints;
}

void Player::setLivePoints(int livePoints)
{
	this->livePoints = livePoints;
}

Vector2 Player::getPosition()
{
	return position;
}

Vector2 Player::GetCenter() {
	Vector2 p;
	p.x = position.x + radius / 2;
	p.y = position.y + radius / 2;
	return p;
}