#include "../includes/Object.hpp"

Object::Object() :
    y_pos(-1),
    x_pos(-1) {}

Object::Object(int y_pos, int x_pos) :
	y_pos(y_pos),
	x_pos(x_pos) {}

Object::~Object() {}

Object &Object::operator=(const Object &other)
{
	if (this != &other) {
		this->y_pos = other.y_pos;
		this->x_pos = other.x_pos;
	}
	return *this;
}

void Object::walk(int y_diff, int x_diff)
{
	this->y_pos += y_diff;
	this->x_pos += x_diff;
}

const int& Object::getYPos() const { return this->y_pos; }

const int& Object::getXPos() const { return this->x_pos; }