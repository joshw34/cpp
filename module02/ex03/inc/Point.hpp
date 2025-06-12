#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x_val, const float y_val);
		Point(const Point& src);
		~Point();

		Point& operator=(const Point& src);

	private:
		const Fixed x;
		const Fixed y;
};

#endif
