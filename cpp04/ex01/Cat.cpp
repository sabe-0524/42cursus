/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:01:49 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:35:39 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "miaaaaaaaaoooo" << std::endl;
}

std::string Cat::getIdea(int nbr) const
{
	return (this->brain->getIdeas()[nbr]);
}

void Cat::setIdea(int nbr, std::string idea)
{
	this->brain->setIdea(nbr, idea);
}

