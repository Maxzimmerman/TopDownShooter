#pragma once
#include "Weapon.hpp"
#include <raylib.h>
#include "bullet.hpp"
#include <iostream>
#include "vector"
#include "camera.hpp"

class Player {
private:
	Color color;
	int radius;
	float speed;
	int livePoints;
	Vector2 position;
public:
	std::unique_ptr<Weapon> weapon;
	Player();
	void Draw();
	void Update();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	Vector2 GetCenter();
	Rectangle getRect();
	void TakeLivePoints();
	int getLivePoints();
	void setLivePoints(int livePoints);
	Vector2 getPosition();
};