#include <iostream>

#include "../inc/Colors.hpp"
#include "../inc/Iter.hpp"

int main() {
  int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const double nums2[10] = {0.5, 1.4, 2.9, 3.8, 4.4, 5.1, 6.2, 7.3, 8.7, 9.9};

  std::cout << BOLD GREEN << "Non-Const:\n" << RESET;
  iter(nums, 10, increment<int>);
  iter(nums, 10, printData<int>);

  std::cout << BOLD GREEN << "\nConst:\n" << RESET;
  // iter(nums2, 10, increment<double>);
  iter(nums2, 10, printData<double>);

  return 0;
}
