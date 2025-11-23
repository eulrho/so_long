#include <iostream>
#include "../includes/Game.hpp"

void Game::playerLose()
{
	this->paint.printLoseMessage((double)(clock() - this->start_time) / CLOCKS_PER_SEC, this->map.getCollectionCnt());
	this->music.stop();
	exit(0);
}

void Game::playerWin()
{
	this->paint.printWinMessage((double)(clock() - this->start_time) / CLOCKS_PER_SEC, this->player.getHp());
	this->music.stop();
	exit(0);
}