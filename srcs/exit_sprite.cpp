#include "../includes/Game.hpp"
#include <iostream>
void	Game::changeExitSprite()
{
	if (this->exit_seq % 10 == 0) {
		int number = this->exit_seq / 10 + 1;
		string file_path = "textures/portal" + to_string(number) + ".xpm";
		this->saveImage(this->exit_img, (char*)file_path.c_str());

		if (number == 8) this->exit_seq = -1;
	}
	this->exit_seq++;
}

void	Game::changeExitImage()
{
	for (int y = 0; y < (int)this->map.getYSize(); y++)
	{
		for (int x = 0; x < (int)this->map.getXSize(); x++)
		{
			if (this->map.isEqualChar(y, x, 'E'))
			{
				this->drawTile(x, y);
				this->drawExit(x, y);
				return ;
			}
		}
	}
}

