#include <iostream>
#include "../includes/Map.hpp"

Map::Map() :
    y_size(0),
    x_size(0),
    start_y(0),
    start_x(0),
    collection_cnt(0) {}

Map::~Map() {}

Map::Map(vector<string> &new_contents) :
    contents(new_contents),
    y_size(new_contents.size()),
    x_size(new_contents[0].size()),
    start_y(0),
    start_x(0),
    collection_cnt(0) {}
 
Map::Map(const Map &new_map) {
    *this = new_map;
}

Map &Map::operator=(const Map &other) {
    if (this != &other) {
		this->contents = other.contents;
		this->y_size = other.y_size;
		this->x_size = other.x_size;
		this->start_y = other.start_y;
        this->start_x = other.start_x;
        this->collection_cnt = other.collection_cnt;
	}
	return *this;
}

void Map::setStartY(int new_start_y) { this->start_y = new_start_y; }

void Map::setStartX(int new_start_x) { this->start_x = new_start_x; }

void Map::addCollectionCnt() { this->collection_cnt++; }

void Map::subCollectionCnt(int y, int x) {
    if (this->collection_cnt > 0) this->collection_cnt--;
    this->contents[y][x] = '0';
}

const vector<string>& Map::getContents() const { return this->contents; }

const size_t Map::getYSize() const { return this->y_size; }

const size_t Map::getXSize() const { return this->x_size; }

const int Map::getCollectionCnt() const { return this->collection_cnt; }

const int Map::getStartY() const { return this->start_y; }

const int Map::getStartX() const { return this->start_x; }

bool Map::isEqualChar(int y, int x, char ch) {
    return this->contents[y][x] == ch;
}