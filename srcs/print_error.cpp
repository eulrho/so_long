#include "../includes/so_long.hpp"

void	print_error(int error_no)
{
	cerr << "Error\n";
	if (error_no == OTHER_CHARACTERS)
		cerr << "other characters on the map";
	else if (error_no == MEMORY)
		cerr << "memory error";
	else if (error_no == FILE_NAME)
		cerr << "invalid file name";
	else if (error_no == STANDARD_INPUT)
		cerr << "invalid input";
	else if (error_no == INVALID_FILE)
		cerr << "file is empty or not found";
	else if (error_no == INVALID_MAP)
		cerr << "invalid configuration on map";
	else if (error_no == INVALID_PATH)
		cerr << "path not found";
	else if (error_no == MAP_SIZE)
		cerr << "map is not rectangle";
	else if (error_no == OVER_FLOW)
		cerr << "overflow!!!!!!!!!";
	exit(1);
}
