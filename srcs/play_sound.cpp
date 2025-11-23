#include "../includes/Music.hpp"

void	Music::play(HSTREAM handle)
{
	if (!BASS_ChannelPlay(handle, TRUE))
		throw BassException(this->getErrorMessage(BASS_ErrorGetCode()));
}

void	Music::playBackgroundSound() { this->play(this->backgroundHandle); }

void	Music::playWalkSound()  { this->play(this->walkHandle); }

void	Music::playCollectionSound()  { this->play(this->collectionHandle); }

void	Music::playExitSound()  { this->play(this->exitHandle); }

void	Music::playAttackSound()  { this->play(this->attackHandle); }