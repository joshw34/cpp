#include "../inc/BitcoinExchange.hpp"

#include <iostream>

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
  processInputFile();
}

void BitcoinExchange::loadDatabase() {
  std::ifstream datafile("./data/data.csv");
  if (!datafile.is_open())
    throw std::runtime_error("Error: data.csv could not be opened.");
  std::string line;
  std::getline(datafile, line);  // Skip header line
  while (std::getline(datafile, line)) {
    size_t comma_pos = line.find_first_of(',', 0);
    std::string date = line.substr(0, comma_pos);
    std::string value = line.substr(comma_pos + 1);
    data[date] = std::strtod(value.c_str(), NULL);
  }
}

void BitcoinExchange::processInputFile() {
  std::ifstream infile(input_file.c_str());
  if (!infile.is_open())
    throw std::runtime_error("Error: Unable to open input file.");
  std::string line;
  std::getline(infile, line);  // Skip header line
  while (std::getline(infile, line)) processLine(line);
}

void BitcoinExchange::processLine(const std::string& line) {
  try {
    validateLineFormat(line);
    std::string date = validateDate(line);
    double amount = validateAmount(line);
    lookupValue(date, amount);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: bad input => " << line << "\n";
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << "\n";
  }
}

void BitcoinExchange::validateLineFormat(const std::string& line) {
  if (line.length() < 14 || line.at(10) != ' ' || line.at(11) != '|' ||
      line.at(12) != ' ' || line.substr(12).find_first_of("|") != line.npos)
    throw std::invalid_argument("");
}

std::string BitcoinExchange::validateDate(const std::string& line) {
  std::string date = line.substr(0, 10);
  for (size_t i = 0; i < date.size(); ++i) {
    if ((i == 4 || i == 7) && date.at(i) != '-')
      throw std::invalid_argument("");
    else if ((i != 4 && i != 7) && std::isdigit(date.at(i)) == 0)
      throw std::invalid_argument("");
  }
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());
  int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year < 1 || month < 1 || month > 12 || day < 1)
    throw std::invalid_argument("");
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    days_in_month[1] = 29;
  if (day > days_in_month[month - 1])
    throw std::invalid_argument("");
  return date;
}

double BitcoinExchange::validateAmount(const std::string& line) {
  char* end;
  double amount = std::strtod(line.substr(13).c_str(), &end);
  if (*end != '\0')
    throw std::invalid_argument("");
  if (amount < 0)
    throw std::out_of_range("Error: not a positive number.");
  if (amount > 1000)
    throw std::out_of_range("Error: too large a number.");
  return amount;
}

void BitcoinExchange::lookupValue(const std::string& date, const double& amount) const {
  std::map<std::string, double>::const_iterator it = data.upper_bound(date);
  if (it == data.begin())
    throw std::out_of_range("Error: date is too early.");
  if (it == data.end())
    throw std::out_of_range("Error: date is too late.");
  else
    --it;
  std::cout << date << " => " << amount << " = " << it->second * amount << "\n";
}
