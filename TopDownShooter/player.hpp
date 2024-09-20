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
	Texture2D texture;
	bool alive;
public:
	int xp;
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
	void TakeLivePoints(int livePoints) { this->livePoints -= livePoints; }
	void killPlayer();
	int getLivePoints();
	void setLivePoints(int livePoints);
	Vector2 getPosition();
	void setXP(int xp) { this->xp = xp; }
	void setAlive(bool alive) { this->alive = alive; }
	bool isAlive() { return alive; }
};