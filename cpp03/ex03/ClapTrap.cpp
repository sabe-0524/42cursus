/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:33:21 by sabe              #+#    #+#             */
/*   Updated: 2025/06/29 22:41:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unknown"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap" << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap" << " string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const unsigned int &hitPoints, const unsigned int &energyPoints, const unsigned int &attackDamage) : name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
	std::cout << "ClapTrap" << " full constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap" <<" Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap" << " Copy assignment operator called" << std::endl;
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
	std::cout << "ClapTrap" << " Destructor called" << std::endl;
}

void ClapTrap::setName(const std::string &name)
{
	this->name = name;
}

void ClapTrap::setHitPoints(const unsigned int &hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(const unsigned int &energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(const unsigned int &attackDamage)
{
	this->attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		std::cout << "ClapTrap" << " " << this->name << " can't attack." << std::endl;
	else
	{
		std::cout << "ClapTrap" << " " << this->name << " attacks " << target << " , causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap" << " " << this->name << " has already died." << std::endl;
		return;
	}
	std::cout << "ClapTrap" << " " << this->name << " is taken " << amount << " damage." << std::endl;
	if (this->hitPoints < amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
		std::cout << "ClapTrap" << " " << this->name << " can't be repaired." << std::endl;
	else
	{
		std::cout << "ClapTrap" << " " << this->name << " is repaired " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}

std::string ClapTrap::getName(void)
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}

unsigned int ClapTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}


