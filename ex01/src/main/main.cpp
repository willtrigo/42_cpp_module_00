/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/01/30 01:16:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presentation/cli/Prompt.hpp"
#include <cstdlib>

int main() {
  Prompt prompt;

  prompt.run();
	return (EXIT_SUCCESS);
}
