#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>  // IWYU pragma: keep
#include <iomanip>  // IWYU pragma: keep
#include <map>
#include <stdexcept>  // IWYU pragma: keep
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string&);
  BitcoinExchange(const BitcoinExchange&);
  ~BitcoinExchange();

  BitcoinExchange& operator=(const BitcoinExchange&);

  void run();

 private:
  BitcoinExchange();  // Private: should not be used
  std::map<std::string, double> data;
  std::string input_file;

  void loadDatabase();
  void lookupInput();
};
