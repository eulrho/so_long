#ifndef GAME_HPP
# define GAME_HPP

extern "C" {
	# include "../mlx/mlx.h"
}
# include <cstdlib>
# include "./Map.hpp"
# include "./Player.hpp"
# include "../bass24-osx/c/bass.h"

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
# define TILE "textures/floor.xpm"
# define WALL "textures/crack.xpm"
# define BEFORE_EXIT "textures/portal_bef.xpm"
# define AFTER_EXIT "textures/portal_aft.xpm"
# define COLLECTION "textures/rat.xpm"
# define PLAYER "textures/doctor_64.xpm"

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
		Image	player_img;
		Image	tile_img;
		Image	wall_img;
		Image	collection_img;
		Image	exit_img;
		Map     map;
		Player  player;
		void	*mlx;
		void	*win;
		HSTREAM backgroundHandle;
		HSTREAM walkHandle;
		HSTREAM mouseHandle;
		HSTREAM exitHandle;

		Game();
		
	public:
		~Game();
        Game(const string&);

        const Map		&getMap() const;
		void			initializeGame();
		void			drawMap();
		void			drawPlayer(int, int);
		void			drawTile(int, int);
		void			drawCollection(int, int);
		void			drawExit(int, int);
		void			drawWall(int, int);
		void			startGame();
		bool			isValidLoad(int, int);
		void			move(int, int);
		bool			isExit();
		void 			soundInit();
		void 			printError(int error_no);
		void			reDraw();
		void 			end();
		void 			stopSound();
		void 			playSound(HSTREAM);
};

#endif