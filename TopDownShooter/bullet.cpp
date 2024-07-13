#include "bullet.hpp"
#include <memory>
#include <iostream>

Bullet::Bullet(Vector2 posision, int speed, Color color)
{
	this->position.x = posision.x;
	this->position.y = posision.y;
	this->rect.width = 5;
	this->rect.height = 10;
	this->direction = "direction";
	this->color = color;
	this->speed = speed;
	this->active = true;
}

Bullet::Bullet() {

}

void Bullet::Draw() {
	if (active)
		DrawRectangle(position.x, position.y, rect.width, rect.height, color);
}

void Bullet::Update() {
	position.x += 0 * GetFrameTime();
	position.y += 1000 * GetFrameTime();
	if (active) {
		if (position.y > GetScreenHeight() || position.y < 0 || position.x > GetScreenWidth() || position.x < 0) {
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