/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:10 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 21:53:46 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "AMateria constructor called." << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.getType())
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assigned constructor called." << std::endl;
	if (this != &other)
	{
		this->type = other.getType();
	}
	return (*this);
}

std::string const& AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << std::endl;
}
