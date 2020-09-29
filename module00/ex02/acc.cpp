#include "acc.hpp"
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit ) : _amount(initial_deposit) , _nbDeposits(0) , _nbWithdrawals(0), _accountIndex(Account::_nbAccounts)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created"
    << std::endl;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed"  
    << std::endl;
}

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals
    << std::endl;
}


void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";pamount:" << this->_amount << ";deposit:" << deposit;  
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits ++;
    std::cout << ";amout:" << this->_amount << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";pamount:";
    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals ++;
    std::cout << ";withdrawal:" << withdrawal << ";amout:" << this->_amount << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
    return true;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << _amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals
    << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[timestamp] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account( void ){
}
