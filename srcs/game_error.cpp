#include "../includes/Game.hpp"

const char* Game::getErrorMessage(int error_no) const
{
	if (error_no == BASS_ERROR_FILEOPEN)
		return "can't open the file";
	else if (error_no == BASS_ERROR_HANDLE)
		return "invalid handle";
	else if (error_no == BASS_ERROR_INIT)
		return "BASS_Init has not been successfully called";
	else if (error_no == BASS_ERROR_NOCHAN)
		return "can't get a free channel";
	else return "some other mystery problem";
}

const char* Game::BassException::what() const throw() { return message; }