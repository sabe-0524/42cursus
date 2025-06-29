/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:53:27 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 15:42:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
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
		std::getline(std::cin, input);
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
