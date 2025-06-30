/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:58:17 by sabe              #+#    #+#             */
/*   Updated: 2025/06/30 18:31:37 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("unknown")
{
	std::cout << "FragTrap" << " default constructor called." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap" << " string constructor called." << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap" <<  " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap" << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap" << " assignment operator called" << std::endl;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap" << " " << this->name << " requests a high five!" << std::endl;
}
