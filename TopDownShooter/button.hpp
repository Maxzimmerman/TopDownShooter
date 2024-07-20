#pragma once
#include <raylib.h>

class Button {
	Rectangle rect;
	bool buttonClicked;
	const char* text;
	Color color;
	Button();
	Button(const char* text);
	void Draw();
};