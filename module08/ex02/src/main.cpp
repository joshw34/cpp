#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "../inc/Colors.hpp"
#include "../inc/MutantStack.hpp"

int main() {
  // Subject PDF Test
  {
    std::cout << BOLD BLUE "\n*** Subject PDF Test ***" RESET "\n";

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top after pushing 5, 17: " << mstack.top() << "\n";
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << "\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << GREEN "Iteration through MutantStack:" RESET "\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << "\n";
      ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "Successfully copied to std::stack, size: " << s.size() << "\n";
  }

  // Subject PDF Test - List Comparison
  {
    std::cout << BOLD BLUE "\n*** Subject PDF Test - List Comparison ***" RESET "\n";

    // Same operations with std::list to verify similar output
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "List back after pushing 5, 17: " << lst.back() << "\n";
    lst.pop_back();
    std::cout << "List size after pop: " << lst.size() << "\n";
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << GREEN "Iteration through std::list:" RESET "\n";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
      std::cout << *it << "\n";
    }
  }

  // Subject PDF Test - Vector Comparison
  {
    std::cout << BOLD BLUE "\n*** Subject PDF Test - Vector Comparison ***" RESET "\n";

    // Same operations with std::vector to verify similar output
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << "Vector back after pushing 5, 17: " << vec.back() << "\n";
    vec.pop_back();
    std::cout << "Vector size after pop: " << vec.size() << "\n";
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);

    std::cout << GREEN "Iteration through std::vector:" RESET "\n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
      std::cout << *it << "\n";
    }
  }

  // Basic Stack Operations Test
  {
    std::cout << BOLD BLUE "\n*** Basic Stack Operations Test ***" RESET "\n";

    MutantStack<int> mstack;

    // Test push and size
    std::cout << GREEN "Testing push() and size():" RESET "\n";
    for (int i = 1; i <= 5; ++i) {
      mstack.push(i);
      std::cout << "Pushed " << i << ", size: " << mstack.size() << "\n";
    }

    // Test top and pop
    std::cout << GREEN "\nTesting top() and pop():" RESET "\n";
    while (!mstack.empty()) {
      std::cout << "Top: " << mstack.top() << ", size: " << mstack.size() << "\n";
      mstack.pop();
    }

    std::cout << "Stack is now empty: " << (mstack.empty() ? "true" : "false") << "\n";
  }

  // Iterator Tests (Use std::list<int> as container)
  {
    std::cout << BOLD BLUE "\n*** Iterator Tests ***" RESET "\n";

    MutantStack<int, std::list<int> > mstack;

    // Fill with test data
    for (int i = 1; i <= 5; ++i) {
      mstack.push(i);
    }

    std::cout << GREEN "Forward iteration (bottom to top):" RESET "\n";
    for (MutantStack<int, std::list<int> >::iterator it = mstack.begin(); it != mstack.end(); ++it) {
      std::cout << *it << "\n";
    }

    std::cout << GREEN "\nReverse iteration (top to bottom - logical stack order):" RESET "\n";
    for (MutantStack<int, std::list<int> >::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
      std::cout << *rit << "\n";
    }
  }

  // Const Iterator Tests (Use std::vector<int> as container)
  {
    std::cout << BOLD BLUE "\n*** Const Iterator Tests ***" RESET "\n";

    MutantStack<int, std::vector<int> > mstack;
    for (int i = 10; i <= 30; i += 10) {
      mstack.push(i);
    }

    const MutantStack<int, std::vector<int> >& const_ref = mstack;

    std::cout << GREEN "Const forward iteration:" RESET "\n";
    for (MutantStack<int, std::vector<int> >::const_iterator it = const_ref.begin(); it != const_ref.end(); ++it) {
      std::cout << *it << "\n";
    }

    std::cout << GREEN "\nConst reverse iteration:" RESET "\n";
    for (MutantStack<int, std::vector<int> >::const_reverse_iterator rit = const_ref.rbegin(); rit != const_ref.rend(); ++rit) {
      std::cout << *rit << "\n";
    }
  }

  // Copy to std::stack Test
  {
    std::cout << BOLD BLUE "\n*** Copy to std::stack Test ***" RESET "\n";

    MutantStack<int> mstack;
    for (int i = 100; i <= 300; i += 100) {
      mstack.push(i);
    }

    // Test copy construction to std::stack
    std::stack<int> regular_stack(mstack);

    std::cout << GREEN "Original MutantStack size: " RESET << mstack.size() << "\n";
    std::cout << GREEN "Copied std::stack size: " RESET << regular_stack.size() << "\n";

    std::cout << GREEN "\nComparing contents (should be identical):" RESET "\n";
    while (!mstack.empty() && !regular_stack.empty()) {
      std::cout << "MutantStack top: " << mstack.top() << ", std::stack top: " << regular_stack.top();
      if (mstack.top() == regular_stack.top()) {
        std::cout << GREEN " ✓" RESET "\n";
      } else {
        std::cout << RED " ✗" RESET "\n";
      }
      mstack.pop();
      regular_stack.pop();
    }
  }

  return 0;
}
