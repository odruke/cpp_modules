#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += deposit;

	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();

	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;

	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();

	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;

	Account::_nbAccounts--;

	return;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
    std::tm*  t    = std::localtime(&now);

    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", t);
    std::cout << "[" << buf << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout
		<< "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();

	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
		Account::_displayTimestamp();

		std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "deposit:" << deposit << ";";

		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;

		std::cout
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
		Account::_displayTimestamp();

		std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";";


		if (Account::checkAmount() >= withdrawal){
			this->_amount -= withdrawal;
			this->_nbWithdrawals++;
			Account::_totalNbWithdrawals++;
			Account::_totalAmount -= withdrawal;

			std::cout
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
			return true;
		}
		std::cout << "withdrawal:refused" << std::endl;
		return false;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}
