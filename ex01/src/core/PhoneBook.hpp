/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:33:29 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/02 04:34:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "infrastructure/storage/Contact.hpp"

enum PhoneBookEnum {
  CONTACT = 1,
  TOTAL_CONTACTS = 8
};

struct Field {
  Fields id;
  std::string strField;
  std::string errorMsg;
  int minChr;
  int (*validade)(int);
};

class PhoneBook {
 public:
  PhoneBook();
  PhoneBook(const PhoneBook& other);
  PhoneBook& operator=(const PhoneBook& other);
  ~PhoneBook();

  static const Field fields[TOTAL_FIELDS];
  void addContact(const Contact& contact);
  bool validateField(std::string str, int minChr, int(*validade)(int));
  int getContacts();

 private:
  Contact m_contacts[TOTAL_CONTACTS];
  int m_contactIndex;
};

#endif
