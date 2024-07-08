#include "bullet.hpp"

Bullet::Bullet(Vector2 posision, int speed, const char* direction, Color color)
{
	this->position.x = posision.x;
	this->position.y = posision.y;
	this->rect.width = 5;
	this->rect.height = 10;
	this->direction = direction;
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
	if(direction == "up") {
		position.y -= speed * GetFrameTime();
	}
	else if(direction == "down") {
		position.y += speed * GetFrameTime();
	}
	else if(direction == "left") {
		position.x -= speed * GetFrameTime();
	}
	else if (direction == "right") {
		position.x += speed * GetFrameTime();
	}

	if (active) {
		if (position.y > GetScreenHeight() && position.y < 0 && position.x > GetScreenWidth() && position.x < 0) {
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