#include "../includes/Player.hpp"

Player::Player() :
	Object(),
	hp(3),
	direction(LEFT) {}

Player::Player(int y_pos, int x_pos) :
	Object(y_pos, x_pos),
	hp(3),
	direction(LEFT) {}

Player::~Player() {}

Player &Player::operator=(const Player &other)
{
	if (this != &other)
	{
		Object::operator=(other);
		this->direction = other.direction;
	}
	return *this;
}

const int& Player::getHp() const { return this->hp; }

const int& Player::getDirection() const { return this->direction; }

void Player::setDirection(int new_direction) { this->direction = new_direction; }

int Player::findNewDirection(int x_diff)
{
	if (x_diff == 1) return RIGHT;
	else return LEFT;
}

void Player::damage() {
	if (this->hp > 0)
		--this->hp;
}

void Player::walk(int y_diff, int x_diff)
{
	this->setDirection(this->findNewDirection(x_diff));
	this->y_pos += y_diff;
	this->x_pos += x_diff;
}