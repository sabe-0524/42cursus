/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:09:47 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 22:06:13 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called." << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called." << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
