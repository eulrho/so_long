#include "../includes/Map.hpp"

bool	Map::checkReached(int **visited)
{	
	for (int y = 0; y < (int)this->y_size; y++)
	{
		for (int x = 0; x < (int)this->x_size; x++)
		{
			if (this->isEqualChar(y, x, 'C') && visited[y][x] == 0)
				return false;
			if (this->isEqualChar(y, x, 'E') && visited[y][x] == 0)
				return false;
		}
	}
	return true;
}

void	Map::find(int **visited, int y, int x)
{
	if (y < 0 || y >= (int)this->y_size || x < 0 || x >= (int)this->x_size)
		return ;
	if (this->isEqualChar(y, x, '1'))
		return ;
	visited[y][x] = 1;
	if (visited[y][x - 1] == 0)
		this->find(visited, y, x - 1);
	if (visited[y - 1][x] == 0)
		this->find(visited, y - 1, x);
	if (visited[y][x + 1] == 0)
		this->find(visited, y, x + 1);
	if (visited[y + 1][x] == 0)
		this->find(visited, y + 1, x);
}

void	Map::isValidPath()
{	
	int** visited = new int*[this->y_size];
	for (int i = 0; i < (int)this->y_size; i++)
		visited[i] = new int[this->x_size];
	
	this->find(visited, this->start_y, this->start_x);
	if (!this->checkReached(visited))
		this->printError(INVALID_PATH);
	
	for(int i = 0; i < (int)this->y_size; i++)
		delete[] visited[i];
	delete[] visited;
}
