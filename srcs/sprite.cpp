#include "../includes/Paint.hpp"

void	Paint::changeSpriteImage(int player_direction) {
	this->setExitImg();
	this->setCollectionImg();
	this->setPlayerImg(player_direction);
	this->setMonsterImg();
}

bool	should_redraw_tile(int y, int x, const Map& map, const Monster& monster, const Player& player)
{
	return (monster.getXPos() == x && monster.getYPos() == y)
		|| (player.getXPos() == x && player.getYPos() == y)
		|| map.isEqualChar(y, x, 'E')
		|| map.isEqualChar(y, x, 'C');
}

void	Paint::drawSpriteImage(const Map& map, const Monster& monster, const Player& player)
{
	this->changeSpriteImage(player.getDirection());
	for (int y = 0; y < (int)map.getYSize(); y++)
	{
		for (int x = 0; x < (int)map.getXSize(); x++)
		{
			if (should_redraw_tile(y, x, map, monster, player))
				this->draw(tile_img, y, x);
			if (map.isEqualChar(y, x, 'E'))
				this->draw(exit_img, y, x);
			if (monster.getXPos() == x && monster.getYPos() == y)
				this->draw(monster_img, y, x);
			if (map.isEqualChar(y, x, 'C'))
				this->draw(this->collection_img, y, x);
			if (player.getXPos() == x && player.getYPos() == y)
				this->draw(player_img, y, x);
		}
	}
	this->collection_img.seq++;
}