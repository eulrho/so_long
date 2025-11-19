#include "../includes/Map.hpp"

int	is_valid_file_name(const string &file_name)
{
	int size = (int)file_name.size();
	
	if (size < 4 || file_name.substr(size - 4) != ".ber")
		return (FILE_NAME);
	return (VALID);
}

void	Map::isValidFile(ifstream &file, const string &file_name)
{
	if (!file.is_open())
		throw InvalidMapException(this->getErrorMessage(INVALID_FILE));
	if (is_valid_file_name(file_name) == FILE_NAME)
		throw InvalidMapException(this->getErrorMessage(FILE_NAME));
}
