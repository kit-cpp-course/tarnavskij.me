#include"game.h"



int main()
{

	Game game =new Game();


	game->setup();
	game->difficulLevel();
	game->initialize();

	while (game->frame());

	game->shutdown();


	delete game;

	return 0;
}

