#include "../includes/Game.hpp"

void	Game::drawMap()
{	
	for (int y = 0; y < (int)this->map.getYSize(); y++)
	{
		for (int x = 0; x < (int)this->map.getXSize(); x++)
		{
			this->drawTile(x, y);
			if (this->map.isEqualChar(y, x, '1'))
				this->drawWall(x, y);
			else if (this->map.isEqualChar(y, x, 'C')
					&& this->map.getCollectionCnt() != 0)
				this->drawCollection(x, y);
			else if (this->map.isEqualChar(y, x, 'E'))
				this->drawExit(x, y);
			if (this->player.getXPos() == x && this->player.getYPos() == y)
				this->drawPlayer(x, y);
			if (this->monster.getXPos() == x && this->monster.getYPos() == y)
				this->drawMonster(x, y);
		}
	}
	for (int x = 0; x < 3; x++)
		drawPlayerHp(x, 0);
}