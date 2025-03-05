/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:48:24 by dande-je          #+#    #+#             */
/*   Updated: 2025/03/05 11:42:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

static std::string megaphone(int argc, char* argv[]);

int main(int argc, char** argv) {
	std::cout << megaphone(--argc, ++argv) << std::endl;
	return EXIT_SUCCESS;
}

static std::string megaphone(int argc, char* argv[]) {
	std::string str;

	if (argc)
	{
		while (*argv)
		{
			char* chr = *argv;
			while (*chr)
				str += std::toupper(*chr++);
			argv++;
		}
	}
	else
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return str;
}
