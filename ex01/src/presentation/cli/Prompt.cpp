/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:36:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/07 22:55:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/PhoneBook.hpp"
#include "infrastructure/storage/Contact.hpp"
#include "presentation/cli/Prompt.hpp"
#include "utils/Default.hpp"
#include "utils/TerminalColor.hpp"
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

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

bool Prompt::getLine() {
  std::clearerr(stdin);
  std::cin.clear();
  std::getline(std::cin, m_input);
  if (std::cin.eof()) {
    std::cout << std::endl;
  }
  if (m_input.empty()) {
    return false;
  }
  return true;
}

void Prompt::run() {
	std::signal(SIGINT, SIG_IGN);
  while (true) {
    std::cout << "Enter command ("
              << m_color.setColor(GREEN, "ADD")
              << ", " << m_color.setColor(BLUE, "SEARCH")
              << ", " + m_color.setColor(ORANGE, "EXIT") + "): ";
    if (!getLine()) {
      continue;
    } else if (m_input == "ADD") {
      getInput();
    } else if (m_input == "SEARCH") {
      displayContacts();
    } else if (m_input == "EXIT") {
      std::cout << m_color.setColor(ORANGE, "Exit phonebook") << std::endl;
      break;
    } else {
      std::cout << m_color.setColor(RED, "Invalid command") << std::endl;
    }
  }
}

void Prompt::getInput() {
  Contact contact;

  for (int i = FIRST_NAME; i < TOTAL_FIELDS; i++) {
    const Field& field = PhoneBook::fields[i];

    while (true) {
      std::cout << "Enter " << field.strField << ": ";
      if (!getLine()) {
        continue;
      }
      if (m_phonebook.validateField(m_input, field.minChr, field.validade)) {
        contact.set(field.id, m_input);
        break;
      } else {
        std::cout << m_color.setColor(RED, field.errorMsg) << std::endl;
      }
    }
  }
  m_phonebook.addContact(contact);
  std::cout << m_color.setColor(GREEN, "New contact added") << std::endl;
}

void Prompt::displayContacts() {
  if (!m_phonebook.getContacts()) {
    std::cout << m_color.setColor(RED, "Phone book has 0 contacts") << std::endl;
  } else {
    while (true) {
      std::cout << m_color.setColor(BLUE, "Your contacts:") << std::endl;
      std::cout << std::setw(PADDING_RIGHT) << "Index" << m_color.setColor(BLUE, "|")
                << std::setw(PADDING_RIGHT) << "First Name" << m_color.setColor(BLUE, "|")
                << std::setw(PADDING_RIGHT) << "Last Name" << m_color.setColor(BLUE, "|")
                << std::setw(PADDING_RIGHT) << "Nickname" << m_color.setColor(BLUE, "|")
                << std::endl;
      for (int i = DEFAULT; i < m_phonebook.getContacts(); i++) {
        displayContact(i, true);
      }
      std::cout << "Choose one index to display: (1 to " << m_phonebook.getContacts() << "): ";
      if (!getLine()) {
        continue;
      }
      int index = std::atoi(m_input.c_str());
      if (!(index < CONTACT || index > m_phonebook.getContacts())) {
        displayContact(--index, false);
        break;
      } else {
        std::cout << m_color.setColor(RED, "Invalid index") << std::endl;
      }
    }
  }
}

void Prompt::displayContact(int i, bool formated) {
  if (formated) {
    std::cout << std::setw(PADDING_RIGHT) << i + CONTACT
              << m_color.setColor(BLUE, "|") << std::setw(PADDING_RIGHT)
              << m_phonebook.getContactInfo(i, FIRST_NAME, formated)
              << m_color.setColor(BLUE, "|") << std::setw(PADDING_RIGHT)
              << m_phonebook.getContactInfo(i, LAST_NAME, formated)
              << m_color.setColor(BLUE, "|") << std::setw(PADDING_RIGHT)
              << m_phonebook.getContactInfo(i, NICKNAME, formated)
              << m_color.setColor(BLUE, "|") << std::endl;
  } else {
    std::cout << m_color.setColor(BLUE, "First name: ")
              << m_phonebook.getContactInfo(i, FIRST_NAME, formated) << std::endl
              << m_color.setColor(BLUE, "Last name: ")
              << m_phonebook.getContactInfo(i, LAST_NAME, formated) << std::endl
              << m_color.setColor(BLUE, "Nickname: ")
              << m_phonebook.getContactInfo(i, NICKNAME, formated) << std::endl
              << m_color.setColor(BLUE, "Phone number: ")
              << m_phonebook.getContactInfo(i, PHONE_NUMBER, formated) << std::endl
              << m_color.setColor(BLUE, "Darkest secret: ")
              << m_phonebook.getContactInfo(i, DARKEST_SECRET, formated) << std::endl;
  }
}
