#include <iostream>
#include "../includes/Player.hpp"

Player::Player() :
    y_pos(0),
    x_pos(0),
    foot_print(0) {}

Player::~Player() {}

Player::Player(int new_y_pos, int new_x_pos) :
    y_pos(new_y_pos),
    x_pos(new_x_pos),
    foot_print(0) {}

Player &Player::operator=(const Player &other)
{
	if (this != &other) {
		this->y_pos = other.y_pos;
		this->x_pos = other.x_pos;
		this->foot_print = other.foot_print;
	}
	return *this;
}

void Player::XMove(int diff) { this->x_pos += diff; }

void Player::YMove(int diff) { this->y_pos += diff; }

void Player::move() {
    this->foot_print++;
    cout << "moves : " << this->foot_print << '\n';
}

const int& Player::getYPos() const { return this->y_pos; }

const int& Player::getXPos() const { return this->x_pos; }