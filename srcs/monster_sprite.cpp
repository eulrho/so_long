#include <string>
#include "../includes/Game.hpp"
#include <iostream>
void	Game::changeMonsterSprite()
{
	int number = this->monster_seq / 10 + 1;
	string file_path = "textures/fire" + to_string(number) + ".xpm";

	if (number == 10) this->monster_seq = 0;
	else this->monster_seq++;
	this->saveImage(this->monster_img, (char*)file_path.c_str());
}

void	Game::changeMonsterImage()
{
	if (this->monster.getYPos() == -1) return ;
	if (rand() % 50 == 1)
		this->randomMonsterMove();

	for (int y = 0; y < (int)this->map.getYSize(); y++)
	{
		for (int x = 0; x < (int)this->map.getXSize(); x++)
		{
			if (this->monster.getXPos() == x && this->monster.getYPos() == y)
			{
				if (this->map.isEqualChar(y, x, '0'))
					this->drawTile(x, y);
				this->drawMonster(x, y);
			}
		}
	}
}