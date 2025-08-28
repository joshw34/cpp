#include <iostream>

template <typename T, int size>
class Container {
  public:
    Container() {
      m_data = new T[size];
    }
    ~Container() {
      delete[] m_data;
    }
    
  private:
    T* m_data;

};

int main() {
  Container<int, 10> c;
  Container<double, 10> c2;
  Container<float, 10> c3;

  return 0;
}
