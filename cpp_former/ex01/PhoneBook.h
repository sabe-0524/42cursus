/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:44 by sabe              #+#    #+#             */
/*   Updated: 2025/06/07 17:10:12 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
		size_t count;
	public:
		PhoneBook() : contacts(), count(0) {}
		void setPhoneBook(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		Contact *getPhoneBook(void);
		Contact getContact(int index);
		size_t getCount(void);
    void addBook(void);
    void searchBook(void);
};

#endif
