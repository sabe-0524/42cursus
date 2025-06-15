/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:43:49 by sabe              #+#    #+#             */
/*   Updated: 2025/06/15 14:37:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "baaaarrrk" << std::endl;
}

std::string Dog::getIdea(int nbr) const
{
	return (this->brain->getIdeas()[nbr]);
}

void Dog::setIdea(int nbr, std::string idea)
{
	this->brain->setIdea(nbr, idea);
}
