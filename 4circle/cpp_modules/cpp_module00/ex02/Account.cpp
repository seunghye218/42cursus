/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:34:26 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/28 17:22:50 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
	this->_accountIndex = getNbAccounts();
	++_nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout 
		<< " index:" << this->_accountIndex << ";amount:" 
		<< initial_deposit << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout 
		<< " index:" << this->_accountIndex << ";amount:" 
		<< this->_amount << ";closed\n";
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:"<< getNbWithdrawals()
	<< std::endl;

}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" <<  this->_amount
		<< ";deposit:" << deposit;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	++(this->_nbDeposits);
	++Account::_totalNbDeposits;
	std::cout
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" <<  this->_amount
		<< ";withdrawal:";
	if (checkAmount() - withdrawal < 0)
	{
		std::cout << "refused\n";
		return false;
	}
	++Account::_totalNbWithdrawals;
	++(this->_nbWithdrawals);
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout
		<< withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	return true;
}

int	Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex
		<< ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	char		buffer[20];
	struct tm	*timeinfo;
	time_t		rawtime;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 100, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}
