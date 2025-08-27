#include <iostream>
#include <string>
#include "../inc/whatever.hpp"
#include "../inc/Colors.hpp"

template <typename T>
void compareValues(T a, T b) {
  std::cout << "Original Values: " << "a=" << a << " b=" << b << "\n"
            << "min = " << ::min(a, b) << "\n"
            << "max = " << ::max(a, b) << "\n"; 
  ::swap(a, b);
  std::cout << "After swap: a=" << a << " b=" << b << "\n" << std::endl;
}


int main() {
  std::cout << GREEN BOLD << "Tests from subject pdf\n" << RESET;
  {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
  }
  
  std::cout << GREEN BOLD << "\nFurther Tests\n" << RESET;

  {
    std::cout << YELLOW << "Int:\n" << RESET;
    compareValues(5, 10);
    compareValues(5, 5);

    std::cout << YELLOW << "Long:\n" << RESET;
    compareValues(2147483648L, -2147483649L);
    compareValues(100, 100);

    std::cout << YELLOW << "Float:\n" << RESET;
    compareValues(10.5f, 2.5f);
    compareValues(100.256, 100.256);

    std::cout << YELLOW << "Double:\n" << RESET;
    compareValues(453534543534543534.5678, 9809807968756567.5678);
    compareValues(56874.321, 56874.321);

    std::cout << YELLOW << "Bool:\n" << RESET;
    std::cout << std::boolalpha;
    compareValues(true, false);
    compareValues(false, false);

    std::cout << YELLOW << "Char:\n" << RESET;
    compareValues('j', 'w');
    compareValues('f', 'f');

    std::cout << YELLOW << "String:\n" << RESET;
    compareValues(std::string("World!"), std::string("Hello, "));
    compareValues("Hello", "Hello");
  }
}
