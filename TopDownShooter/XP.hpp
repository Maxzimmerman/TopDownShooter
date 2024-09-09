#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "XPType.hpp"

class XP
{
private:
	Vector2 position;
	int width;
	int height;
	bool picked;
	XPType type;
	int points;
public:
	XP(Vector2 pos, XPType type);
	XP(Vector2 pos);
	XP();
	void Draw();
	void setPoints(XPType type);
	Rectangle getRect();
	int getPoints() { return points; }
};

