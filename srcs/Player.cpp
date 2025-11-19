#include "../includes/Player.hpp"

Player::Player() :
	Object(),
	hp(3) {}

Player::Player(int y_pos, int x_pos) :
	Object(y_pos, x_pos),
	hp(3) {}

Player::~Player() {}

Player &Player::operator=(const Player &other)
{
	if (this != &other)
		Object::operator=(other);
	return *this;
}

const int &Player::getHp() const { return this->hp; }

void Player::damage() {
	if (this->hp > 0)
		--this->hp;
}