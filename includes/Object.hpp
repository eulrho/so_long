#ifndef OBJECT_HPP
# define OBJECT_HPP

enum DIRECTION {
	LEFT, RIGHT, UP, DOWN
};

class Object {
	private:
		int	y_pos;
		int	x_pos;
		int	direction;

	public:
		Object();
		virtual	~Object();
		Object(int, int);

		Object			&operator=(const Object &);
		const int&		getYPos() const;
		const int&		getXPos() const;
		const int&		getDirection() const;

		void			setDirection(int);

		virtual int		findNewDirection(int, int);
		void        	walk(int, int);
};

#endif