#include "../includes/Game.hpp"

int	render_next_frame(void *param)
{
	Game *game = static_cast<Game*>(param);
	game->reDraw();
	game->checkCrash();
	return (0);
}

int	x_close(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	Game *game = static_cast<Game*>(param);
	
	if (keycode == KEY_UP)
		game->movePlayer(-1, 0);
	else if (keycode == KEY_DOWN)
		game->movePlayer(1, 0);
	else if (keycode == KEY_LEFT)
		game->movePlayer(0, -1);
	else if (keycode == KEY_RIGHT)
		game->movePlayer(0, +1);
	else if (keycode == ESC)
		x_close(0, game);
	if (game->isExit())
		game->playerWin();
	return (0);
}
