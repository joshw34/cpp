#include <iostream>

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}  // Private

BitcoinExchange::BitcoinExchange(const std::string& input)
    : input_file(input) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
    : data(src.data), input_file(src.input_file) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
  if (this != &src) {
    this->data = src.data;
    this->input_file = src.input_file;
  }
  return *this;
}

void BitcoinExchange::run() {
  loadData();
}

void BitcoinExchange::loadData() {
  std::ifstream datafile("./data/data.csv");
  if (!datafile.is_open())
    throw std::invalid_argument("Error: data.csv could not be opened");
  std::string line;
  char* end;
  std::getline(datafile, line);  // Skip header line
  while (std::getline(datafile, line)) {
    size_t comma_pos = line.find_first_of(',', 0);
    std::string date = line.substr(0, comma_pos);
    std::string value = line.substr(comma_pos + 1);
    if (dateIsValid(date) && valueIsValid(value))
      data[date] = std::strtod(value.c_str(), &end);
  }
}

bool BitcoinExchange::dateIsValid(const std::string& date) {
  if (date.length() != 10 || date.find_first_not_of("1234567890-") != date.npos
    || date.at(4) != '-' || date.at(7) != '-')
    return false;

  int year = std::atoi(date.substr(0, 4).c_str()); 
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  
  if (year < 0 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 4 == 0 && (year % 100 !=0 || year % 400 == 0))
    daysInMonth[1] = 29;
  if (day > daysInMonth[month - 1])
    return false;
  return true;
}
