#ifndef PLAYER_HPP
# define PLAYER_HPP

using namespace std;

class Player {
	private:
        int	y_pos;
        int	x_pos;
        int	foot_print;
		
	public:
		Player();
		~Player();
        Player(int, int);
        Player &operator=(const Player &);
		const int getYPos() const;
		const int getXPos() const;

        void XMove(int);
        void YMove(int);
        void move();
};

#endif