#include <string>
#include "../includes/Paint.hpp"

void	Paint::saveImage(Image &img, char *file)
{
	img.image = mlx_xpm_file_to_image(this->mlx, file, &img.width, &img.height);
}

string	make_file_path(string file_name, int number) {
	string result = IMAGE_PATH + file_name;
	if (number != -1) result += to_string(number);
	result += FILE_EXTENSION;
	return result;
}

void	Paint::setPlayerImg(bool isRight) {
	string direction = isRight == false ? "left" : "right";
	int number = this->player_img.seq / 10 + 1;
	string file_path = make_file_path(PLAYER + direction, number);

	if (number == 12) this->player_img.seq = 0;
	else this->player_img.seq++;
	this->saveImage(this->player_img, (char *) file_path.c_str());
}

void	Paint::setTileImg() {
	string file_path = make_file_path(TILE, -1);
	this->saveImage(this->tile_img, (char *) file_path.c_str());
}

void	Paint::setWallImg() {
	string file_path = make_file_path(WALL, -1);
	this->saveImage(this->wall_img, (char *) file_path.c_str());
}

void	Paint::setCollectionImg() {
	if (this->collection_img.seq % 13 == 0) {
		int number = this->collection_img.seq / 10 + 1;
		string file_path = make_file_path(COLLECTION, number);
		this->saveImage(this->collection_img, (char*)file_path.c_str());

		if (number == 10) this->collection_img.seq = -1;
	}
}

void	Paint::setExitImg() {
	if (this->isBefore) {
		string file_path = make_file_path(BEFORE_EXIT, -1);
		this->saveImage(this->exit_img, (char*)file_path.c_str());
		return ;
	}
	if (this->exit_img.seq % 10 == 0) {
		int number = this->exit_img.seq / 10 + 1;
		string file_path = make_file_path(AFTER_EXIT, number);
		this->saveImage(this->exit_img, (char*)file_path.c_str());

		if (number == 8) this->exit_img.seq = -1;
	}
	this->exit_img.seq++;
}

void	Paint::setMonsterImg() {
	int number = this->monster_img.seq / 10 + 1;
	string file_path = make_file_path(MONSTER, number);
	if (number == 10) this->monster_img.seq = 0;
	else this->monster_img.seq++;
	this->saveImage(this->monster_img, (char*)file_path.c_str());
}

void	Paint::setHpImg() {
	string file_path = make_file_path(HP, -1);
	this->saveImage(this->hp_img, (char*)file_path.c_str());
}