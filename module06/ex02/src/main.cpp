#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include "../inc/Colors.hpp"

static void printResult(char c) {
  std::cout << c << std::endl;
}

static void identify(Base& p) {
  try {
    A& a_ref = dynamic_cast<A&>(p);
    (void)a_ref;
    return printResult('A');
  } catch (std::exception& e) {}
  try {
    B& b_ref = dynamic_cast<B&>(p);
    (void)b_ref;
    return printResult('B');
  } catch (std::exception& e) {}
  try {
    C& c_ref = dynamic_cast<C&>(p);
    (void)c_ref;
    return printResult('C');
  } catch (std::exception& e) {}
}

static void identify(Base* p) {
  A* a_ptr = dynamic_cast<A*>(p);
  if (a_ptr)
    return printResult('A');
  B* b_ptr = dynamic_cast<B*>(p);
  if (b_ptr)
    return printResult('B');
  C* c_ptr = dynamic_cast<C*>(p);
  if (c_ptr)
    return printResult('C');
}

static Base* generate() {
  switch (rand() % 3) {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      return new C;
  }
  throw std::logic_error("Unexpected Random Value");
}

int main() {
  std::srand(std::time(0));
  {
    std::cout << BOLD << "Known Object Types:\n" << RESET;
    A a_test;
    B b_test;
    C c_test;
    identify(&a_test);
    identify(a_test);
    identify(&b_test);
    identify(b_test);
    identify(&c_test);
    identify(c_test);
  }
  std::cout << "\n\n";
  {
    std::cout << BOLD << "Random Objects:\n" << RESET;
    for (size_t i = 0; i < 15; i++) {
      std::cout << "---" << "Test " << i + 1 << "---\n";
      Base* ptr = generate();
      identify(ptr);
      identify(*ptr);
      delete ptr;
    }
  }
}
