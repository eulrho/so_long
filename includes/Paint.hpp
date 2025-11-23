#ifndef PAINT_HPP
# define PAINT_HPP

extern "C" {
# include "../mlx/mlx.h"
}

# include "./Map.hpp"
# include "./Player.hpp"
# include "./Monster.hpp"

# define IMAGE_SIZE 64

// image path
# define IMAGE_PATH "textures/"
# define FILE_EXTENSION ".xpm"
# define MONSTER "fire"
# define TILE "crack"
# define WALL "rock"
# define BEFORE_EXIT "portal_bef"
# define HP "heart"
# define PLAYER "player_"
# define COLLECTION "rat"
# define AFTER_EXIT "portal"

struct Image {
	void	*image = NULL;
	int		width = 0;
	int		height = 0;
	int		seq = 0;
};

class Map;
class Player;
class Monster;

class Paint {
	private:
		void	*mlx;
		void	*win;
		Image	player_img;
		Image	tile_img;
		Image	wall_img;
		Image	collection_img;
		Image	exit_img;
		Image	monster_img;
		Image	hp_img;

		bool	isBefore;

		void	setPlayerImg(bool);
		void	setTileImg();
		void	setWallImg();
		void	setCollectionImg();
		void	setExitImg();
		void	setMonsterImg();
		void	setHpImg();
		void 	saveImage(Image&, char*);

		void 	changeSpriteImage(int);
		void 	draw(Image&, int, int);

	public:
		Paint();
		~Paint();

		void	init(void*, void*);
		void	drawMap(const Map&);
		void	drawSpriteImage(const Map&, const Monster&, const Player&);
		void	setIsBefore(bool);

		void	removeCharacter(int, int);
		void 	removeHpImage(int, int);

		void 	printLoseMessage(double, int);
		void 	printWinMessage(double, int);
};

#endif
