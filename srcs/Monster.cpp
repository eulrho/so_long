#include "../includes/Monster.hpp"

Monster::Monster() :
	Object() {}

Monster::Monster(int y_pos, int x_pos) :
	Object(y_pos, x_pos) {}

Monster::~Monster() {}

Monster &Monster::operator=(const Monster &other)
{
	if (this != &other)
		Object::operator=(other);
	return *this;
}

bool Monster::isEmptyPath() { return this->path.empty(); }

void Monster::moveByPath()
{
	int y_diff = this->path.top().first - this->y_pos;
	int x_diff = this->path.top().second - this->x_pos;
	this->walk(y_diff, x_diff);
	this->path.pop();
}