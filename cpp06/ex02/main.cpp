/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/01/30 01:46:53 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base* p = generate();

	std::cout << "identify(Base*): ";
	identify(p);

	std::cout << "identify(Base&): ";
	identify(*p);

	delete p;
	return 0;
}
