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
	game.startButton.Draw();
	if (game.startButton.CheckIfButtonClicked()) {
		game.startButton.buttonClicked = true;
		currentState = LEVEL1;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();
}

void DrawLevel1(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	BeginMode2D(game.camera.camera);

	game.level = 1;
	game.HandleInput();
	game.Draw();
	game.Update();

	if (game.CheckIfGameEnd()) {
		currentState = GAMEOVER;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();

	EndMode2D();
}

void DrawLevel2(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	BeginMode2D(game.camera.camera);

	game.level = 2;
	game.HandleInput();
	game.Draw();
	game.Update();

	if (game.CheckIfGameEnd()) {
		currentState = GAMEOVER;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();

	EndMode2D();
}

void DrawGameOver(Game& game, GameState& currentState) {
	ClearBackground(BLACK);
	game.restartButton.Draw();
	if (game.restartButton.CheckIfButtonClicked()) {
		game.restartButton.buttonClicked = true;
		game.Reset();
		currentState = LEVEL1;
	}

	if (IsKeyPressed(KEY_ESCAPE))
		CloseWindow();
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