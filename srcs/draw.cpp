#include "../includes/Game.hpp"

void	Game::drawMap()
{	
	for (int y = 0; y < (int)map.getYSize(); y++)
	{
		for (int x = 0; x < (int)map.getXSize(); x++)
		{
			drawTile(x, y);
			if (map.isEqualChar(y, x, '1'))
				drawWall(x, y);
			else if (map.isEqualChar(y, x, 'C')
					&& map.getCollectionCnt() != 0)
				drawCollection(x, y);
			else if (map.isEqualChar(y, x, 'E'))
				drawExit(x, y);
			if (this->player.getXPos() == x && this->player.getYPos() == y)
				drawPlayer(x, y);
		}
	}
}

void	Game::reDraw()
{
	mlx_clear_window(this->mlx, this->win);
	this->drawMap();
}