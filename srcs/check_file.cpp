#include "../includes/so_long.hpp"

int	is_valid_file_name(string &file_name)
{
	int size = (int)file_name.size();
	
	if (size < 4 || file_name.substr(size - 4) != ".ber")
		return (FILE_NAME);
	return (VALID);
}

void	is_valid_file(ifstream &file, string file_name)
{
	if (!file.is_open())
		print_error(INVALID_FILE);
	if (is_valid_file_name(file_name) == FILE_NAME)
		print_error(FILE_NAME);
}
