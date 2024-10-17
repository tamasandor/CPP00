/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:54:25 by atamas            #+#    #+#             */
/*   Updated: 2024/10/17 15:34:52 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int	initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << '\n';
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << '\n';
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << '\n';
	return ;
}

void	Account::makeDeposit( int deposit )
{
	int	pre_amount;

	pre_amount = _amount;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << pre_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
	return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	int	pre_amount;

	pre_amount = _amount;
	_displayTimestamp();
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals += 1;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		std::cout << "index:" << _accountIndex << ";p_amount:" << pre_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
		
		return (true);
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << pre_amount << ";withdrawal:refused\n";
	return (false);
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
	return ;
}

void	Account::_displayTimestamp( void )
{
	time_t	timestamp;

	timestamp = time(NULL);
	struct tm *dateTime = localtime(&timestamp);
	std::cout << '[' << dateTime->tm_year + 1900 << dateTime->tm_mon + 1 << dateTime->tm_mday << '_' << dateTime->tm_hour << dateTime->tm_min << dateTime->tm_sec << "] ";

	return ;
}
