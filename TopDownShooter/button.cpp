#include <raylib.h>
#include "button.hpp"
#include <iostream>

Button::Button() {
	rect = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 80, 20 };
	buttonClicked = false;
	this->text = "default Text";
	color = WHITE;
}

void Button::Draw()
{
	DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
	DrawText(text, rect.x, rect.y, 20, GREEN);
}

bool Button::CheckIfButtonClicked() {
	Vector2 mousePosition = GetMousePosition();
	Vector2 direction = { rect.x - mousePosition.x, rect.y - mousePosition.y };
	float distance = sqrt(direction.x*direction.x+direction.y*direction.y);
	if (distance < 3)
		return true;
	else
		return false;
}
