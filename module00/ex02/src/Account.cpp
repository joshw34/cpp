#include "../inc/Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 1;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

int		Account::getNbAccounts() {
	return _nbAccounts;
}

int		Account::getTotalAmount() {
	return _totalAmount;
}

int		Account::getNbDeposits() {
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:";
	if (checkAmount() - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount() const {
	return _amount;
}

void	Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp() {
	std::time_t	timestamp = time(NULL);
	struct tm	timedata = *localtime(&timestamp);

	std::cout	<< "["
				<< timedata.tm_year + 1900
				<< std::setfill('0') << std::setw(2) << timedata.tm_mon + 1
				<< std::setfill('0') << std::setw(2) << timedata.tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2) << timedata.tm_hour 
				<< std::setfill('0') << std::setw(2) << timedata.tm_min
				<< std::setfill('0') << std::setw(2) << timedata.tm_sec
				<< "]" ;
}
