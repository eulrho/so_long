#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "./Object.hpp"

enum DIRECTION {
	LEFT, RIGHT
};

class Player : public Object{
	private:
		int		hp;
		int		direction;

		void	setDirection(int);
		int		findNewDirection(int);
	public:
		Player();
		~Player();
		Player(int, int);

        Player&		operator=(const Player &);

		const int&	getHp() const;
		const int&	getDirection() const;

		void		damage();
		void		walk(int, int) override;
};

#endif