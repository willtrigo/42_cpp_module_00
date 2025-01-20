/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 02:24:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/20 02:37:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalColor.hpp"
#include <string>

const std::string TerminalColor::RESET = "\033[0m";
const std::string TerminalColor::RED = "\033[1;31m";
const std::string TerminalColor::GREEN = "\033[1;32m";
const std::string TerminalColor::YELLOW = "\033[1;33m";
const std::string TerminalColor::BLUE = "\033[1;34m";
const std::string TerminalColor::WHITE = "\033[1;37m";

TerminalColor& TerminalColor::getInstance() {
  static TerminalColor instance;
  return instance;
}

TerminalColor::TerminalColor() {}
TerminalColor::~TerminalColor() {}

std::string TerminalColor::setColor(const std::string& color, const std::string& str) const {
  return color + str + RESET;
}

std::string TerminalColor::red(const std::string& str) const {
  return setColor(RED, str);
}

std::string TerminalColor::green(const std::string& str) const {
  return setColor(GREEN, str);
}

std::string TerminalColor::yellow(const std::string& str) const {
  return setColor(YELLOW, str);
}

std::string TerminalColor::blue(const std::string& str) const {
  return setColor(BLUE, str);
}

std::string TerminalColor::white(const std::string& str) const {
  return setColor(WHITE, str);
}

const std::string& TerminalColor::reset() const {
  return RESET;
}
