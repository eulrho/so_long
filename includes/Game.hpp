#ifndef GAME_HPP
# define GAME_HPP

extern "C" {
	# include "../mlx/mlx.h"
}
# include "./Map.hpp"
# include "./Player.hpp"

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

		Game();
		
	public:
		~Game();
        Game(const string&);

		void			*mlx;
		void			*win;

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
};

#endif