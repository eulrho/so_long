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

int Monster::findNewDirection(int y_diff, int x_diff)
{
	if (x_diff == 1 && y_diff == 0) return RIGHT;
	else if (x_diff == -1 && y_diff == 0) return LEFT;
	else if (x_diff == 0 && y_diff == 1) return DOWN;
	else return UP;
}

bool Monster::isEmptyPath() { return this->path.empty(); }

void Monster::moveByPath()
{
	int y_diff = this->path.top().first - this->getYPos();
	int x_diff = this->path.top().second - this->getXPos();
	this->walk(y_diff, x_diff);
	this->path.pop();
}