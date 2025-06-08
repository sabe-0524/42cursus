/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:07:33 by sabe              #+#    #+#             */
/*   Updated: 2025/06/07 18:33:17 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

void PhoneBook::setPhoneBook(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	Contact contact;

	contact.setFirstName(first_name);
	contact.setLastName(last_name);
	contact.setNickName(nickname);
	contact.setPhoneNumber(phone_number);
	contact.setDarkestSecret(darkest_secret);

	this->contacts[count % 8] = contact;
	this->count++;
}

Contact *PhoneBook::getPhoneBook(void)
{
	return (this->contacts);
}

Contact PhoneBook::getContact(int index)
{
	return (this->contacts[index]);
}

size_t PhoneBook::getCount(void)
{
	return (this->count);
}

void PhoneBook::addBook(void)
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
	this->setPhoneBook(first_name, last_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::searchBook(void)
{
  std::string input;
  size_t index;

  std::cout << "Please tell me index: ";
  std::getline(std::cin, input);
  if (std::cin.eof())
  {
    std::cout << "EOF" << std::endl;
    exit(0);
  }
  if (input.length() != 1 || (!isdigit(input[0] || input[0] > '7')))
  {
    std::cout << "Invalid input" << std::endl;
    return;
  }
  index = static_cast<size_t>(input[0] - '0');
  if (index >= this->getCount())
  {
    std::cout << "Index out of range" << std::endl;
    return;
  }
  Contact contact = this->getContact(index);
  contact.printContact();
  input.clear();
}