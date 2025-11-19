#include "../includes/Game.hpp"
#include "../includes/hook.hpp"

#include <iostream>

Game::Game() :
    mlx(NULL),
    win(NULL),
	isEnd(false),
	exit_seq(0),
	collection_seq(0),
	player_seq(0) {}

Game::~Game() {}

Game::Game(const string &map_file) :
    map(Map(map_file)),
    mlx(NULL),
    win(NULL),
	isEnd(false),
	exit_seq(0),
	collection_seq(0),
	player_seq(0)
{
    this->map.isValidMap();
	this->player = Player(this->map.getStartY(), this->map.getStartX());
	this->initializeGame();
}

const Map& Game::getMap() const  { return this->map; }

void Game::initializeGame() {
    this->mlx = mlx_init();
	this->win = mlx_new_window(this->mlx, this->map.getXSize() * IMAGE_SIZE,
			this->map.getYSize() * IMAGE_SIZE, (char*)GAME_NAME);
	this->drawMap();
	this->soundInit();
}

void Game::startGame() {
    mlx_hook(this->win, KEY_PRESS, KEY_PRESS_MASK, key_hook, this);
	mlx_hook(this->win, EXIT_BUTTON, 0, x_close, this);
	mlx_loop_hook(this->mlx, render_next_frame, this);

	if (!BASS_ChannelPlay(this->backgroundHandle, FALSE))
		this->printError(BASS_ErrorGetCode());
	this->drawMap();
	mlx_loop(this->mlx);
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

void Game::printError(int error_no)
{
	cerr << "Error\n";
	if (error_no == BASS_ERROR_FILEOPEN)
		cerr << "can't open the file";
	else if (error_no == BASS_ERROR_HANDLE)
		cerr << "invalid handle";
	else if (error_no == BASS_ERROR_INIT)
		cerr << "BASS_Init has not been successfully called";
	else if (error_no == BASS_ERROR_NOCHAN)
		cerr << "can't get a free channel";
	else
		cerr << "some other mystery problem";
	exit(1);
}