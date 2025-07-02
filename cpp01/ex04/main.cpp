/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:09:26 by sabe              #+#    #+#             */
/*   Updated: 2025/07/01 16:26:03 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid Input" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "File Error" << std::endl;
		return (1);
	}
	std::string text;
	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "File Error" << std::endl;
		return (1);
	}
	std::string s1(argv[2]);
	std::string::size_type found = 0;
	std::string::size_type pos = 0;
	while (std::getline(infile, text))
	{
		pos = 0;
		while ((found = text.find(s1, pos)) != std::string::npos)
		{
			text.erase(found, s1.length());
			text.insert(found, argv[3]);
			pos = found + std::string(argv[3]).length();
		}
		outfile << text << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
