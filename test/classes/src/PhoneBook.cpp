#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	if (this->total < 8)
		this->index = this->total + 1;
	else
		this->index = 0;

}
