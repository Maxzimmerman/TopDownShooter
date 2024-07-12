#include "camera.hpp"

Cameraa::Cameraa()
{
	camera.target = { 0.0f, 0.0f };
	camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
}

void Cameraa::Draw() {
	BeginMode2D(camera);
}

void Cameraa::Update(Vector2 playerPosition) {
	camera.target = playerPosition;
}
