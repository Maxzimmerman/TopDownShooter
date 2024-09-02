#pragma once
#include <raylib.h>

class Cameraa {
public:
	Camera2D camera;
	Cameraa();
	Cameraa(Vector2& playerPosition);
	void Draw();
	void Update(const Vector2& playerPosition);
};