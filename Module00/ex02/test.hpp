#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}


bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (Account::checkAmount() >= withdrawal)
		this->_amount -= withdrawal;
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";  
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    time_t		timet;

    std::time(&timet);
    std::cout << "[";
	std::cout << std::put_time(localtime(&timet), "%Y%m%d_%H%M%S") << "] ";
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

int  Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}
int  Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}
int  Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}
int  Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}
