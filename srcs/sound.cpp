#include "../includes/Game.hpp"

void Game::soundInit() {
	// -1 : 기본 오디오 출력 장치, 44100 : 샘플링 속도
	if (!BASS_Init(-1, 44100, 0, 0, NULL))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));

	this->backgroundHandle = BASS_StreamCreateFile(FALSE, BACKGROUND, 0, 0, 0 | BASS_SAMPLE_LOOP);
	this->walkHandle = BASS_StreamCreateFile(FALSE, WALK, 0, 0, 0);
	this->mouseHandle = BASS_StreamCreateFile(FALSE, MOUSE, 0, 0, 0);
	this->exitHandle = BASS_StreamCreateFile(FALSE, EXIT, 0, 0, 0);
	this->attackHandle = BASS_StreamCreateFile(FALSE, ATTACK, 0, 0, 0);
	if (!(this->backgroundHandle && this->walkHandle && this->mouseHandle && this->exitHandle && this->attackHandle))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}

void Game::playSound(HSTREAM handle)
{
	if (!BASS_ChannelPlay(handle, TRUE))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}

void Game::stopSound()
{
	if (!(BASS_ChannelStop(this->backgroundHandle) && BASS_StreamFree(this->backgroundHandle) && BASS_StreamFree(this->walkHandle)
		&& BASS_StreamFree(this->mouseHandle) && BASS_StreamFree(this->exitHandle) && BASS_StreamFree(this->attackHandle)))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}