#include "MineField.hpp"

MineField::MineField()
{
	target = nullptr;
	position = {};
	radius = 100;
	speed = 300.0f;
	movingTime = 1.f;
	movingTimer = 5.0f;
	explodeTimer = 0.f;
	explodeTime = 0.5f;
	exploded = false;
	shouldExplode = false;
}

MineField::MineField(Vector2 position)
{
	target = nullptr;
	this->position = position;
	radius = 100;
	speed = 300.0f;
	movingTime = 1.f;
	movingTimer = 0.0f;
	explodeTimer = 0.f;
	explodeTime = 0.5f;
	exploded = false;
	shouldExplode = false;
}

void MineField::Draw()
{
	Color color = { 255, 0, 0, 128 };
	if (!exploded)
		DrawCircle(position.x, position.y, radius, color);
	// Draw timer till mine should explode
	if (!exploded && shouldExplode)
		DrawText(std::to_string(explodeTimer).c_str(), position.x, position.y, 20, RED);
}

void MineField::Update()
{
	// if player and mine collide the mine should not move
	if (CheckCollisionRecs(target->getRect(), this->getRect())) {
		speed = 0.0f;
		shouldExplode = true;
	}

	if (shouldExplode)
		Explode();

	// if mine should not explode and dosen't collide with player
	// - it should just follow the player
	Vector2 direction = Vector2Subtract(target->GetCenter(), position);
	direction = Vector2Normalize(direction);
	position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
}

void MineField::Explode()
{
	// if the mine stopped moving
	// - a timer counts to 5
	// - - if timer is up the mine dissapears
	explodeTimer += GetFrameTime();

	if (explodeTimer > explodeTime) {
		exploded = true;
	}
}

Rectangle MineField::getRect()
{
	Rectangle rect;
	rect.x = position.x - radius / 2;
	rect.y = position.y - radius / 2;
	rect.width = radius;
	rect.height = radius;
	return rect;
}
