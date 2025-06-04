/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:52:44 by sabe              #+#    #+#             */
/*   Updated: 2025/06/04 19:22:18 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

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
};

#endif
