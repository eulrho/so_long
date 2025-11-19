#include <iostream>
#include "../includes/Map.hpp"

Map::Map() :
    y_size(0),
    x_size(0),
    start_y(-1),
    start_x(-1),
	monster_start_y(-1),
	monster_start_x(-1),
    collection_cnt(0) {}

Map::~Map() {}

Map::Map(const string& map_file) :
    start_y(-1),
    start_x(-1),
	monster_start_y(-1),
	monster_start_x(-1),
    collection_cnt(0)
{
    this->contents = this->readMap(map_file);
    this->y_size = this->contents.size();
    this->x_size = this->contents[0].size();
}
 
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
		this->monster_start_y = other.monster_start_y;
		this->monster_start_x = other.monster_start_x;
	}
	return *this;
}

void Map::setStartY(int new_start_y) { this->start_y = new_start_y; }

void Map::setStartX(int new_start_x) { this->start_x = new_start_x; }

void Map::setMonsterStartY(int new_monster_start_y) { this->monster_start_y = new_monster_start_y; }

void Map::setMonsterStartX(int new_monster_start_x) { this->monster_start_x = new_monster_start_x; }

void Map::addCollectionCnt() { this->collection_cnt++; }

void Map::subCollectionCnt(int y, int x) {
    if (this->collection_cnt > 0) this->collection_cnt--;
    this->contents[y][x] = '0';
}

const vector<string>& Map::getContents() const { return this->contents; }

const size_t& Map::getYSize() const { return this->y_size; }

const size_t& Map::getXSize() const { return this->x_size; }

const int& Map::getCollectionCnt() const { return this->collection_cnt; }

const int& Map::getStartY() const { return this->start_y; }

const int& Map::getStartX() const { return this->start_x; }

const int& Map::getMonsterStartY() const { return this->monster_start_y; }

const int& Map::getMonsterStartX() const { return this->monster_start_x; }

bool Map::isEqualChar(int y, int x, char ch) {
    return this->contents[y][x] == ch;
}

vector<string>	Map::readMap(const string &map_file)
{
	ifstream file(map_file);
	this->isValidFile(file, map_file);
    
	vector<string> result;
	string line;
	while (getline(file, line))
	{
		if (line.empty())
			throw InvalidMapException(this->getErrorMessage(INVALID_MAP));
		result.push_back(line);
	}
	if (result.empty())
		throw InvalidMapException(this->getErrorMessage(INVALID_FILE));
	file.close();
	return result;
}