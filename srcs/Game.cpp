#include <iostream>
#include "../includes/Game.hpp"
#include "../includes/hook.hpp"

Game::Game() :
    mlx(NULL),
    win(NULL),
	isEnd(false),
	exit_seq(0),
	collection_seq(0),
	player_seq(0),
	monster_seq(0),
	start_time(clock()),
	attack_time(0) {}

Game::~Game() {}

Game::Game(const string &map_file) :
    mlx(NULL),
    win(NULL),
	isEnd(false),
	exit_seq(0),
	collection_seq(0),
	player_seq(0),
	monster_seq(0),
	start_time(clock()),
	attack_time(0)
{
	try {
		srand((unsigned int)time(NULL));
		this->map = Map(map_file);
		this->map.isValidMap();
		this->player = Player(this->map.getStartY(), this->map.getStartX());
		this->monster = Monster(this->map.getMonsterStartY(), this->map.getMonsterStartX());
	}
	catch(const exception& e) {
		cerr << "\033[1;31m" << "Error\n" << e.what() << "\033[0m";
		exit(1);
	}
}

void Game::initializeGame() {
    this->mlx = mlx_init();
	this->win = mlx_new_window(this->mlx, this->map.getXSize() * IMAGE_SIZE,
			this->map.getYSize() * IMAGE_SIZE, (char*)GAME_NAME);
	this->drawMap();
	this->soundInit();
}

void Game::startGame() {
	try {
		this->initializeGame();

		mlx_hook(this->win, KEY_PRESS, KEY_PRESS_MASK, key_hook, this);
		mlx_hook(this->win, EXIT_BUTTON, 0, x_close, this);
		mlx_loop_hook(this->mlx, render_next_frame, this);

		this->playSound(this->backgroundHandle);
		this->drawMap();
		mlx_loop(this->mlx);
	}
	catch(const exception& e) {
		cerr << "\033[1;31m" << "Error\n" << e.what() << "\033[0m";
		exit(1);
	}
}

bool Game::isValidLoad(int y, int x) {
	if (this->map.isEqualChar(y, x, '1'))
		return false;
	if (this->map.isEqualChar(y, x, 'C'))
	{
		this->playSound(this->mouseHandle);
        this->map.subCollectionCnt(y, x);
		if (this->map.getCollectionCnt() == 0) {
			this->isEnd = true;
			this->playSound(this->exitHandle);
		}
	}
	return true;
}

void Game::move(int y_diff, int x_diff) {
    if (isValidLoad(this->player.getYPos() + y_diff, this->player.getXPos() + x_diff)) {
		this->drawTile(this->player.getXPos(), this->player.getYPos());
		this->playSound(this->walkHandle);
		this->player.walk(y_diff, x_diff);
    }
}

bool Game::isExit() {
    return (this->map.isEqualChar(this->player.getYPos(), this->player.getXPos(), 'E')
        && this->isEnd);
}

void Game::checkCrash()
{
	if (this->monster.getYPos() == -1) return ;
	if (this->monster.getYPos() == this->player.getYPos() && this->monster.getXPos() == this->player.getXPos())
	{
		if (this->attack_time != 0 && (int)((double)(clock() - this->attack_time) / CLOCKS_PER_SEC) < 1) return;
		this->attack_time = clock();
		this->player.damage();
	}
	if (this->player.getHp() == 0)
		this->playerLose();
}