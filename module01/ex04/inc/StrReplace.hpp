#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class StrReplace {
 public:
  StrReplace();
  ~StrReplace();

  bool setInfile(char* filename);
  bool setStrings(char* to_find, char* to_insert);
  bool replace();

 private:
  int found;
  std::string infile;
  std::string outfile;
  std::string to_find;
  std::string to_insert;

  void replaceNewlineChar(std::string& s);
  void replaceOccurrences(std::string& s);
  void print_result();
};
