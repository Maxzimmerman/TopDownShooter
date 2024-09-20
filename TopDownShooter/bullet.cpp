#include "bullet.hpp"
#include <memory>
#include <iostream>
#include <raymath.h>

Bullet::Bullet(const Vector2& position, const Vector2& direction, int speed, const Color& color)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->rect.width = 5;
	this->rect.height = 10;
	this->rect.x = this->position.x;
	this->rect.y = this->position.y;
	this->direction = direction;
	this->color = color;
	this->speed = speed;
	this->active = true;
	this->liveTime = 1.0f;
}

Bullet::Bullet() {
	position = {};
	this->rect.width = 5;
	this->rect.height = 10;
	rect = {};
	this->direction = {};
	this->color = {};
	this->speed = {};
	this->active = true;
	this->liveTime = 1.0f;
}

void Bullet::Draw() {
	if (active)
		DrawRectangle(position.x, position.y, rect.width, rect.height, color);
}

void Bullet::Update() {
	// move bullet in the givin direction
	Vector2 distance = { direction.x * speed * GetFrameTime(), direction.y * speed * GetFrameTime() };
	position = { position.x + distance.x, position.y + distance.y };

	// set a timer if timer is up delete the bullet
	if (active) {
		liveTime -= GetFrameTime();
		if (liveTime <= 0) {
			active = false;
		}
	}
}

Rectangle Bullet::GetRect() {
	Rectangle rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.width = this->rect.width;
	rect.height = this->rect.height;
	return rect;
}