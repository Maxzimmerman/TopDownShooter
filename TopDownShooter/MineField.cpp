#include "MineField.hpp"

MineField::MineField()
{
	target = nullptr;
	position = {};
	radius = 100;
	speed = 300.0f;
	movingTime = 1.f;
	movingTimer = 0.0f;
	exploded = false;
}

MineField::MineField(Vector2 position)
{
	target = nullptr;
	this->position = position;
	radius = 100;
	speed = 300.0f;
	movingTime = 1.f;
	movingTimer = 0.0f;
	exploded = false;
}

void MineField::Draw()
{
	Color color = { 255, 0, 0, 128 };
	if(!exploded)
		DrawCircle(position.x, position.y, radius, color);
}

void MineField::Update()
{
	if (CheckCollisionRecs(target->getRect(), this->getRect())) {
		speed = 0.0f;
		movingTimer += GetFrameTime();

		if (movingTimer > movingTime) {
			exploded = true;
		}
	}

	Vector2 direction = Vector2Subtract(target->GetCenter(), position);
	direction = Vector2Normalize(direction);
	position = { position.x + direction.x * speed * GetFrameTime(), position.y + direction.y * speed * GetFrameTime() };
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
