/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:07:33 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 19:31:20 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool isPrintable(const std::string& s)
{
    if (s.empty())
		return (false);
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        unsigned char c = static_cast<unsigned char>(*it);
        if (!std::isprint(c)) return false;
    }
    return (true);
}


bool isNumber(const std::string& s)
{
    if (s.empty())
		return (false);
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        unsigned char c = static_cast<unsigned char>(*it);
        if (!std::isdigit(c)) return false;
    }
    return (true);
}

bool isAlphabet(const std::string& s)
{
    if (s.empty())
		return (false);
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        unsigned char c = static_cast<unsigned char>(*it);
        if (!std::isalpha(c) && c != ' ') return false;
    }
    return (true);
}

bool isAlnum(const std::string& s)
{
    if (s.empty())
		return (false);
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        unsigned char c = static_cast<unsigned char>(*it);
        if (!std::isalnum(c) && c != ' ') return false;
    }
    return (true);
}

void PhoneBook::setPhoneBook(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phone_number, std::string &darkest_secret)
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

Contact PhoneBook::getContact(int index)
{
	return (this->contacts[index]);
}

size_t PhoneBook::getCount(void)
{
	return (this->count);
}

void PhoneBook::my_getline(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "EOF" << std::endl;
		exit(0);
	}
}

void PhoneBook::addBook(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name?: ";
	this->my_getline(first_name);
	if (!isAlphabet(first_name))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cout << "Last name?: ";
	this->my_getline(last_name);
	if (!isAlphabet(last_name))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cout << "Nickname?: ";
	this->my_getline(nickname);
	if (!isAlnum(nickname))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cout << "Phone number?: ";
	this->my_getline(phone_number);
	if (!isNumber(phone_number))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cout << "Darkest secret?: ";
	this->my_getline(darkest_secret);
	if (!isPrintable(darkest_secret))
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
  this->my_getline(input);
  if (input.length() != 1 || (!isdigit(input[0]) || input[0] > '7'))
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
}
