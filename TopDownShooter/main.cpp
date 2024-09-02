#include <raylib.h>
#include "game.hpp"
#include "camera.hpp"
#include "GameState.hpp"
#include "Level.hpp"

int main() {
	int width = 1500;
	int height = 1000;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	GameState currentState = MAINMENU;
	Game* game = new Game();
	Level* mainMenu = new Level();
	Level* gameOver = new Level();
	Level* lvl1 = new Level();
	Level* lvl2 = new Level();

	while (!WindowShouldClose()) {

		BeginDrawing();

		switch (currentState)
		{
		case MAINMENU:
			mainMenu->Draw(*game, currentState, LEVEL1, 0);
			break;
		case LEVEL1:
			lvl1->Draw(*game, currentState, LEVEL2, 1);
			break;
		case LEVEL2:
			lvl2->Draw(*game, currentState, MAINMENU, 2);
			break;
		case GAMEOVER:
			gameOver->Draw(*game, currentState, MAINMENU, 0);
			break;
		default:
			break;
		}
		EndDrawing();
	}
}