#include <string>
#include "../includes/Game.hpp"

void	Game::changePlayerSprite()
{
	string direction = this->player.getDirection() == LEFT ? "left" : "right";
	int number = this->player_seq / 10 + 1;
	string file_path = "textures/player_" + direction + to_string(number) + ".xpm";

	if (number == 12) this->player_seq = 0;
	else this->player_seq++;
	this->saveImage(this->player_img, (char*)file_path.c_str());
}

void	Game::changePlayerImage()
{
	for (int y = 0; y < (int)this->map.getYSize(); y++)
	{
		for (int x = 0; x < (int)this->map.getXSize(); x++)
		{
			if (this->player.getXPos() == x && this->player.getYPos() == y)
			{
				if (this->map.isEqualChar(y, x, '0') && !(this->monster.getYPos() == y && this->monster.getXPos() == x))
					this->drawTile(x, y);
				this->drawPlayer(x, y);
			}
		}
	}
}