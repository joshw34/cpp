#include "../inc/Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::setName(std::string name) {
	this->name = name;
}

std::string	Contact::getName() const {
	return this->name;
}

void	Contact::setLast(std::string last) {
	this->last = last;
}

std::string	Contact::getLast() const {
	return this->last;
}

void	Contact::setNick(std::string nick) {
	this->nick = nick;
}

std::string	Contact::getNick() const {
	return this->nick;
}

void	Contact::setPhone(std::string phone) {
	this->phone = phone;
}

std::string	Contact::getPhone() const {
	return this->phone;
}

void	Contact::setSecret(std::string secret) {
	this->secret = secret;
}

std::string	Contact::getSecret() const {
	return this->secret;
}
