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
  lookupInput();
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
      data[date] = std::strtod(value.c_str(), NULL);
  }
}

void BitcoinExchange::lookupInput() {
  std::ifstream infile(input_file);
  if (!infile.is_open())
    throw std::invalid_argument("Error: Unable to open input file");
  std::string line;
  std::getline(infile, line); // Skip header line
  while (std::getline(infile, line)) {

  }
}

