#pragma once
#include <raylib.h>
#include "player.hpp"
#include "camera.hpp"

class Game {
public:
	Player player;
	Cameraa camera;
	Game();
	void HandleInput();
	void Update();
	void Draw();
};