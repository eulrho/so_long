#include <iostream>
#include "../includes/Game.hpp"
#include "../includes/hook.hpp"

Game::Game() :
	paint(Paint()),
    mlx(NULL),
    win(NULL),
	isEnd(false),
	start_time(clock()),
	attack_time(0) {}

Game::~Game() {}

Game::Game(const string &map_file) :
	paint(Paint()),
    mlx(NULL),
    win(NULL),
	isEnd(false),
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
	this->paint.init(mlx, win);
	this->music.init();
}

void Game::startGame() {
	try {
		this->initializeGame();

		mlx_hook(this->win, KEY_PRESS, KEY_PRESS_MASK, key_hook, this);
		mlx_hook(this->win, EXIT_BUTTON, 0, x_close, this);
		mlx_loop_hook(this->mlx, render_next_frame, this);

		this->music.playBackgroundSound();
		this->paint.drawMap(this->map);
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
		this->music.playCollectionSound();
        this->map.subCollectionCnt(y, x);
		if (this->map.getCollectionCnt() == 0) {
			this->isEnd = true;
			this->paint.setIsBefore(false);
			this->music.playExitSound();
		}
	}
	return true;
}

void Game::move(int y_diff, int x_diff) {
    if (isValidLoad(this->player.getYPos() + y_diff, this->player.getXPos() + x_diff)) {
		this->music.playWalkSound();
		this->paint.removeCharacter(this->player.getYPos(), this->player.getXPos());
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
		if (this->attack_time != 0 && ((double)(clock() - this->attack_time) / CLOCKS_PER_SEC) <= 0.1) return;
		this->attack_time = clock();
		this->music.playAttackSound();
		this->player.damage();
		this->paint.removeHpImage(0, this->player.getHp());
	}
	if (this->player.getHp() == 0)
		this->playerLose();
}

void Game::reDraw()
{
	this->randomMonsterMove();
	this->paint.drawSpriteImage(this->map, this->monster, this->player);
}