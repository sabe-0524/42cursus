/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:07:33 by sabe              #+#    #+#             */
/*   Updated: 2025/06/04 19:26:18 by sabe             ###   ########.fr       */
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
