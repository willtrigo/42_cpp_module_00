/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:24 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/07 22:20:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>

static std::string megaphone(int argc, char* argv[]);
static std::string toUpper(const std::string& str);

int main(int argc, char* argv[]) {
	std::cout << megaphone(--argc, ++argv) << std::endl;
	return EXIT_SUCCESS;
}

static std::string toUpper(const std::string& str) {
  std::string new_str(str);

  for (size_t i = 0; i < new_str.length(); ++i) {
    new_str.at(i) = std::toupper(new_str.at(i));
  }
  return new_str;
}

static std::string megaphone(int argc, char* argv[]) {
	std::string str;

	if (argc) {
		while (*argv) {
      str += toUpper(static_cast<std::string>(*argv++));
		}
	} else {
    str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  }
	return str;
}
