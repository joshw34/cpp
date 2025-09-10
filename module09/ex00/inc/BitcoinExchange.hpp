#pragma once

#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string& input);
  BitcoinExchange(const BitcoinExchange& src);

  BitcoinExchange& operator=(const BitcoinExchange& src);

  void run();

 private:
  BitcoinExchange();  // Private: should not be used
  std::map<std::string, double> data;
  std::string input_file;

  void loadData();

  bool dateIsValid(const std::string&);
  bool valueIsValid(const std::string&);
};
