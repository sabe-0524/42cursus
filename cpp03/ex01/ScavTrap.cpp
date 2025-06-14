/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:12:08 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 17:20:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("unknown", 100, 50, 20)
{
	std::cout << this->getClassName() << " default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << this->getClassName() << " string constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->getClassName() <<  " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << this->getClassName() << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << this->getClassName() << " assignment operator called" << std::endl;
    }
    return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << getClassName() << " is now in Gate keeper mode." << std::endl;
}
