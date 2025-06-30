/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:50:04 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 20:18:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("unknown"), ScavTrap("unknown"), FragTrap("unknown"), name("unknown")
{
	std::cout << "DiamondTrap" << " default constructor called" << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->name = "unknown";
    ClapTrap::name = "unknown_clap_name";
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << "DiamondTrap" << " name constructor called" << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->name = name;
    ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap" <<  " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
  , ScavTrap(other)
  , FragTrap(other)
  , name(other.name)
{
    std::cout << "DiamondTrap" << " copy constructor called" << std::endl;
    this->attackDamage = FragTrap::attackDamage;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    ClapTrap::name = this->name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->hitPoints = other.hitPoints;
        std::cout << "DiamondTrap" << " assignment operator called" << std::endl;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout
      << "DiamondTrap name: " << this->name
      << ", ClapTrap name: " << ClapTrap::name
      << std::endl;
}
