#pragma once

#include <climits>
#include <cstdlib>
#include <iostream>
#include <limits>   // IWYU pragma: keep
#include <sstream>  // IWYU pragma: keep
#include <string>

#include "Colors.hpp"  // IWYU pragma: keep
#include "Fixed.hpp"

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
