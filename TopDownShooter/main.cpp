#include <raylib.h>
#include "game.hpp"
#include "camera.hpp"

int main() {
	int width = 1500;
	int height = 1000;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	Game game;

	while (!WindowShouldClose()) {
		BeginDrawing();
		BeginMode2D(game.camera.camera);

			game.HandleInput();

			ClearBackground(BLACK);
			game.Draw();
			game.Update();
			EndMode2D();
		EndDrawing();
	}
}