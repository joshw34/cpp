#include <iostream>

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}  // Private

BitcoinExchange::BitcoinExchange(const std::string& input)
    : input_file(input) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
    : data(src.data), input_file(src.input_file) {}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
  if (this != &src) {
    this->data = src.data;
    this->input_file = src.input_file;
  }
  return *this;
}

void BitcoinExchange::run() {
  loadDatabase();
  std::cout << std::fixed << std::setprecision(2);
  for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it) {
    std::cout << it->first << " " << it->second << "\n";
  }
  std::cout << data.size() << std::endl;
}

void BitcoinExchange::loadDatabase() {
  std::ifstream datafile("./data/data.csv");
  if (!datafile.is_open())
    throw std::invalid_argument("Error: data.csv could not be opened");
  std::string line;
  std::getline(datafile, line);  // Skip header line
  while (std::getline(datafile, line)) {
    size_t comma_pos = line.find_first_of(',', 0);
    std::string date = line.substr(0, comma_pos);
    std::string value = line.substr(comma_pos + 1);
    if (dateIsValid(date) && valueIsValid(value))
      data[date] = std::strtod(value.c_str(), NULL);
    else
      std::cout << "Error: Invalid Date in data.csv: " << line << std::endl;
  }
}

bool BitcoinExchange::dateIsValid(const std::string& date) {
  if (date.length() != 10 || date.find_first_not_of("1234567890-") != date.npos
    || date.at(4) != '-' || date.at(7) != '-')
    return false;
  int year = std::atoi(date.substr(0, 4).c_str()); 
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  time_t now = std::time(0);
  tm* timeinfo = localtime(&now);
  int year_today = timeinfo->tm_year + 1900;
  int month_today = timeinfo->tm_mon + 1;
  int day_today = timeinfo->tm_mday;
  if (year < 0 || year > year_today || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 4 == 0 && (year % 100 !=0 || year % 400 == 0))
    daysInMonth[1] = 29;
  if (day > daysInMonth[month - 1])
    return false;
  if (year == year_today) {
    if (month > month_today)
      return false;
    else if (month == month_today && day > day_today)
      return false;
  }
  return true;
}

bool BitcoinExchange::valueIsValid(const std::string& value) {
  if (value.empty())
    return false;
  char* end;
  double check = std::strtod(value.c_str(), &end);
  if (!*end && check >= 0)
    return true;
  return false;
}
