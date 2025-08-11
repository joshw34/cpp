#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"
#include <iostream>

int main() {
    Data original("Josh", 35);
    Data* ptr_before = &original;
    uintptr_t serialized = Serializer::serialize(&original);
    Data* ptr_after = Serializer::deserialize(serialized);

    std::cout << original << "\n\n";

    std::cout << BOLD << "serialize(): " << RESET << serialized << "\n\n";

    if (ptr_before == ptr_after) { 
        std::cout << GREEN << "Returned Data* matches original:\n" << RESET
                  << *Serializer::deserialize(serialized) << std::endl;
    }
    else {
        std::cout << RED << "Pointers do not match:\n" << RESET
                  << "Original: " << ptr_before << "\n"
                  << "Deserialized: " << ptr_after << std::endl;
    }
}
