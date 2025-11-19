#include <iostream>
#include "../includes/Game.hpp"

void Game::playerLose()
{
	cout << fixed;
	cout.precision(2);
	cout << "\033[1;33m" << "=================================\n";
	cout  << "              LOSE\n";
	cout << "---------------------------------\n";
	cout << "          time        |   " << (double)(clock() - this->start_time) / CLOCKS_PER_SEC << "s\n";
	cout << "---------------------------------\n";
	cout << " remaining collection |    " << this->map.getCollectionCnt() << '\n';
	cout << "=================================\n";
	this->stopSound();
	exit(0);
}

void Game::playerWin()
{
	cout << fixed;
	cout.precision(2);
	cout << "\033[1;32m" << "=================================\n";
	cout  << "              WIN\n";
	cout << "---------------------------------\n";
	cout << "          time        |   " << (double)(clock() - this->start_time) / CLOCKS_PER_SEC << "s\n";
	cout << "---------------------------------\n";
	cout << "     remaining hp     |    " << this->player.getHp() << '\n';
	cout << "=================================\n";
	this->stopSound();
	exit(0);
}