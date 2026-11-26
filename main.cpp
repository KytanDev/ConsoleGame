#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
	// seed random number gen for Knight attacks
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// create game instance and start main game loop
	// game handles menu, combat and progression
	Game game;
	game.run();

	return 0;
}