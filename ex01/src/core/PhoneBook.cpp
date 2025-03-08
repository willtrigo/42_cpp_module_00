/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:05:02 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/07 22:32:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/PhoneBook.hpp"
#include "infrastructure/storage/Contact.hpp"
#include "utils/Default.hpp"
#include <cctype>
#include <cstddef>

const Field PhoneBook::fields[TOTAL_FIELDS] = {
  {FIRST_NAME, "first name", "field first name only accept letters and must be at least 3 letters", 3, std::isalpha},
{LAST_NAME, "last name", "field last name only accept letters and must be at least 3 letters", 3, std::isalpha},
  {NICKNAME, "nickname", "field nickname must be at least 3 characters", 3, std::isprint},
  {PHONE_NUMBER, "phone number", "field phone number must be at least 8 digits", 8, std::isdigit},
  {DARKEST_SECRET, "darkest secret", "field darkest secret must be at least 5 characters", 5, std::isprint},
};

PhoneBook::PhoneBook() : m_contactIndex(DEFAULT) {}

PhoneBook::PhoneBook(const PhoneBook& other) {
  *this = other;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
  if (this != &other) {
    for (int i = DEFAULT; i < TOTAL_CONTACTS; ++i) {
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
    for (int i = DEFAULT; i < TOTAL_CONTACTS - CONTACT; ++i) {
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
  for (size_t i = DEFAULT; i < str.length(); ++i) {
    if (!validade(str.at(i))) {
      return false;
    }
  }
  return true;
}

std::string PhoneBook::getContactInfo(int id, Fields field, bool formated) {
  if (formated) {
    std::string str_temp = m_contacts[id].get(field);

    if (str_temp.length() >= PADDING_RIGHT)
      return str_temp.substr(DEFAULT, FORMATER_SIZE) + ".";
  }
  return m_contacts[id].get(field);
}
