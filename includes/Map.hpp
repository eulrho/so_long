#ifndef MAP_HPP
# define MAP_HPP

# include <fstream>
# include <vector>
# include <string>

using namespace std;

// error codes
# define VALID 0
# define FILE_NAME 1
# define INVALID_FILE 2
# define INVALID_MAP 3
# define INVALID_PATH 4
# define MAP_SIZE 5

class Map {
	private:
        vector<string>  contents;
        size_t          y_size;
        size_t          x_size;
        int             start_y;
        int             start_x;
		int 			monster_start_y;
		int 			monster_start_x;
        int             collection_cnt;

		const char*		getErrorMessage(int) const;

		class InvalidMapException : public exception {
			private:
				const char* message;
			public:
				InvalidMapException(const char* message) : message(message) {};
				const char* what() const throw();
		};
	public:
		Map();
		~Map();
        Map(const string&);
        Map(const Map&);
        Map                     &operator=(const Map&);
        void                    setStartY(int);
        void                    setStartX(int);
		void                    setMonsterStartY(int);
		void                    setMonsterStartX(int);
        void                    addCollectionCnt();
        void                    subCollectionCnt(int, int);

		const vector<string>&   getContents() const;
        const size_t&           getYSize() const;
        const size_t&           getXSize() const;
        const int&              getCollectionCnt() const;
        const int&              getStartY() const;
        const int&              getStartX() const;
		const int&              getMonsterStartY() const;
		const int&              getMonsterStartX() const;

		bool                    isEqualChar(int, int, char);
        void			        isValidFile(ifstream&, const string&);
        void		        	isValidMapConfig(int, int, int&, int&, int&);
        void		        	isValidConfigCount(const int&, const int&, const int&);
        void		        	isValidRectangle(int);
        void		        	isValidMap();
        bool                    checkReached(int**);
        void			        isValidPath();
        vector<string>	        readMap(const string&);
		void			        find(int**, int, int);
};

#endif