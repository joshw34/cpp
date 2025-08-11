#include "../inc/Data.hpp"

Data::Data() : name("default_name"), age(0) {}

Data::Data(const std::string& name, const int age) : name(name), age(age) {}

Data::Data(const Data& src) : name(src.name),  age(src.age) {}

Data::~Data() {}

Data& Data::operator=(const Data& src) {
    if (this != &src) {
        this->name = src.name;
        this->age = src.age;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << BOLD << "Name: " << RESET << data.name
       << BOLD << "\nAge: " << RESET << data.age
       << BOLD << "\nData*: " << RESET << &data;
    return os;
}
