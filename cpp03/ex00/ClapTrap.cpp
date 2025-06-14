/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:33:21 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 16:10:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " can't attack." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has already died." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " is taken " << amount << " damage." << std::endl;
	if (this->hitPoints < amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " can't be repaired." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " is repaired " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}
