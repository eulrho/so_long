#ifndef MAP_HPP
# define MAP_HPP

# include <vector>
# include <string>

using namespace std;

class Map {
	private:
        vector<string> contents;
        size_t	y_size;
        size_t	x_size;
        int		start_y;
        int		start_x;
        int		collection_cnt;
		
	public:
		Map();
		~Map();
        Map(vector<string>&);
        Map(const Map&);
        Map &operator=(const Map&);
        void setStartY(int);
        void setStartX(int);
        void addCollectionCnt();
        void subCollectionCnt(int, int);

		const vector<string>& getContents() const;
        const size_t getYSize() const;
        const size_t getXSize() const;
        const int getCollectionCnt() const;
        const int getStartY() const;
        const int getStartX() const;

		bool isEqualChar(int, int, char);
};

#endif