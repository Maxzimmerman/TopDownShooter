#include <raylib.h>
#include "game.hpp"

int main() {
	int width = 1000;
	int height = 500;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	Game game;

	while (!WindowShouldClose()) {
		BeginDrawing();

			game.HandleInput();

			ClearBackground(BLACK);
			game.Draw();
			game.Update();

		EndDrawing();
	}
}