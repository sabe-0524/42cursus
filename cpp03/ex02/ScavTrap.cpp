/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:12:08 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 18:31:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("unknown")
{
	std::cout << "ScavTrap" << " default constructor called." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap" << " string constructor called." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap" <<  " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap" << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap" << " assignment operator called" << std::endl;
    }
    return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap" << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout
      << "ScavTrap " << this->name
      << " attacks " << target
      << ", causing " << this->attackDamage
      << " points of damage!"
      << std::endl;
}
