/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:54:07 by sabe              #+#    #+#             */
/*   Updated: 2025/06/07 18:22:37 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

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
	return (this->first_name);
}

std::string Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string Contact::getNickName(void) const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

void Contact::printContact(void) const
{
  std::cout << "First Name: " << this->first_name << std::endl;
  std::cout << "Last Name: " << this->last_name << std::endl;
  std::cout << "Nickname: " << this->nickname << std::endl;
  std::cout << "Phone Number: " << this->phone_number << std::endl;
  std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}