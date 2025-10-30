#ifndef MAP_HPP
# define MAP_HPP

# include <fstream>
# include <vector>
# include <string>

using namespace std;

// error codes
# define VALID 1
# define OTHER_CHARACTERS 2
# define MEMORY 3
# define FILE_NAME 4
// # define STANDARD_INPUT 5
# define INVALID_FILE 6
# define INVALID_MAP 7
# define INVALID_PATH 8
# define MAP_SIZE 9
# define OVER_FLOW 10

class Map {
	private:
        vector<string>  contents;
        size_t          y_size;
        size_t          x_size;
        int             start_y;
        int             start_x;
        int             collection_cnt;
		
	public:
		Map();
		~Map();
        Map(const string&);
        Map(const Map&);
        Map                     &operator=(const Map&);
        void                    setStartY(int);
        void                    setStartX(int);
        void                    addCollectionCnt();
        void                    subCollectionCnt(int, int);

		const vector<string>&   getContents() const;
        const size_t            getYSize() const;
        const size_t            getXSize() const;
        const int               getCollectionCnt() const;
        const int               getStartY() const;
        const int               getStartX() const;

		bool                    isEqualChar(int, int, char);
        void			        isValidFile(ifstream&, const string&);
        void		        	isValidMapConfig(int, int, int&, int&);
        void		        	isValidConfigCount(const int&, const int&);
        void		        	isValidRectangle(int);
        void		        	isValidMap();
        bool                    checkReached(int**);
        void			        isValidPath();
        vector<string>	        readMap(const string&);
        void			        printError(int);
		void			        find(int**, int, int);
};

#endif