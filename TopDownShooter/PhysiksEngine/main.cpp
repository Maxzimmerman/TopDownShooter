#include <raylib.h>
#include "player.hpp"

int main() {
	int width = 1000;
	int height = 700;
	const char* title = "Gamewindow";
	InitWindow(width, height, title);
	SetTargetFPS(240);

	// Physische Bewegung
	const float g = 9.81f; // Erdbeschleunigung
	const float mass = 8.0f; // Masse des Koerpers
	const float Cd = 1000.0f; // Luft widerstand
	const float rho = 1.225f; // Luftdichte
	const float area = 0.7f; // Luftflaeche

	float y = 100.0f; // Start Position
	float v = 0.0f;	// Startgeschwindigkeit
	float t = 0.0f; // Zeit
	const float dt = 1.0f / 60.0f; // Zeitintervall

    Player* player = new Player
	(
		{(float)GetScreenHeight(), (float)GetScreenWidth()}, 
		40.0f
	);

	while (!WindowShouldClose()) {
		float F_luft = 0.5f * Cd * rho * area * v * v;
		float direction = (v > 0) ? -1.0f : 1.0f;
		float a = g + direction * (F_luft / mass);

		v += a * dt;
		y += v * dt * 100.0f;

		std::cout << v << std::endl;

		if(GetScreenHeight() - 50.0f < y) {
			y = GetScreenHeight() - 50.0f;
			v = 0;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircle(GetScreenWidth() / 2, (int)y, 20, BLUE);

		EndDrawing();
	}
}