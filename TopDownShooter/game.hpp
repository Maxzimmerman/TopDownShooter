#include <raylib.h>
#include "player.hpp"

class Game {
private:
	Player player;
public:
	Game();
	void HandleInput();
	void Update();
	void Draw();
};