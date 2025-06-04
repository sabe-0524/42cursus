/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:53:27 by sabe              #+#    #+#             */
/*   Updated: 2025/06/04 19:27:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>

void add_book(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name?: ";
	std::cin >> first_name;
	std::cout << "Last name?: ";
	std::cin >> last_name;
	std::cout << "Nickname?: ";
	std::cin >> nickname;
	std::cout << "Phone number?: ";
	std::cin >> phone_number;
	std::cout << "Darkest secret?: ";
	std::cin >> darkest_secret;
	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	phonebook.setPhoneBook(first_name, last_name, nickname, phone_number, darkest_secret);
}

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
		std::cin >> input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			add_book(phonebook);
		else if (input == "SEARCH")
			search_book();
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (0);
}
