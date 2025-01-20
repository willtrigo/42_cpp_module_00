/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 04:50:20 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/20 02:32:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_COLOR_HPP
#define TERMINAL_COLOR_HPP

#include <string>

class TerminalColor {
public:
  static TerminalColor& getInstance();

  std::string red(const std::string& str) const;
  std::string green(const std::string& str) const;
  std::string yellow(const std::string& str) const;
  std::string blue(const std::string& str) const;
  std::string white(const std::string& str) const;

  const std::string& reset() const;
private:
  TerminalColor();
  ~TerminalColor();

  std::string setColor(const std::string& color, const std::string& str) const;

  static const std::string RESET;
  static const std::string RED;
  static const std::string GREEN;
  static const std::string YELLOW;
  static const std::string BLUE;
  static const std::string WHITE;
};

#endif
