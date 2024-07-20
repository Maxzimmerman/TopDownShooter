#include "bullet.hpp"
#include <memory>
#include <iostream>
#include <raymath.h>

Bullet::Bullet(Vector2 posision, Vector2 direction, int speed, Color color)
{
	this->position.x = posision.x;
	this->position.y = posision.y;
	this->rect.width = 5;
	this->rect.height = 10;
	this->direction = direction;
	this->color = color;
	this->speed = speed;
	this->active = true;
	this->liveTime = 1.0f;
}

Bullet::Bullet() {

}

void Bullet::Draw() {
	if (active)
		DrawRectangle(position.x, position.y, rect.width, rect.height, color);
}

void Bullet::Update() {
	position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
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