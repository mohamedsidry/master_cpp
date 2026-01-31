/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:52:06 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:54:16 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
_accountIndex(Account::getNbAccounts()),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
    Account::_displayTimestamp();
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    std::cout << "index:" << _accountIndex << ";" << std::flush;
    std::cout << "amount:" << _amount << ";" << std::flush;
    std::cout << "created" <<std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= _amount;
    std::cout << "index:" << _accountIndex << ";" << std::flush;
    std::cout << "amount:" << _amount << ";" << std::flush;
    std::cout << "closed" <<std::endl;
}

void Account::makeDeposit(int deposit)
{
    if (deposit <= 0)
        return ;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << std::flush;
    std::cout << "p_amount:" << _amount << ";" << std::flush;
    _amount += deposit;
    _nbDeposits += 1;
    std::cout << "deposit:" << deposit << ";" << std::flush;
    std::cout << "amount:" << _amount << ";" << std::flush;
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << std::flush;
    std::cout << "p_amount:" << _amount << ";" << std::flush;
    if (withdrawal < 0 || withdrawal > checkAmount())
    {
        std::cout << "withdrawal:" << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    _totalAmount -=withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";" << std::flush;
    std::cout << "amount:" << _amount << ";" << std::flush;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << std::flush;
    std::cout << "amount:" << _amount << ";" << std::flush;
    std::cout << "deposits:" << _nbDeposits << ";" << std::flush;
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

    std::cout << "["
              << (ltm->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (ltm->tm_mon + 1)
              << std::setw(2) << ltm->tm_mday
              << "_"
              << std::setw(2) << ltm->tm_hour
              << std::setw(2) << ltm->tm_min
              << std::setw(2) << ltm->tm_sec
              << "] ";
}



int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}


void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";" << std::flush;
    std::cout << "total:" << Account::getTotalAmount() << ";" << std::flush;
    std::cout << "deposits:" << Account::getNbDeposits() << ";" << std::flush;
    std::cout << "withdrawals:" << Account::getNbWithdrawals()  << std::endl;
}
