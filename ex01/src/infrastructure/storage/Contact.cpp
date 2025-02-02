/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:37:31 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/01 04:27:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/storage/Contact.hpp"
#include "utils/Default.hpp"
#include <string>
#include <stdexcept>

Contact::Contact() {}

Contact::Contact(const Contact& other) {
  *this = other;
}

Contact& Contact::operator=(const Contact& other) {
  if (this != &other) {
    for (int i = DEFAULT; i < TOTAL_FIELDS; i++) {
      m_fields[i] = other.m_fields[i];
    }
  }
  return *this;
}

Contact::~Contact() {}

void Contact::set(Fields field, const std::string& value) {
  if (field >= FIRST_NAME && field <= DARKEST_SECRET) {
    m_fields[field] = value;
  } else {
    throw std::out_of_range("Invalid field");
  }
}

const std::string& Contact::get(Fields field) const {
  if (field >= FIRST_NAME && field <= DARKEST_SECRET) {
    return m_fields[field];
  }
  throw std::out_of_range("Invalid field");
}
