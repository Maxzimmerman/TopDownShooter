#include "Level.hpp"

void Level::Draw(Game& game, GameState& currentState, GameState nextState, int lvl)
{
	if (currentState == MAINMENU) {
		ClearBackground(BLACK);
		game.startButton->Draw();

		if (game.startButton->CheckIfButtonClicked()) {
			game.startButton->buttonClicked = true;
			currentState = nextState;
		}

		if (IsKeyPressed(KEY_ESCAPE))
			CloseWindow();
	}
	else if (currentState == GAMEOVER) {
		ClearBackground(BLACK);
		DrawText("GAMEOVER", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);
		DrawText("Press ESC to leave", GetScreenWidth() / 2, GetScreenHeight() / 2 + 30, 10, RED);

		game.goBackToHomeButton->Draw();
		if (game.goBackToHomeButton->CheckIfButtonClicked()) {
			currentState = nextState;
		}
	}
	else {
		ClearBackground(BLACK);
		BeginMode2D(game.camera->camera);

		game.level = lvl;
		game.HandleInput();
		game.Draw();
		game.Update();

		if (game.CheckIfLose()) {
			game.Reset(10);
			currentState = GAMEOVER;
		}
		else if (game.CheckIfWon()) {
			game.Reset(10);
			currentState = nextState;
		}

		if (IsKeyPressed(KEY_ESCAPE))
			CloseWindow();

		EndMode2D();
	}
}
