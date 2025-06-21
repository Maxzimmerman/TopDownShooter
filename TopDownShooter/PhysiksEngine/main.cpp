#include <raylib.h>
#include "player.hpp"

int main() {
	int width = 1500;
	int height = 1000;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

    Player* player = new Player();

	while (!WindowShouldClose()) {

		BeginDrawing();

        player->Draw();
        player->Update();

		EndDrawing();
	}
}