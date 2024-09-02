#pragma once
#include "GameState.hpp"
#include "game.hpp"

class Level
{
public:
	void Draw(Game&, GameState& currentState, GameState nextState, int lvl);
};

