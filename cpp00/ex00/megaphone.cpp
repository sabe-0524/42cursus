/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:10:54 by sabe              #+#    #+#             */
/*   Updated: 2025/06/03 21:32:27 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < argc; i++)
	{
		std::string s(argv[i]);
		for (size_t j = 0; j < s.size(); j++)
		{
			if (std::islower(static_cast<unsigned char>(s[j])))
			{
				s[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
			}
		}
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
