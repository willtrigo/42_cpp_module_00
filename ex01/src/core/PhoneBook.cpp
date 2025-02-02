/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:05:02 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/02 05:02:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/PhoneBook.hpp"
#include "infrastructure/storage/Contact.hpp"
#include "utils/Default.hpp"
#include <cctype>
#include <cstddef>

const Field PhoneBook::fields[TOTAL_FIELDS] = {
  {FIRST_NAME, "first name", "first name only accept characters and must be at least 3 characters.", 3, std::isalpha},
{LAST_NAME, "last name", "last name only accept characters and must be at least 3 characters.", 3, std::isalpha},
  {NICKNAME, "nickname", "nickname must be at least 3 characters.", 3, std::isprint},
  {PHONE_NUMBER, "phone number", "phone number must be at least 8 digits.", 8, std::isdigit},
  {DARKEST_SECRET, "darkest secret", "darkest secret must be at least 5 characters.", 5, std::isprint},
};

PhoneBook::PhoneBook() : m_contactIndex(DEFAULT) {}

PhoneBook::PhoneBook(const PhoneBook& other) {
  *this = other;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
  if (this != &other) {
    for (int i = DEFAULT; i < TOTAL_CONTACTS; i++) {
      this->m_contacts[i] = other.m_contacts[i]; 
    }
    this->m_contactIndex = other.m_contactIndex;
  }
  return *this;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
  if (m_contactIndex < TOTAL_CONTACTS) {
    m_contacts[m_contactIndex++] = contact;
  } else {
    for (int i = DEFAULT; i < TOTAL_CONTACTS - CONTACT; i++) {
      m_contacts[i] = m_contacts[i + CONTACT];
    }
    m_contacts[TOTAL_CONTACTS - CONTACT] = contact;
  }
}

int PhoneBook::getContacts() {
  return m_contactIndex;
}

bool PhoneBook::validateField(std::string str, int minChr, int(*validade)(int)) {
  if (str.length() < static_cast<size_t>(minChr))
    return false;
  for (size_t i = DEFAULT; i < str.length(); i++) {
    if (!validade(str.at(i))) {
      return false;
    }
  }
  return true;
}
