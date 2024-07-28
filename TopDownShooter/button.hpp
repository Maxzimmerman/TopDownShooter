#pragma once
#include <raylib.h>

class Button {
public:
	Rectangle rect;
	bool buttonClicked;
	const char* text;
	Color color;
	Button();
	void Draw();
	bool CheckIfButtonClicked();
};