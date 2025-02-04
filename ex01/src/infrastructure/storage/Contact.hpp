/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:32:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/04 18:27:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

enum Fields {
  FIRST_NAME,
  LAST_NAME,
  NICKNAME,
  PHONE_NUMBER,
  DARKEST_SECRET,
  TOTAL_FIELDS
};

class Contact {
public:
  Contact();
  Contact(const Contact& other);
  Contact& operator=(const Contact& other);
  ~Contact();

  void set(Fields field, const std::string& value);
  const std::string& get(Fields field) const;

private:
  std::string m_fields[TOTAL_FIELDS];
};

#endif // CONTACT_HPP
