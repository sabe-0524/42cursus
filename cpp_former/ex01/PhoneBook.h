/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:44 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 14:57:04 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iostream>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact contacts[8];
		size_t count;
		void my_getline(std::string &str);
		size_t getCount(void);
		Contact getContact(int index);
		void setPhoneBook(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
	public:
		PhoneBook() : contacts(), count(0) {}
		void addBook(void);
		void searchBook(void);
};

#endif
