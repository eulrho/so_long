#include "../includes/Music.hpp"

Music::Music() {}

Music::~Music() {}

void Music::init() {
	// -1 : 기본 오디오 출력 장치, 44100 : 샘플링 속도
	if (!BASS_Init(-1, 44100, 0, 0, NULL))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));

	this->backgroundHandle = BASS_StreamCreateFile(FALSE, BACKGROUND, 0, 0, 0 | BASS_SAMPLE_LOOP);
	this->walkHandle = BASS_StreamCreateFile(FALSE, WALK, 0, 0, 0);
	this->collectionHandle = BASS_StreamCreateFile(FALSE, MOUSE, 0, 0, 0);
	this->exitHandle = BASS_StreamCreateFile(FALSE, EXIT, 0, 0, 0);
	this->attackHandle = BASS_StreamCreateFile(FALSE, ATTACK, 0, 0, 0);
	if (!(this->backgroundHandle && this->walkHandle && this->collectionHandle && this->exitHandle && this->attackHandle))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}

void Music::stop()
{
	if (!(BASS_ChannelStop(this->backgroundHandle) && BASS_StreamFree(this->backgroundHandle) && BASS_StreamFree(this->walkHandle)
		&& BASS_StreamFree(this->collectionHandle) && BASS_StreamFree(this->exitHandle) && BASS_StreamFree(this->attackHandle)))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}

const char* Music::getErrorMessage(int error_no) const
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

const char* Music::BassException::what() const throw() { return message; }