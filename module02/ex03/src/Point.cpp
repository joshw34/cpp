#include "../inc/Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val)) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {
}

Point::Point(const std::string& name) : x(userInput(name, 'x')), y(userInput(name, 'y')) {
	system("clear");
}

Point::~Point() {
}

const Fixed& Point::getX() const {
	return this->x;
}

const Fixed& Point::getY() const {
	return this->y;
}

Point& Point::operator=(const Point&) {
	/* The only way to achieve this with const values:
	
	const_cast<Fixed&>(this->x) = src.x;
	const_cast<Fixed&>(this->y) = src.y;

	But using cons_cast to remove const is undefined behaviour */
	return *this;
}

float Point::userInput(const std::string& name, const char& type) {
	std::string input;
	double coord;

	while (true) {
		std::cout << GREEN << "Enter " << type << " coordinate for " << name << RESET << std::endl; 

		std::cin >> input;

		if (input.find_first_not_of("1234567890.+-") != input.npos) {
			std::cerr << RED << "Invalid characters in input" << RESET << std::endl;
			continue;
		}

		std::istringstream input_stream(input);
		if (input_stream >> coord && input_stream.eof()) {
			if (std::isfinite(static_cast<float>(coord)) && checkFixedRange(coord))
				break;
			std::cerr << RED << "Number out of range for Fixed Point class" << RESET << std::endl;
		}
		else
			std::cerr << RED << "Invalid Number Format" << RESET << std::endl;
	}
	return static_cast<float>(coord);
}

bool Point::checkFixedRange(const float& input) {
	static float high = 0.0f;
	static float low = 0.0f;

	if (high == low) {
		Fixed max;
		Fixed min;
		max.setRawBits(INT_MAX);
		min.setRawBits(INT_MIN);
		high = max.toFloat();
		low = min.toFloat();
	}

	return (input >= low && input <= high);
}

/* Works with Fixed << overload to printf Fixed toFloat() values */
std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}
