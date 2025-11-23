#ifndef GAME_HPP
# define GAME_HPP

extern "C" {
	# include "../mlx/mlx.h"
	# include "../bass24-osx/c/bass.h"
}
# include <cstdlib>
# include <ctime>
# include <string>
# include "./Map.hpp"
# include "./Player.hpp"
# include "./Monster.hpp"
# include "./Paint.hpp"
# include "./Music.hpp"

using namespace std;

// mask code
# define KEY_PRESS_MASK 1

// mac key codes
# define LEFT_CLICK 1
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define ESC 53
# define KEY_PRESS 2
# define EXIT_BUTTON 17

// execution name
# define GAME_NAME "so_long"

class Game {
	private:
		Paint		paint;
		Map     	map;
		Player  	player;
		Monster		monster;
		Music		music;
		void		*mlx;
		void		*win;
		bool 		isEnd;
		clock_t		start_time;
		clock_t 	attack_time;

		Game();

		void		initializeGame();
		bool		isValidLoad(int, int);

		void 		playerLose();
		
	public:
		~Game();
        Game(const string&);

		void	startGame();
		void 	playerWin();
		void	move(int, int);
		bool	isExit();
		void 	randomMonsterMove();
		void 	checkCrash();
		void 	reDraw();
};

#endif