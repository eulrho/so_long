#ifndef MONSTER_HPP
# define MONSTER_HPP

#include <vector>
#include <stack>
#include "./Object.hpp"
#include "./Map.hpp"

class Map;

class Monster : public Object{
	private:
		stack<pair<int, int>>	path;
	public:
		Monster();
		~Monster();
		Monster(int, int);

		Monster	&operator=(const Monster &);
		int		findNewDirection(int, int) override;
		void	setPath(Map&, int, int);
		bool 	isEmptyPath();
		void 	moveByPath();
};

#endif