#include "../includes/Player.hpp"

Player::Player() :
    y_pos(0),
    x_pos(0),
	direction(LEFT) {}

Player::Player(int y_pos, int x_pos) :
		y_pos(y_pos),
		x_pos(x_pos),
		direction(LEFT) {}

Player::~Player() {}

Player &Player::operator=(const Player &other)
{
	if (this != &other) {
		this->y_pos = other.y_pos;
		this->x_pos = other.x_pos;
		this->direction = other.direction;
	}
	return *this;
}

void Player::walk(int y_diff, int x_diff)
{
	this->setDirection(x_diff);
	this->y_pos += y_diff;
	this->x_pos += x_diff;
}

const int& Player::getYPos() const { return this->y_pos; }

const int& Player::getXPos() const { return this->x_pos; }

const int& Player::getDirection() const { return this->direction; }

void Player::setDirection(int x_diff)
{
	if (x_diff == 1) this->direction = RIGHT;
	else if (x_diff == -1) this->direction = LEFT;
}