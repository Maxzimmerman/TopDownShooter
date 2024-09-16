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
	
}

void Weapon::Reload()
{
	// if the magazine is empty set a timer and update the progress
	if (magazine <= 0) {
		refillTimer += GetFrameTime();
		reloadPregress = refillTimer / refillTime;

		// if the timer is up fill up magazine and reset timer
		if (refillTimer >= refillTime) {
			magazine = magazineSize;
			refillTimer = 0.0f;
			reloadPregress = 0.0f;
		}
	}
}

void Weapon::ShootBullets(const Vector2& mousePosition, const Vector2& playerCenter)
{
	// if magazin is not empty
	// - define direction the bullet should move to
	// - add bullet two game
	// - decrement the magazine size
	if (magazine > 0) {
		Vector2 direction = Vector2Subtract(mousePosition, position);
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

void Weapon::DrawReloadProgressBar(const Vector2& barPosition, int width, int height)
{
	DrawRectangle(barPosition.x, barPosition.y, width, height, DARKGRAY);
	DrawRectangle(barPosition.x, barPosition.y, width * reloadPregress, height, GREEN);
}

void Weapon::setType(const WeaponType& type)
{
	this->type = type;
}
