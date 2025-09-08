#pragma once

#include <cstdlib>
#include <deque>
#include <algorithm>

template <typename T>
class MutantStack {
 public:
  MutantStack() {};
  MutantStack(const MutantStack& src) : data(src.data) {};
  ~MutantStack() {};

  MutantStack& operator=(const MutantStack& src) {
    if (this != &src) {
      this->data = src.data;
    }
    return *this;
  }

  // Element Access
  const T& top() const {
    return data.back();
  }

  // Capacity
  bool empty() const {
    return data.empty();
  }

  size_t size() const {
    return data.size();
  }

  // Modifiers
  void push(const T& element) {
    data.push_back(element);
  }

  template<typename Container>
  void push_range(const Container& cont) {
    data.insert(data.end(), cont.begin(), cont.end());
  }

  void pop() {
    data.pop_back();
  }

  void swap(MutantStack<T> other) {
    std::swap(this->data, other.data); 
  }

  // Iterators
  typedef typename std::deque<T>::iterator reverse_iterator;
  typedef typename std::deque<T>::const_iterator const_reverse_iterator;
  typedef typename std::deque<T>::reverse_iterator iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_iterator;

  iterator begin() {
    return data.rbegin();
  }

  iterator end() {
    return data.rend();
  }

  const_iterator cbegin() const {
    return data.rbegin();
  }

  const_iterator cend() const {
    return data.rend();
  }

  reverse_iterator rbegin() {
    return data.begin();
  }

  reverse_iterator rend() {
    return data.end();
  }

  const_reverse_iterator crbegin() const {
    return data.begin();
  }

  const_reverse_iterator crend() const {
    return data.end();
  }

  // Getters
  const std::deque<int>& getData() const {
    return data;
  }

 private:
  std::deque<T> data;
};

template <typename T>
bool operator==(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() == rhs.getData();
}

template <typename T>
bool operator!=(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() != rhs.getData();
}

template <typename T>
bool operator<(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() < rhs.getData();
}

template <typename T>
bool operator<=(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() <= rhs.getData();
}

template <typename T>
bool operator>(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() > rhs.getData();
}

template <typename T>
bool operator>=(const MutantStack<T>& lhs, const MutantStack<T>& rhs) {
  return lhs.getData() >= rhs.getData();
}



