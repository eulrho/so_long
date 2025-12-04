#ifndef OBJECT_HPP
# define OBJECT_HPP

class Object {
	protected:
		int	y_pos;
		int	x_pos;

	public:
		Object();
		virtual	~Object();
		Object(int, int);

		Object			&operator=(const Object &);
		const int&		getYPos() const;
		const int&		getXPos() const;

		virtual void    walk(int, int);
};

#endif