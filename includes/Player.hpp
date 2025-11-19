#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "./Object.hpp"

class Player : public Object{
	private:
		int hp;
	public:
		Player();
		~Player();
		Player(int, int);

        Player      &operator=(const Player &);

		const int	&getHp() const;
		void		damage();
};

#endif