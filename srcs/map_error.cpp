#include "../includes/Map.hpp"

const char* Map::getErrorMessage(int error_no) const
{
	if (error_no == FILE_NAME)
		return "invalid file name";
	else if (error_no == INVALID_FILE)
		return "file is empty or not found";
	else if (error_no == INVALID_MAP)
		return "invalid configuration on map";
	else if (error_no == INVALID_PATH)
		return "path not found";
	else return "map is not rectangle";
}

const char* Map::InvalidMapException::what() const throw() { return message; }