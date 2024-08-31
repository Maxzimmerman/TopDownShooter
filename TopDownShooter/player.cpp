#include "player.hpp"
#include "shooter.hpp"
#include "bullet.hpp"
#include <raymath.h>
#include "camera.hpp"

Player::Player() {
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
	radius = 5;
	speed = 200;
	color = WHITE;
	livePoints = 5;
	magazine = 5;
	magazineSize = 5;
	refillTime = 2.f;
	refillTimer = 0.0f;
	reloadPregress = 0.0f;
}

void Player::Draw()
{
	if(livePoints > 0)
		DrawCircle(position.x, position.y, radius, color);
}

void Player::Update()
{
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

void Player::MoveLeft() {
	position.x -= speed * GetFrameTime();
}

void Player::MoveRight() {
	position.x += speed * GetFrameTime();
}

void Player::MoveUp() {
	position.y -= speed * GetFrameTime();
}

void Player::MoveDown() {
	position.y += speed * GetFrameTime();
}

Rectangle Player::getRect() {
	Rectangle rect;
	rect.x = position.x - radius / 2;
	rect.y = position.y - radius / 2;
	rect.width = radius;
	rect.height = radius;
	return rect;
}

void Player::ShootBullets(Vector2 mousePosition, Cameraa* camera)
{
	if (magazine > 0) {
		Vector2 worldMouserPosition = GetScreenToWorld2D(mousePosition, camera->camera);

		// bekomme richtungs vektor
		Vector2 direction = { worldMouserPosition.x - position.x, worldMouserPosition.y - position.y };

		direction = Vector2Normalize(direction);
		bullets.push_back(Bullet(GetCenter(), direction, 600, GREEN));
		decrementMagazine();
	}
}

void Player::TakeLivePoints()
{
	livePoints--;
}

void Player::DrawReloadProgressBar(Vector2 barPosition, int width, int height)
{
	DrawRectangle(barPosition.x, barPosition.y, width, height, DARKGRAY);
	DrawRectangle(barPosition.x, barPosition.y, width * reloadPregress, height, GREEN);
}

Vector2 Player::GetCenter() {
	Vector2 p;
	p.x = position.x + radius / 2;
	p.y = position.y + radius / 2;
	return p;
}