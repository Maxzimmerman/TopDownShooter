#include "XP.hpp"

XP::XP(Vector2 pos, XPType type)
{
	type = type;
	picked = false;
	this->position = pos;
	this->width = 15;
	this->height = 15;
	setPoints(type);
}

XP::XP(Vector2 pos)
{
	type = INITIAL;
	picked = false;
	this->position = pos;
	this->width = 15;
	this->height = 15;
	setPoints(type);
}

XP::XP()
{
	type = INITIAL;
	picked = false;
	this->position = {};
	this->width = 15;
	this->height = 15;
	setPoints(type);
}

void XP::Draw()
{
	Color color = BLACK;
	if (!picked)
		if (type == INITIAL)
			color = GREEN;
		else if (type == TYPE1)
			color = GREEN;
		else if (type == TYPE2)
			color = RED;
	DrawRectangle(position.x, position.y, width, height, color);
}

void XP::setPoints(XPType type)
{
	if (type == INITIAL)
		points = 10;
	else if (type == TYPE1)
		points = 10;
	else if (type == TYPE2)
		points = 20;
}

Rectangle XP::getRect()
{
	Rectangle rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.width = width;
	rect.height = height;
	return rect;
}
