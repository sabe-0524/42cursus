/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:46 by sabe              #+#    #+#             */
/*   Updated: 2025/07/20 14:04:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels[4] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

Harl::Harl(void)
{
}

void Harl::exec(std::string level)
{
	int i = 0;
	while (i < 4)
	{
		if (level == this->levels[i])
			break;
		i++;
	}
	switch (i)
	{
		case (DEBUG):
			this->debug();
			// fall through
		case (INFO):
			this->info();
			// fall through
		case (WARNING):
			this->warning();
			// fall through
		case (ERROR):
			this->error();
			break;
		default:
			std::cout << "Invalid Input" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]: ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]: ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]: ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]: ";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
