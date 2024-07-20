#include <raylib.h>
#include "button.hpp"

Button::Button(const char* text) {
	rect = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	buttonClicked = false;
	this->text = text;
	color = WHITE;
}

void Button::Draw()
{

}
