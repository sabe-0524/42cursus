/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:50:04 by sabe              #+#    #+#             */
/*   Updated: 2025/06/14 20:37:13 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("unknown_clap_name"), ScavTrap("unknown"), FragTrap("unknown"), name("unknown")
{
	std::cout << this->getClassName() << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	std::cout << this->getClassName() << " name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << this->getClassName() <<  " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
  , ScavTrap(other)
  , FragTrap(other)
  , name(other.name)
{
    std::cout << this->getClassName() << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << this->getClassName() << " assignment operator called" << std::endl;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout
      << "DiamondTrap name: " << this->name
      << ", ClapTrap name: " << ClapTrap::getName()
      << std::endl;
}
