#include "../includes/so_long.hpp"

int	key_hook(int keycode, void *param)
{
	Game *game = static_cast<Game*>(param);
	
	if (keycode == KEY_UP)
		game->move(-1, 0);
	else if (keycode == KEY_DOWN)
		game->move(1, 0);
	else if (keycode == KEY_LEFT)
		game->move(0, -1);
	else if (keycode == KEY_RIGHT)
		game->move(0, +1);
	else if (keycode == ESC)
		x_close(0, game);
	if (game->isExit())
		x_close(0, game);
	return (0);
}

int	render_next_frame(void *param)
{
	Game *game = static_cast<Game*>(param);
	mlx_clear_window(game->mlx, game->win);
	game->drawMap();
	return (0);
}

int	x_close(int keycode, void *param)
{
	exit(0);
	return (0);
}
