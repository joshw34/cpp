#include "../inc/MutantStack.hpp"
#include <iostream>
#include <stack>

int main() {
  MutantStack<int> mut;
  std::stack<int> stk;

  for (int i = 0; i < 10; ++i) {
    mut.push(i + 1);
    stk.push(i + 1);
  }
  
  std::cout << std::boolalpha;

  for (MutantStack<int>::iterator it = mut.begin(); it != mut.end(); ++it) {
    std::cout << *it << "\n";
  }

  return 0;
}
