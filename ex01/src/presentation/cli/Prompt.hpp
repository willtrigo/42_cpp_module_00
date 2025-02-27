/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:53:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/27 16:27:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include "core/PhoneBook.hpp"
#include "utils/TerminalColor.hpp"
#include <string>

class Prompt {
 public:
  Prompt();
  Prompt(const Prompt&);
  Prompt& operator=(const Prompt&);
  ~Prompt();

  void run();

 private:
  PhoneBook m_phonebook;
  std::string m_input;
  const TerminalColor& m_color;

  bool getLine();
  void displayContacts();
  void displayContact(int i, bool formated);
  void getInput();
};

#endif // PROMPT_HPP
