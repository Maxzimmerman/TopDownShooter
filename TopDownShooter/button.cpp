#include <raylib.h>
#include "button.hpp"
#include <iostream>

Button::Button() {
	rect = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 100, 30 };
	buttonClicked = false;
	this->text = "default Text";
	color = WHITE;
}

void Button::Draw()
{
	if(!buttonClicked)
		DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
		DrawText(text, rect.x, rect.y, 20, GREEN);
}

bool Button::CheckIfButtonClicked() {
	Vector2 mousePosition = GetMousePosition();
	// check if mouse is on button
	if ((mousePosition.x >= rect.x) && (mousePosition.x <= (rect.x + rect.width)) &&
		(mousePosition.y >= rect.y) && (mousePosition.y <= (rect.y + rect.height))) {
		// check if mouse button clicked
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			return true;
		}
	}
	else
		return false;
}