#ifndef MONSTER_HPP
# define MONSTER_HPP

#include "./Object.hpp"

class Monster : public Object{
	public:
		Monster();
		~Monster();
		Monster(int, int);

		Monster	&operator=(const Monster &);
		int		findNewDirection(int, int) override;
};

#endif