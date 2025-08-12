#include <iomanip>

#include "../inc/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

static void print_result(const bool& result) {
  if (result == true)
    std::cout << GREEN;
  else if (result == false)
    std::cout << RED;
  std::cout << result << RESET << std::endl;
}

int main() {
  std::cout << std::boolalpha << std::setprecision(3);

  /*{
    Point a("a");
    Point b("b");
    Point c("c");
    Point point("point");
    bool result;

    std::cout << "a: " << a << "\n"
              << "b: " << b << "\n"
              << "c: " << c << "\n"
              << "point: " << point << std::endl;

    result = bsp(a, b, c, point);
    print_result(result);
  }*/

  {
    Point a(0.0f, 5.0f), b(-5.0f, -5.0f), c(5.0f, -5.0f);
    bool result;

    std::cout << "Triangle abc:" << a << " " << b << " " << c << std::endl;

    Point d(4.2f, -4.5f);
    std::cout << "\nPoint Inside triangle: " << d << std::endl;
    result = bsp(a, b, c, d);
    print_result(result);

    Point e(-0.6f, 1.8f);
    std::cout << "\nPoint Inside triangle: " << e << std::endl;
    result = bsp(a, b, c, e);
    print_result(result);

    Point f(-4.99f, -4.99f);
    std::cout << "\nPoint Inside triangle: " << f << std::endl;
    result = bsp(a, b, c, f);
    print_result(result);

    Point g(0.2, -2.6f);
    std::cout << "\nPoint Inside triangle: " << g << std::endl;
    result = bsp(a, b, c, g);
    print_result(result);

    Point h(-3.1f, -1.2f);
    std::cout << "\nPoint on edge ab: " << h << std::endl;
    result = bsp(a, b, c, h);
    print_result(result);

    Point i(1.3f, -5.0f);
    std::cout << "\nPoint on edge bc: " << i << std::endl;
    result = bsp(a, b, c, i);
    print_result(result);

    Point j(1.2f, 2.7f);
    std::cout << "\nPoint on edge ac: " << j << std::endl;
    result = bsp(a, b, c, j);
    print_result(result);

    Point k(-5.2f, 3.3f);
    std::cout << "\nPoint outside triangle: " << k << std::endl;
    result = bsp(a, b, c, k);
    print_result(result);

    Point l(7.5f, 4.8f);
    std::cout << "\nPoint outside triangle: " << l << std::endl;
    result = bsp(a, b, c, l);
    print_result(result);

    Point m(4.0f, -2.0f);
    std::cout << "\nPoint outside triangle: " << m << std::endl;
    result = bsp(a, b, c, m);
    print_result(result);

    Point n(-4.4f, -3.0f);
    std::cout << "\nPoint outside triangle: " << n << std::endl;
    result = bsp(a, b, c, n);
    print_result(result);
  }

  return 0;
}
