# include <iostream>
#include "../includes/Game.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "invalid input";
		exit(1);
	}
	const string map_file = string(argv[1]);
	Game game(map_file);
	game.initializeGame();
	game.startGame();
	return 0;
}
