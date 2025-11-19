#include "../includes/Game.hpp"

void	Game::changeCollectionSprite()
{
	if (this->collection_seq % 13 == 0) {
		int number = this->collection_seq / 10 + 1;
		string file_path = "textures/rat" + to_string(number) + ".xpm";
		this->saveImage(this->collection_img, (char*)file_path.c_str());

		if (number == 10) this->collection_seq = -1;
	}
}

void	Game::changeCollectionImage()
{
	for (int y = 0; y < (int)this->map.getYSize(); y++)
	{
		for (int x = 0; x < (int)this->map.getXSize(); x++)
		{
			if (this->map.isEqualChar(y, x, 'C'))
			{
				this->drawTile(x, y);
				this->drawCollection(x, y);
			}
		}
	}
	this->collection_seq++;
}