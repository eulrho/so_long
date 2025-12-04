#include <queue>
#include "../includes/Monster.hpp"

using namespace std;

stack<pair<int, int>> find_shortest_path(vector<vector<pair<int, int>>>& parent, int target_y, int target_x) {
	stack<pair<int, int>> path;
	path.push({target_y, target_x});

	int y = target_y, x = target_x;
	while (parent[y][x].first != -1) {
		path.push(parent[y][x]);
		y = path.top().first;
		x = path.top().second;
	}
	return path;
}

vector<vector<pair<int, int>>> bfs(Map& m, int start_y, int start_x, int target_y, int target_x) {
	int y_size = (int)m.getYSize(), x_size = (int)m.getXSize();
	vector<vector<int>> distance(y_size, vector<int>(x_size, -1));
	distance[start_y][start_x] = 0;
	vector<vector<pair<int, int>>> parent(y_size, vector<pair<int, int>>(x_size));
	parent[start_y][start_x] = {-1, -1};

	queue<pair<int, int>> q;
	q.push({start_y, start_x});

	int y, x;
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if (y == target_y && x == target_x) break ;

		for (int i=0; i<4; i++) {
			if (y + dy[i] < 0 || y + dy[i] >= y_size || x + dx[i] < 0 || x + dx[i] >= x_size)
				continue ;
			if (m.isEqualChar(y + dy[i], x + dx[i], '1')) continue ;
			if (distance[y + dy[i]][x + dx[i]] == -1 || distance[y + dy[i]][x + dx[i]] > distance[y][x] + 1) {
				q.push({y + dy[i], x + dx[i]});
				distance[y + dy[i]][x + dx[i]] = distance[y][x] + 1;
				parent[y + dy[i]][x + dx[i]] = {y, x};
			}
		}
	}
	return parent;
}

void Monster::setPath(Map& m, int player_y, int player_x) {
	vector<vector<pair<int, int>>> parent = bfs(m, this->getYPos(), this->getXPos(), player_y, player_x);
	this->path = find_shortest_path(parent, player_y, player_x);
}