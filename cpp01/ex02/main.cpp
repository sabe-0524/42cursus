/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:02:23 by sabe              #+#    #+#             */
/*   Updated: 2025/06/08 19:13:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Normal address: " << &str << std::endl;
	std::cout << "Ptr address:    " << stringPTR << std::endl;
	std::cout << "Ref address:    " << &stringREF << std::endl;
	std::cout << "Normal value:   " << str << std::endl;
	std::cout << "Ptr valie:      " << *stringPTR << std::endl;
	std::cout << "Ref value:      " << stringREF << std::endl;
	return (0);
}
