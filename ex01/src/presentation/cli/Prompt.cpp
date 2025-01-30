/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:36:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/30 03:28:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presentation/cli/Prompt.hpp"
#include "utils/TerminalColor.hpp"
#include <csignal>
#include <cstdio>
#include <iostream>
#include <ostream>

Prompt::Prompt() : m_color(TerminalColor::getInstance()) {}

Prompt::Prompt(const Prompt& other) : m_color(TerminalColor::getInstance()) {
  *this = other;
}

Prompt& Prompt::operator=(const Prompt& other) {
  if (this != &other) {
    this->m_phonebook = other.m_phonebook;
  }
  return *this;
}

Prompt::~Prompt() {}

void Prompt::run() {
	std::signal(SIGINT, SIG_IGN);
  while (true) {
    std::cout << "Enter command (" + m_color.setColor(GREEN, "ADD") +
      ", " + m_color.setColor(YELLOW, "SEARCH") +
      ", " + m_color.setColor(RED, "EXIT") + "): ";
	  std::clearerr(stdin);
  	std::cin.clear();
    std::getline(std::cin, m_input);
    if (std::cin.eof()) {
      std::cout << std::endl;
   }
    if (m_input.empty()) {
      continue;
    } else if (m_input == "ADD") {

    } else if (m_input == "EXIT") {
      std::cout << "Exit phonebook" << std::endl;
      break;
    } else {
      std::cout << m_color.setColor(RED, "Invalid command") << std::endl << std::endl;
    }
  }
}
