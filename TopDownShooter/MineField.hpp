#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "player.hpp"
#include <string>

class MineField
{
private:
	Player* target;
	Vector2 position;
	int radius;
	float movingTimer;
	float movingTime;
	float explodeTimer;
	float explodeTime;
	float speed;
	bool exploded;
	bool shouldExplode;
public:
	MineField();
	MineField(Vector2 position);
	void Draw();
	void Update();
	void setTarget(Player* player) { target = player; } 
	Rectangle getRect();
};

