#include "../includes/so_long.hpp"

Map	read_map(string map_file)
{
	ifstream file(map_file);
	is_valid_file(file, map_file);

	vector<string> result;
	string line;
	while (getline(file, line))
	{
		if (line.empty())
			print_error(INVALID_MAP);
		result.push_back(line);
	}
	if (result.empty())
		print_error(INVALID_FILE);
	file.close();
	return Map(result);
}

int	main(int argc, char **argv)
{
	if (argc != 2) print_error(STANDARD_INPUT);

	Map new_map = read_map(string(argv[1]));
	is_valid_map(new_map);

	Game game(new_map);
	game.initializeGame();
	game.startGame();
	return 0;
}
