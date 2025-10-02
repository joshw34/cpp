#pragma once

#include <cstdlib>
#include <fstream>  // IWYU pragma: keep
#include <map>
#include <stdexcept>  // IWYU pragma: keep
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string&);
  ~BitcoinExchange();

  void run();

 private:
  BitcoinExchange();  // Private: should not be used
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  std::map<std::string, double> data;
  std::string input_file;

  void loadDatabase();
  void processInputFile();
  void processLine(const std::string&);
  void validateLineFormat(const std::string&);
  std::string validateDate(const std::string&);
  double validateAmount(const std::string&);
  void lookupValue(const std::string&, const double&) const;
};
