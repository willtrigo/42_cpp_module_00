/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:53:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/02 04:46:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include "core/PhoneBook.hpp"
#include "utils/TerminalColor.hpp"

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
  void getInput();
};

#endif // PROMPT_HPP
