#include "../includes/so_long.hpp"

int y_size = 0;
int x_size = 0;

bool	check_reached(Map &map, int **visited)
{	
	for (int y = 0; y < (int)y_size; y++)
	{
		for (int x = 0; x < (int)x_size; x++)
		{
			if (map.isEqualChar(y, x, 'C') && visited[y][x] == 0)
				return false;
			if (map.isEqualChar(y, x, 'E') && visited[y][x] == 0)
				return false;
		}
	}
	return true;
}

void	find(int **visited, Map &map, int y, int x)
{
	if (y < 0 || y >= y_size || x < 0 || x >= x_size)
		return ;
	if (map.isEqualChar(y, x, '1'))
		return ;
	visited[y][x] = 1;
	if (visited[y][x - 1] == 0)
		find(visited, map, y, x - 1);
	if (visited[y - 1][x] == 0)
		find(visited, map, y - 1, x);
	if (visited[y][x + 1] == 0)
		find(visited, map, y, x + 1);
	if (visited[y + 1][x] == 0)
		find(visited, map, y + 1, x);
}

void	is_valid_path(Map &map)
{
	y_size = (int)map.getYSize();
	x_size = (int)map.getXSize();
	
	int** visited = new int*[y_size];
	for (int i = 0; i < y_size; i++)
		visited[i] = new int[x_size];
	
	find(visited, map, map.getStartY(), map.getStartX());
	if (!check_reached(map, visited))
		print_error(INVALID_PATH);
	
	for(int i = 0; i < y_size; i++)
		delete[] visited[i];
	delete[] visited;
}
