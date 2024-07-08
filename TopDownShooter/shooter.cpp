#include "shooter.hpp"

Shooter::Shooter()
{
	position.x = 100;
	position.y = 100;
	rect.width = 60;
	rect.height = 60;
	speed = 200;
	color = BLUE;
}

void Shooter::Draw() {
	DrawRectangle(position.x, position.y, rect.width, rect.height, color);
}

void Shooter::Update() {
	Vector2 mousePosition = GetMousePosition();
	Vector2 rectCenter = { rect.x + rect.width, rect.y + rect.height };

	float dx = mousePosition.x - rectCenter.x;
	float dy = mousePosition.y - rectCenter.y;
}

Rectangle Shooter::GetRect() {
	return {10 ,10};
}
