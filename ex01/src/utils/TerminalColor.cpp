/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 02:24:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/29 02:25:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalColor.hpp"
#include <string>
#include <utility>

TerminalColor::TerminalColor() {}
TerminalColor::~TerminalColor() {}

TerminalColor& TerminalColor::getInstance() {
  static TerminalColor instance;
  return instance;
}

const std::pair<ColorCode, std::string> TerminalColor::COLOR_MAP[] = {
  std::make_pair(RED, "\033[31m"),
  std::make_pair(GREEN, "\033[32m"),
  std::make_pair(YELLOW, "\033[33m"),
  std::make_pair(BLUE, "\033[34m"),
  std::make_pair(WHITE, "\033[37m"),
  std::make_pair(RESET, "\033[0m")
};

std::string TerminalColor::setColor(ColorCode color, const std::string& str) const {
  return COLOR_MAP[color].second + str + COLOR_MAP[RESET].second;
}
