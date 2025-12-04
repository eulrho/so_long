#include "../includes/Game.hpp"

void Game::movePlayer(int y_diff, int x_diff) {
	if (isValidLoad(this->player.getYPos() + y_diff, this->player.getXPos() + x_diff)) {
		if (++this->player_move_cnt == 3) {
			this->monster.setPath(this->map, this->player.getYPos() + y_diff, this->player.getXPos() + x_diff);
			this->player_move_cnt = 0;
		}
		this->music.playWalkSound();
		this->paint.removeCharacter(this->player.getYPos(), this->player.getXPos());
		this->player.walk(y_diff, x_diff);
	}
}

void Game::moveMonster()
{
	if (this->monster.isEmptyPath()) return ;
	if (this->monster_move_time != 0 && ((double)(clock() - this->monster_move_time) / CLOCKS_PER_SEC) <= 0.07) return;
	this->monster_move_time = clock();
	this->paint.removeCharacter(this->monster.getYPos(), this->monster.getXPos());
	this->monster.moveByPath();
}