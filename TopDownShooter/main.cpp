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

	Rectangle button = { GetScreenWidth() / 2, GetScreenHeight() / 2, 80, 30 };
	bool buttonClicked = false;
	Vector2 mousePosition = { 0, 0 };

	while (!WindowShouldClose()) {

		BeginDrawing();

		switch (currentScreen)
		{
		case HOME:
			mousePosition = GetMousePosition();
			DrawRectangle(button.x, button.y, button.width, button.height, WHITE);
			if (CheckCollisionPointRec(mousePosition, button)) {
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
					currentScreen = LEVEL1;
					break;
				}
			}
			break;
		case LEVEL1:
			BeginMode2D(game.camera.camera);

			game.HandleInput();

			ClearBackground(BLACK);
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
			mousePosition = GetMousePosition();
			DrawText("Gameover", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, RED);
			DrawRectangle(button.x, button.y, button.width, button.height, WHITE);
			if (CheckCollisionPointRec(mousePosition, button)) {
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