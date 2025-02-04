/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:59:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/04 01:08:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
    << "amount:" << checkAmount() << ";"
    << "created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
    << "amount:" << _amount << ";"
    << "closed" << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t now = std::time(0);
  std::tm* local = std::localtime(&now);
  char buf[20];
  std::strftime(buf, 20, "%Y%m%d_%H%M%S", local);
  std::cout << "[" << buf << "] ";
}

int Account::getNbAccounts() {
  return _nbAccounts;
}

int Account::getTotalAmount() {
  return _totalAmount;
}

int Account::getNbDeposits() {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";"
    << "total:" << _totalAmount << ";"
    << "deposits:" << _totalNbDeposits << ";"
    << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
    << "p_amount:" << checkAmount() << ";"
    << "deposit:" << deposit << ";";
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "amount:" << checkAmount() << ";"
    "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
    << "p_amount:" << checkAmount() << ";"
    << "withdrawal:";
  if (withdrawal > checkAmount()) {
    std::cout << "refused" << std::endl;
    return false;
  }
  std::cout << withdrawal << ";";
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << "amount:" << checkAmount() << ";"
    << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount() const {
  return _amount;
}

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
    << "amount:" << checkAmount() << ";"
    << "deposits:" << _nbDeposits << ";"
    << "withdrawals:" << _nbWithdrawals << std::endl;
}
