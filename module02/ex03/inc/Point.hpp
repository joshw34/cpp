#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <sstream>
#include <limits>
#include "Fixed.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Point {
	public:
		Point();
		Point(const float x_val, const float y_val);
		Point(const Point& src);
		Point(const std::string& name);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;

		Point& operator=(const Point&);

	private:
		const Fixed x;
		const Fixed y;
		static float userInput(const std::string& name, const char& type);
		static bool checkFixedRange(const float& input);
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif
