#include "../includes/so_long.hpp"

int start_cnt = 0;
int end_cnt = 0;

void	is_valid_map_config(Map& map, int y, int x)
{
	if ((y == 0 || y == map.getYSize() - 1) && !map.isEqualChar(y, x, '1'))
		print_error(INVALID_MAP);
	if ((x == 0 || x == map.getXSize() - 1) && !map.isEqualChar(y, x, '1'))
		print_error(INVALID_MAP);
	if (!map.isEqualChar(y, x, '0') && !map.isEqualChar(y, x, '1')
			&& !map.isEqualChar(y, x, 'C') && !map.isEqualChar(y, x, 'E')
			&& !map.isEqualChar(y, x, 'P'))
		print_error(INVALID_MAP);
	if (map.isEqualChar(y, x, 'P'))
	{
		map.setStartY(y);
		map.setStartX(x);
		start_cnt++;
	}
	else if (map.isEqualChar(y, x, 'C'))
		map.addCollectionCnt();
	else if (map.isEqualChar(y, x, 'E'))
		end_cnt++;
}

void	is_valid_config_count(const int collection_cnt)
{
	if (collection_cnt == 0)
		print_error(INVALID_MAP);
	if (end_cnt != 1)
		print_error(INVALID_MAP);
	if (start_cnt != 1)
		print_error(INVALID_MAP);
}

void	is_valid_rectangle(const vector<string>& contents, int y, int x_size)
{
	if (contents[y].size() != x_size)
		print_error(MAP_SIZE);
}

void	is_valid_map(Map &map)
{
	const vector<string>& contents = map.getContents();
	
	for (int y = 0; y < (int)map.getYSize(); y++) {
		is_valid_rectangle(contents, y, (int)map.getXSize());
		for (int x = 0; x < (int)map.getXSize(); x++)
			is_valid_map_config(map, y, x);
	}
	is_valid_config_count(map.getCollectionCnt());
	is_valid_path(map);
}
