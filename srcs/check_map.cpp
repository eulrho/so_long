#include "../includes/Map.hpp"

void	Map::isValidMapConfig(int y, int x, int &start_cnt, int &end_cnt)
{
	if ((y == 0 || y == (int)this->y_size - 1) && !this->isEqualChar(y, x, '1'))
		this->printError(INVALID_MAP);
	if ((x == 0 || x == (int)this->x_size - 1) && !this->isEqualChar(y, x, '1'))
		this->printError(INVALID_MAP);
	if (!this->isEqualChar(y, x, '0') && !this->isEqualChar(y, x, '1')
			&& !this->isEqualChar(y, x, 'C') && !this->isEqualChar(y, x, 'E')
			&& !this->isEqualChar(y, x, 'P'))
		this->printError(INVALID_MAP);
	if (this->isEqualChar(y, x, 'P'))
	{
		this->setStartY(y);
		this->setStartX(x);
		start_cnt++;
	}
	else if (this->isEqualChar(y, x, 'C'))
		this->addCollectionCnt();
	else if (this->isEqualChar(y, x, 'E'))
		end_cnt++;
}

void	Map::isValidConfigCount(const int &end_cnt, const int &start_cnt)
{
	if (this->collection_cnt == 0)
		this->printError(INVALID_MAP);
	if (end_cnt != 1)
		this->printError(INVALID_MAP);
	if (start_cnt != 1)
		this->printError(INVALID_MAP);
}

void	Map::isValidRectangle(int y)
{
	if (this->contents[y].size() != this->x_size)
		this->printError(MAP_SIZE);
}

void	Map::isValidMap()
{	
	int start_cnt = 0;
	int end_cnt = 0;
	for (int y = 0; y < (int)this->y_size; y++) {
		this->isValidRectangle(y);
		for (int x = 0; x < (int)this->x_size; x++)
			this->isValidMapConfig(y, x, start_cnt, end_cnt);
	}
	this->isValidConfigCount(start_cnt, end_cnt);
	this->isValidPath();
}
