#include <iostream>
#include "../includes/Game.hpp"

void	save_image(void *mlx, Image &img, char *file)
{
	img.image = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
}

void	Game::drawTile(int x, int y)
{
	if (this->tile_img.image == NULL)
		save_image(this->mlx, this->tile_img, (char*)TILE);
	mlx_put_image_to_window(this->mlx, this->win, this->tile_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawWall(int x, int y)
{
	if (this->wall_img.image == NULL)
		save_image(this->mlx, this->wall_img, (char*)WALL);
	mlx_put_image_to_window(this->mlx, this->win, this->wall_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawExit(int x, int y)
{
	if (this->exit_img.image == NULL)
	{
		if (this->map.getCollectionCnt() != 0)
			save_image(this->mlx, this->exit_img, (char*)BEFORE_EXIT);
		else
			save_image(this->mlx, this->exit_img, (char*)AFTER_EXIT);
	}
	mlx_put_image_to_window(this->mlx, this->win, this->exit_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawCollection(int x, int y)
{
	if (this->collection_img.image == NULL)
		save_image(this->mlx, this->collection_img, (char*)COLLECTION);
	mlx_put_image_to_window(this->mlx, this->win, this->collection_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawPlayer(int x, int y)
{
	if (this->player_img.image == NULL)
		save_image(this->mlx, this->player_img, (char*)PLAYER);
	mlx_put_image_to_window(this->mlx, this->win, this->player_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}
