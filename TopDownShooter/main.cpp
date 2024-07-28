#include <raylib.h>
#include "game.hpp"
#include "camera.hpp"

typedef enum GameScreen { HOME, LEVEL1, LEVEL2, ENDING } GameScreen;

int main() {
	int width = 1500;
	int height = 1000;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	GameScreen currentScreen = HOME;
	Game game;

	while (!WindowShouldClose()) {

		BeginDrawing();

		switch (currentScreen)
		{
		case HOME:
			ClearBackground(BLACK);
			game.startButton.Draw();
			if (game.startButton.CheckIfButtonClicked()) {
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					currentScreen = LEVEL1;
					break;
				}
			}
			break;
		case LEVEL1:
			ClearBackground(BLACK);
			BeginMode2D(game.camera.camera);

			game.HandleInput();
			game.Draw();
			game.Update();

			if (game.CheckIfGameEnd()) {
				currentScreen = ENDING;
				break;
			}

			EndMode2D();
			break;
		case LEVEL2:
			break;
		case ENDING:
			ClearBackground(BLACK);
			game.restartButton.Draw();
			if (game.restartButton.CheckIfButtonClicked()) {
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					currentScreen = LEVEL1;
					break;
				}
			}
			break;
		default:
			break;
		}
		EndDrawing();
	}
}