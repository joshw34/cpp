#pragma once

#include <stdexcept>
#include <ostream>

template <typename T>
class Array {
  public:
    Array() : array_data(0), array_size(0) {}
    Array(const unsigned int n) : array_data(n > 0 ? new T[n]() : 0), array_size(n) {}
    Array(const Array& src) : array_data(getArrayCopy(src)), array_size(src.size()) {}
    ~Array() { if (array_data) delete[] array_data; }

    Array& operator=(const Array& src) {
      if (this != &src) {
        this->array_size = src.size();
        if (this->array_data)
          delete[] this->array_data;
        this->array_data = getArrayCopy(src);
      };
      return *this;
    }

    T& operator[](const unsigned int index) const {
      if (array_size == 0 || index >= array_size)
        throw std::out_of_range("Error: Index Out of Range");
      return this->array_data[index];
    }

    unsigned int size() const {
      return this->array_size;
    }

  private:
    T* array_data;
    unsigned int array_size;

    T* getArrayCopy(const Array& src) {
      if (src.size() == 0)
        return 0;
      T* result = new T[src.size()]();
      for (unsigned int i = 0; i < src.size(); ++i) {
          result[i] = src[i];             
      }
      return result;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& arr) {
  if (arr.size() > 0) {
    for (size_t i = 0; i < arr.size(); ++i) {
      try {
         os << arr[i] << "\n";
      } catch (std::exception& e) {
        break;
      }
    }
  }
  return os;
}
