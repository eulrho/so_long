#include "../includes/Game.hpp"

void	Game::saveImage(Image &img, char *file)
{
	img.image = mlx_xpm_file_to_image(this->mlx, file, &img.width, &img.height);
}

void	Game::drawTile(int x, int y)
{
	if (this->tile_img.image == NULL)
		this->saveImage(this->tile_img, (char*)TILE);
	mlx_put_image_to_window(this->mlx, this->win, this->tile_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawWall(int x, int y)
{
	if (this->wall_img.image == NULL)
		this->saveImage(this->wall_img, (char*)WALL);
	mlx_put_image_to_window(this->mlx, this->win, this->wall_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawExit(int x, int y)
{
	if (!this->isEnd)
		this->saveImage(this->exit_img, (char*)BEFORE_EXIT);
	else this->changeExitSprite();
	mlx_put_image_to_window(this->mlx, this->win, this->exit_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawCollection(int x, int y)
{
	this->changeCollectionSprite();
	mlx_put_image_to_window(this->mlx, this->win, this->collection_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawPlayer(int x, int y)
{
	this->changePlayerSprite();
	mlx_put_image_to_window(this->mlx, this->win, this->player_img.image,
		x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Game::drawMonster(int x, int y)
{
	this->changeMonsterSprite();
	mlx_put_image_to_window(this->mlx, this->win, this->monster_img.image,
							x * IMAGE_SIZE, y * IMAGE_SIZE);
}
