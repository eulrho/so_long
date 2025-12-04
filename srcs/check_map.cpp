#include "../includes/Map.hpp"

void	Map::isValidMapConfig(int y, int x, int &player_cnt, int &end_cnt, int &monster_cnt)
{
	if ((y == 0 || y == (int)this->y_size - 1) && !this->isEqualChar(y, x, '1'))
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
	if ((x == 0 || x == (int)this->x_size - 1) && !this->isEqualChar(y, x, '1'))
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));

	if (this->isEqualChar(y, x, 'P'))
	{
		this->setStartY(y);
		this->setStartX(x);
		this->contents[y][x] = '0';
		player_cnt++;
	}
	else if (this->isEqualChar(y, x, 'C'))
		this->addCollectionCnt();
	else if (this->isEqualChar(y, x, 'E'))
		end_cnt++;
	else if (this->isEqualChar(y, x, 'M'))
	{
		this->setMonsterStartY(y);
		this->setMonsterStartX(x);
		this->contents[y][x] = '0';
		monster_cnt++;
	}
	else if (!(this->isEqualChar(y, x, '0') || this->isEqualChar(y, x, '1')))
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
}

void	Map::isValidConfigCount(const int &end_cnt, const int &player_cnt, const int &monster_cnt)
{
	if (this->collection_cnt == 0)
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
	if (end_cnt != 1)
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
	if (player_cnt != 1)
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
	if (monster_cnt >= 2)
		throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
}

void	Map::isValidRectangle(int y)
{
	if (this->contents[y].size() != this->x_size)
		throw InvalidMapException(this->getErrorMessage(MAP_SIZE));
}

void	Map::isValidMap()
{
	if ((long long)this->y_size * this->x_size > 2147483647)
		throw InvalidMapException(this->getErrorMessage(MAP_SIZE));
	int player_cnt = 0;
	int end_cnt = 0;
	int monster_cnt = 0;
	for (int y = 0; y < (int)this->y_size; y++) {
		this->isValidRectangle(y);
		for (int x = 0; x < (int)this->x_size; x++)
			this->isValidMapConfig(y, x, player_cnt, end_cnt, monster_cnt);
	}
	this->isValidConfigCount(end_cnt, player_cnt, monster_cnt);
	this->isValidPath();
}
