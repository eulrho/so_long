#include <vector>
#include "../includes/Game.hpp"

int find_direction(int y_diff, int x_diff)
{
	if (x_diff == 1 && y_diff == 0) return RIGHT;
	else if (x_diff == -1 && y_diff == 0) return LEFT;
	else if (x_diff == 0 && y_diff == 1) return DOWN;
	else return UP;
}

bool is_valid_direction(int y_diff, int x_diff, int target)
{
	int new_direction = find_direction(y_diff, x_diff);
	if ((new_direction == UP && target == DOWN) || (new_direction == DOWN && target == UP))
		return false;
	if ((new_direction == LEFT && target == RIGHT) || (new_direction == RIGHT && target == LEFT))
		return false;
	return true;
}

void Game::randomMonsterMove()
{
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};

	vector<pair<int, int>> tmp;
	for (int i=0; i<4; i++) {
		int new_y = this->monster.getYPos() + dy[i];
		int new_x = this->monster.getXPos() + dx[i];
		if (this->map.isEqualChar(new_y, new_x, 'E') || this->map.isEqualChar(new_y, new_x, 'C')
					|| this->map.isEqualChar(new_y, new_x, '1'))
			continue ;
		tmp.emplace_back(dy[i], dx[i]);
	}

	vector<pair<int, int>> diff;
	if (tmp.size() != 1) {
		for (auto t : tmp) {
			if (is_valid_direction(t.first, t.second, this->monster.getDirection()))
				diff.push_back(t);
		}
	}
	else diff.push_back(tmp[0]);

	this->drawTile(this->monster.getXPos(), this->monster.getYPos());
	int random_idx = rand() % diff.size();
	this->monster.walk(diff[random_idx].first, diff[random_idx].second);
}