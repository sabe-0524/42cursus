/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:54:07 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 15:42:36 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string input)
{
	this->first_name = input;
}

void Contact::setLastName(const std::string input)
{
	this->last_name = input;
}

void Contact::setNickName(const std::string input)
{
	this->nickname = input;
}

void Contact::setPhoneNumber(const std::string input)
{
	this->phone_number = input;
}

void Contact::setDarkestSecret(const std::string input)
{
	this->darkest_secret = input;
}

std::string Contact::getFirstName(void) const
{
	if (this->first_name.length() > 10)
		return (this->first_name.substr(0, 9) + ".");
	else
		return (this->first_name);
}

std::string Contact::getLastName(void) const
{
	if (this->last_name.length() > 10)
		return (this->last_name.substr(0, 9) + ".");
	else
		return (this->last_name);
}

std::string Contact::getNickName(void) const
{
	if (this->nickname.length() > 10)
		return (this->nickname.substr(0, 9) + ".");
	else
		return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	if (this->phone_number.length() > 10)
		return (this->phone_number.substr(0, 9) + ".");
	else
		return (this->phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	if (this->darkest_secret.length() > 10)
		return (this->darkest_secret.substr(0, 9) + ".");
	else
		return (this->darkest_secret);
}

void Contact::printContact(void) const
{
	std::cout << std::right;
	std::cout << std::setw(10) << this->getFirstName() << "|";
	std::cout << std::setw(10) << this->getLastName() << "|";
	std::cout << std::setw(10) << this->getNickName() << "|";
	std::cout << std::setw(10) << this->getPhoneNumber() << "|";
	std::cout << std::setw(10) << this->getDarkestSecret() << std::endl;
}
