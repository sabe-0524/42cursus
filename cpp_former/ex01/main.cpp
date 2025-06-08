/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:53:27 by sabe              #+#    #+#             */
/*   Updated: 2025/06/07 18:47:06 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>

void search_book(void)
{
	
}

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Input command: ";
		// std::getline(std::cin, input);
    std::cin >> input;
    if (std::cin.eof())
    {
      std::cout << "EOF" << std::endl;
      exit(0);
    }
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phonebook.addBook();
		else if (input == "SEARCH")
			phonebook.searchBook();
		else
			std::cout << "Invalid input" << std::endl;
    input.clear();
	}
	return (0);
}
