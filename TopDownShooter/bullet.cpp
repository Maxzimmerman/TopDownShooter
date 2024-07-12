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
	if (active) {
		Vector2 mousePosition = GetMousePosition();
		Vector2 directionToMouse = { mousePosition.x - position.x, mousePosition.y - position.y };

		// Normalize the direction vector
		float length = sqrt(directionToMouse.x * directionToMouse.x + directionToMouse.y * directionToMouse.y);
		if (length != 0) {
			directionToMouse.x /= length;
			directionToMouse.y /= length;
		}

		// Update position with normalized direction and speed
		position.x += directionToMouse.x * speed;
		position.y += directionToMouse.y * speed;


		if (position.y > GetScreenHeight() || position.y < 0 && position.x > GetScreenWidth() || position.x < 0) {
			active = false;
			std::cout << "dec" << std::endl;
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