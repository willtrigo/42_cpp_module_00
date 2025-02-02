/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 02:24:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/02/02 02:28:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalColor.hpp"
#include <stdexcept>
#include <string>
#include <utility>

TerminalColor::TerminalColor() {}
TerminalColor::~TerminalColor() {}

TerminalColor& TerminalColor::getInstance() {
  static TerminalColor instance;
  return instance;
}

TerminalColor::TerminalColor(const TerminalColor&) {
  throw std::runtime_error("Copying of TerminalColor is not allowed");
}

TerminalColor& TerminalColor::operator=(const TerminalColor&) {
  throw std::runtime_error("Copy assignment of TerminalColor is not allowed");
  return *this;
}

const std::pair<ColorCode, std::string> TerminalColor::COLOR_MAP[] = {
  std::make_pair(RED, "\033[31m"),
  std::make_pair(GREEN, "\033[32m"),
  std::make_pair(YELLOW, "\033[33m"),
  std::make_pair(BLUE, "\033[34m"),
  std::make_pair(WHITE, "\033[37m"),
  std::make_pair(ORANGE, "\x1B[38;5;202m"),
  std::make_pair(RESET, "\033[0m")
};

std::string TerminalColor::setColor(ColorCode color, const std::string& str) const {
  return COLOR_MAP[color].second + str + COLOR_MAP[RESET].second;
}
