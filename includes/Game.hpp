#ifndef GAME_HPP
# define GAME_HPP

extern "C" {
	# include "../mlx/mlx.h"
	# include "../bass24-osx/c/bass.h"
}
# include <cstdlib>
# include <ctime>
# include <string>
# include <stdexcept>
# include "./Map.hpp"
# include "./Player.hpp"
# include "./Monster.hpp"

using namespace std;

# define IMAGE_SIZE 64

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

// image path
# define TILE "textures/crack.xpm"
# define WALL "textures/rock.xpm"
# define BEFORE_EXIT "textures/portal_bef.xpm"

// bgm path
# define BACKGROUND "/Users/rho-eul/study/so_long/bgm/game_bgm.mp3"
# define WALK "/Users/rho-eul/study/so_long/bgm/walk.mp3"
# define MOUSE "/Users/rho-eul/study/so_long/bgm/mouse.mp3"
# define EXIT "/Users/rho-eul/study/so_long/bgm/exit.mp3"
# define CLEAR "/Users/rho-eul/study/so_long/bgm/clear.mp3"

// execution name
# define GAME_NAME "so_long"

struct Image {
	void	*image = NULL;
    int		width = 0;
    int		height = 0;
};

class Game {
	private:
		Image		player_img;
		Image		tile_img;
		Image		wall_img;
		Image		collection_img;
		Image		exit_img;
		Image		monster_img;
		Map     	map;
		Player  	player;
		Monster		monster;
		void		*mlx;
		void		*win;
		HSTREAM 	backgroundHandle;
		HSTREAM 	walkHandle;
		HSTREAM 	mouseHandle;
		HSTREAM 	exitHandle;
		bool 		isEnd;
		int			exit_seq;
		int 		collection_seq;
		int 		player_seq;
		int 		monster_seq;
		clock_t		start_time;
		clock_t 	attack_time;

		Game();

		void		initializeGame();

		void		drawMap();
		void		drawPlayer(int, int);
		void		drawTile(int, int);
		void		drawCollection(int, int);
		void		drawExit(int, int);
		void		drawWall(int, int);
		void		drawMonster(int, int);
		void		saveImage(Image&, char*);

		bool		isValidLoad(int, int);

		void		soundInit();
		void 		playSound(HSTREAM);

		void 		changeExitSprite();
		void		changeCollectionSprite();
		void		changePlayerSprite();
		void 		changeMonsterSprite();

		void 		randomMonsterMove();

		const char*	getErrorMessage(int) const;
		void 		playerLose();

		class BassException : public exception {
			private:
				const char* message;
			public:
				BassException(const char* message) : message(message) {};
				const char* what() const throw();
		};
		
	public:
		~Game();
        Game(const string&);

		void	startGame();
		void 	playerWin();
		void	move(int, int);
		bool	isExit();
		void 	checkCrash();

		void	changeExitImage();
		void 	changeCollectionImage();
		void 	changePlayerImage();
		void 	changeMonsterImage();

		void 	stopSound();
};

#endif