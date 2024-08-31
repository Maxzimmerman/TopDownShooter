#include <raylib.h>
#include "game.hpp"
#include "camera.hpp"

enum GameState {
	MAINMENU,
	LEVEL1,
	LEVEL2,
	GAMEOVER,
};

void DrawMainMenu(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	game.startButton->Draw();

	if (game.startButton->CheckIfButtonClicked()) {
		game.startButton->buttonClicked = true;
		currentState = LEVEL1;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();
}

void DrawLevel1(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	BeginMode2D(game.camera->camera);

	game.level = 1;
	game.HandleInput();
	game.Draw();
	game.Update();

	if (game.CheckIfLose()) {
		game.Reset(10);
		currentState = GAMEOVER;
	}
	else if (game.CheckIfWon()) {
		game.Reset(30);
		currentState = LEVEL2;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();

	EndMode2D();
}

void DrawLevel2(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	BeginMode2D(game.camera->camera);

	game.level = 2;
	game.HandleInput();
	game.Draw();
	game.Update();

	if (game.CheckIfLose()) {
		game.Reset(10);
		currentState = GAMEOVER;
	}
	else if (game.CheckIfWon()) {
		game.Reset(10);
		currentState = LEVEL1;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();

	EndMode2D();
}

void DrawGameOver(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	DrawText("GAMEOVER", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);
	DrawText("Press ESC to leave", GetScreenWidth() / 2, GetScreenHeight() / 2 + 30, 10, RED);

	game.goBackToHomeButton->Draw();
	if (game.goBackToHomeButton->CheckIfButtonClicked()) {
		currentState = MAINMENU;
	}
}

int main() {
	int width = 1500;
	int height = 1000;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	GameState currentState = MAINMENU;
	Game game;

	while (!WindowShouldClose()) {

		BeginDrawing();

		switch (currentState)
		{
		case MAINMENU:
			DrawMainMenu(game, currentState);
			break;
		case LEVEL1:
			DrawLevel1(game, currentState);
			break;
		case LEVEL2:
			DrawLevel2(game, currentState);
			break;
		case GAMEOVER:
			DrawGameOver(game, currentState);
			break;
		default:
			break;
		}
		EndDrawing();
	}
}