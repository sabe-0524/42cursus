/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:58:24 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 21:56:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor called." << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment operator called." << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}
