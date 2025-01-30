/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:53:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/30 03:14:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include "core/Phonebook.hpp"
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
  const TerminalColor& m_color;
  std::string m_input;
};

#endif // PROMPT_HPP
