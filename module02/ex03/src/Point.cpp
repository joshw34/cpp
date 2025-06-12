#include "../inc/Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val)) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {
}

Point::~Point() {
}

Point& Point::operator=(const Point& src) {
	/* The only way to achieve this with const values:
	
	const_cast<Fixed&>(this->x) = src.x;
	const_cast<Fixed&>(this->y) = src.y;

	But using cons_cast to remove const is undefined behaviour */
	return *this;
}
