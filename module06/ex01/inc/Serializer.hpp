#pragma once

#include <stdint.h>

#include "Colors.hpp"  // IWYU pragma: keep
#include "Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
};
