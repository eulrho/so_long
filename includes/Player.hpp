#ifndef PLAYER_HPP
# define PLAYER_HPP

enum DIRECTION {
	LEFT, RIGHT
};

class Player {
	private:
        int		y_pos;
        int		x_pos;
		int		direction;

		void	setDirection(int);
		
	public:
		Player();
		~Player();
		Player(int, int);

        Player      &operator=(const Player &);
		const int&  getYPos() const;
		const int&  getXPos() const;
		const int&	getDirection() const;

        void        walk(int, int);
};

#endif