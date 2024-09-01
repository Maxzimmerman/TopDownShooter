#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "vector"
#include "bullet.hpp"
#include "camera.hpp"
#include "WeaponType.hpp"

class Weapon
{
private:
	int magazine;
	int magazineSize;
	float refillTime;
	float refillTimer;
	float reloadPregress;
	Vector2 position;
	WeaponType type;
public:
	std::vector<Bullet> bullets;
	Weapon();
	void Draw();
	void Update();
	void ShootBullets(Vector2 mousePosition, Cameraa& camera, Vector2 playerCenter);
	int getMagazine();
	void setMagazine(int magazine);
	void decrementMagazine();
	void DrawReloadProgressBar(Vector2 barPosition, int width, int height);
	void setType(WeaponType type);
};

