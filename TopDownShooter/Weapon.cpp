#include "Weapon.hpp"

Weapon::Weapon()
{
	magazine = 5;
	magazineSize = 5;
	refillTime = 2.f;
	refillTimer = 0.0f;
	reloadPregress = 0.0f;
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	type = DEFAULT;
}

void Weapon::Draw()
{
	
}

void Weapon::Update()
{
	if (type == RIFLE) {
		if (magazine <= 0) {
			refillTimer += GetFrameTime();
			reloadPregress = refillTimer / refillTime;

			if (refillTimer >= refillTime) {
				magazine = magazineSize;
				refillTimer = 0.0f;
				reloadPregress = 0.0f;
			}
		}
	}
	if (type == SHOTGUN) {
		if (magazine < magazineSize) {
			refillTimer += GetFrameTime();
			reloadPregress = refillTimer / refillTime;

			if (refillTimer >= refillTime) {
				magazine++;
				refillTimer = 0.0f;
				reloadPregress = 0.0f;
			}
		}
	}
}

void Weapon::ShootBullets(Vector2 mousePosition, Cameraa& camera, Vector2 playerCenter)
{
	if (magazine > 0) {
		Vector2 direction = { mousePosition.x - position.x, mousePosition.y - position.y };

		direction = Vector2Normalize(direction);
		bullets.push_back(Bullet(playerCenter, direction, 600, GREEN));
		decrementMagazine();
	}
}

int Weapon::getMagazine()
{
	return magazine;
}

void Weapon::setMagazine(int magazine)
{
	this->magazine = magazine;
}

void Weapon::decrementMagazine()
{
	magazine--;
}

void Weapon::DrawReloadProgressBar(Vector2 barPosition, int width, int height)
{
	DrawRectangle(barPosition.x, barPosition.y, width, height, DARKGRAY);
	DrawRectangle(barPosition.x, barPosition.y, width * reloadPregress, height, GREEN);
}

void Weapon::setType(WeaponType type)
{
	this->type = type;
}
