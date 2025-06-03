/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:54:06 by sabe              #+#    #+#             */
/*   Updated: 2025/06/03 22:54:31 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		long unsigned int phone_number;
		std::string darkset_secret;
	public:
		void setFirstName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickName(std::string nick_name);
		void setPhoneNumber(long unsigned int phone_number);
		void setDarksetSecret(std::string darkset_secret);
};
