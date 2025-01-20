/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/20 02:57:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "utils/TerminalColor.hpp"

int main(void)
{
  const TerminalColor& color = TerminalColor::getInstance();

  std::cout << color.red("works!!") << std::endl;
	return (EXIT_SUCCESS);
}
