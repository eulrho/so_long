#include <iostream>
#include "../includes/Paint.hpp"

Paint::Paint() :
	mlx(NULL),
	win(NULL),
	isBefore(true) {}

Paint::~Paint() {}

void 	Paint::init(void* mlx, void* win)
{
	this->mlx = mlx;
	this->win = win;
	this->setHpImg();
	this->setTileImg();
	this->setWallImg();
	this->setExitImg();
	this->setCollectionImg();
	this->setPlayerImg(false);
	this->setMonsterImg();
}

void	Paint::setIsBefore(bool flag) { this->isBefore = flag; }

void	Paint::draw(Image &img, int y, int x)
{
	mlx_put_image_to_window(this->mlx, this->win, img.image,
							x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	Paint::drawMap(const Map& map)
{
	for (int y = 0; y < (int)map.getYSize(); y++)
	{
		for (int x = 0; x < (int)map.getXSize(); x++)
		{
			this->draw(tile_img, y, x);
			if (map.isEqualChar(y, x, '1'))
				this->draw(wall_img, y, x);
		}
	}
	for (int x = 0; x < 3; x++)
		this->draw(hp_img, 0, x);
}

void 	Paint::removeHpImage(int y, int x)
{
	this->draw(tile_img, y, x);
	this->draw(wall_img, y, x);
}

void	Paint::printLoseMessage(double time, int collection_cnt)
{
	cout << fixed;
	cout.precision(2);
	cout << "\033[1;33m" << "=================================\n";
	cout  << "              LOSE\n";
	cout << "---------------------------------\n";
	cout << "          time        |   " << time << "s\n";
	cout << "---------------------------------\n";
	cout << " remaining collection |    " << collection_cnt << '\n';
	cout << "=================================\n";
}

void	Paint::printWinMessage(double time, int hp)
{
	cout << fixed;
	cout.precision(2);
	cout << "\033[1;32m" << "=================================\n";
	cout  << "              WIN\n";
	cout << "---------------------------------\n";
	cout << "          time        |   " << time << "s\n";
	cout << "---------------------------------\n";
	cout << "     remaining hp     |    " << hp << '\n';
	cout << "=================================\n";
}

void 	Paint::removeCharacter(int y, int x)
{
	this->draw(tile_img, y, x);
}